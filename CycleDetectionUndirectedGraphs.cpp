#include<bits/stdc++.h>
using namespace std;
int vis[1000];
vector<vector<int>> g;
int par[1000];
int cycleDetected = 0;
set<int> s;

void dfs(int x)
{
	if(vis[x]) return;
	vis[x] = 1;
	s.insert(x);
	for(auto j: g[x])
	{

		if(vis[j] && j != par[x])
		{
			/*
			if( par[j] != x)
			{
				cout << "x: " << x << " , j: " << j << ",  j's parent :" << par[j] << endl;
				cycleDetected = 1;
			}*/

			//if(s.count(j))
			//{
				cycleDetected = 1;
			//}
		}
		else
		{
			par[j] = x;
			dfs(j);
		}
	}
	s.erase(x);
}

int main()
{

	int i, n, m;
	cin >> n >> m;
	g.resize(n+1);
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >>v;
		g[u].push_back(v);
		g[v].push_back(u);
	}

	for(int i = 1; i <= n; i++)
	{
		if(!vis[i]) dfs(i);
	}
	cout << cycleDetected << endl;
}
