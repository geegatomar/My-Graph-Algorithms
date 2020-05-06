#include<bits/stdc++.h>
using namespace std;
int vis[100];
vector<vector<int>> g;

void dfs(int node)
{
	if(vis[node]) return;
	cout << node << " ";
	vis[node] = 1;

	for(auto j : g[node])
	{
		dfs(j);
	}
}

int main()
{
	int n, m, i, j;
	cin >> n >> m;
	//vector<vector<int>> g(n+1);
	g.resize(n+1);
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	dfs(1);
	cout << endl;

}
