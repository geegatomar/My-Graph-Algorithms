#include<bits/stdc++.h>
using namespace std;
int vis[100];
vector<vector<int>> g;

void dfs(int node)
{
	if(vis[node]) return;
	vis[node] = 1;
	for(auto j: g[node])
	{
		dfs(j);
	}
}

int main()
{
	int n, m, i;
	cin >> n >> m;
	g.resize(n+1);
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	int comp = 0; //componenets
	for(i = 1; i <= n; i++)
	{
		if(!vis[i])
		{
			dfs(i);
			comp++;
		}
	}
	cout << comp << endl;
}
