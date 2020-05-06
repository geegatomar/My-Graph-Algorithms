#include<bits/stdc++.h>
using namespace std;
int vis[100];
vector<vector<int>> g, gr;
stack<int> s;

void dfs(int x, vector<vector<int>> g)
{
	if(vis[x]) return;
	vis[x] = 1;
	for(auto j : g[x])
	{
		dfs(j, g);
	}
	s.push(x);     //push onto stack after visiting all its neighbours

}


int main()
{
	int n, m;
	cin >> n >> m;
	g.resize(n + 1);
	gr.resize(n+1);
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		gr[v].push_back(u);          //gr is the reverse(transpose) graph of g
	}
	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
			dfs(i, g);
	}



	memset(vis, 0, sizeof(vis));

	int compo = 0;
	while(!s.empty())
	{
		int x = s.top();
		if(!vis[x])
		{
			compo++;
			dfs(x, gr);
		}
		s.pop();
	}
	
	cout << compo << endl;
}
