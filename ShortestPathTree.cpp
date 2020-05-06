#include<bits/stdc++.h>
using namespace std;
int vis[100];
int lev[100];
int previ[100];     //contains the prev node, i.e. the node from which it was discovered
vector<vector<int>> g;
deque<int> q;

void bfs(int node, int l)
{
	if(vis[node]) return;
	vis[node] = 1;
	lev[node] = l;
	q.push_back(node);

	while(!q.empty())
	{
		l++;
		for(auto j : g[node])
		{
			if(!vis[j])
			{
				vis[j] = 1;
				q.push_back(j);
				lev[j] = l;
				previ[j] = node;
			}
		}

		q.pop_front();
		node = q.front();
	}
}

int main()
{
	int n, m, i;
	cin >> n >> m;
	g.resize(n + 1);
	for(int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		g[u].push_back(v);
	}

	for(int i = 1; i <= n; i++)
	{
		if(!vis[i])
			bfs(i, 1);
	}

	for(int i = 1; i <= n; i++) cout << lev[i] << " ";
	cout << endl;
	for(int i = 1; i <= n; i++) cout << previ[i] << " ";
	cout << endl;

	int x = 4;
	while(previ[x] != 0)
	{
		cout << x << " ";
		x = previ[x];
	}
	cout << endl;



}
