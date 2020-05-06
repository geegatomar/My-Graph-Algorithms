#include<bits/stdc++.h>
using namespace std;
#define inf 1e9+1


int main()
{
	int n, m;
	cin >> n >> m;
	map< pair<int,int> , int> edge;
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		edge[make_pair(u, v)] = w;

	}
	int src;
	cin >> src;
	map<int, int> dist;
	for(int i = 1; i <= n; i++)
	{
		dist[i] = inf;
	}
	dist[src] = 0;

	int nv = 4*n - 1;
	while(nv--)
	{
		for(auto j : edge)
		{
			int u = j.first.first, v = j.first.second, w = j.second;
			if(dist[u] == inf)
				continue;
			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
			}
		}

	}
	nv = n;
	unordered_set<int> sn;    //set of neg edged vertices
	while(nv--)
	{
		for(auto j : edge)
                {
                        int u = j.first.first, v = j.first.second, w = j.second;
                        if(dist[u] == inf)
                                continue;
                        if(dist[u] + w < dist[v])
                        {

				sn.insert(u);
				sn.insert(v);
                                dist[v] = dist[u] + w;
                        }
                }

	}
	for(int i = 1; i <= n; i++)
	{
		if( sn.count(i))
		{
			cout << '-' << endl;
		}
		else if( dist[i] >= inf)
		{
			cout << '*' << endl;
		}
		else
			cout << dist[i] << endl;
	}
}
