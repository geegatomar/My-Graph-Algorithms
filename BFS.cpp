#include<bits/stdc++.h>
using namespace std;
int vis[100];
vector<vector<int>> g;
int lev[100];
deque<int> q;

void bfs(int node, int l)
{
	if(vis[node]) return;
	vis[node] = 1;
	lev[node] = l;

	q.push_back(node);
	while(!q.empty())
	{

	//	l++;
		
		for(auto j : g[node])
		{
			if(!vis[j])
			{
				
				vis[j] = 1;         //dont forget to mark it visited
			//	lev[j] = l;         // THIS IS WRONG WAY OF GIVING LEVEL
				lev[j] = lev[node] + 1;   //CORRECT WAY OF ASSIGNING LEVEL
				q.push_back(j);
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
	for(int i = 1; i <= n; i++)
	{
		cout << lev[i] << " ";	
	}
	cout << endl;


}
