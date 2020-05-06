#include<bits/stdc++.h>
using namespace std;
int vis[100];
vector<vector<int>> g;
stack<int> s;

void dfs(int node)
{
	
	if(vis[node]) return;
	int f = 0;
	vis[node] = 1;
	for(auto j: g[node])
	{
		if(!vis[j])
		{
			f = 1;
			dfs(j);
		}
	}

	s.push(node);
}

int main()
{
	int n, m, i;
	cin >> n >> m;
	g.resize(n + 1);
	for(int i = 0 ; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}
	for(int i = 1; i < n + 1; i++)
	{
		if(!vis[i])
		{
			dfs(i);
		}
	}

	while(!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;

}



/*
input
8 8
1 3
2 3
2 4
3 5
5 8
4 6
5 6
6 7
*/

