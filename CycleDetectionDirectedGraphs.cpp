#include<bits/stdc++.h>
using namespace std;
int vis[100];
vector<vector<int>> g;
set<int> s;
int cycleDetected = 0;

void dfs(int x)
{
	
	if(vis[x]) return;
	//cout << x << endl;
	vis[x] = 1;
	s.insert(x);
	
	for(auto j : g[x])
	{
		if(vis[j])
		{
			cout << "x: " <<x << ", j: " <<j << ",  " << s.count(j) << endl;
			if(s.count(j))
			{
				cycleDetected = 1;
				return;
			}
		}
		else
			dfs(j);
	}
	s.erase(x);
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

	}

	for(int i = 1; i <= n; i++)
	{
		if(!vis[i]) dfs(i);
	}
	cout << cycleDetected << endl;

}
