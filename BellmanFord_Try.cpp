#include<bits/stdc++.h>
using namespace std;
unordered_set<int> negcyc;
vector<int> v;
#define inf 1e9

class graph
{
	public:
		map< pair<int, int> , int> m;     //map of edge and its weight

		void addEdge(int u, int v, int w)
		{
			m[make_pair(u, v)] = w;
		}

		int bellman(int n, int src, int t)
		{
			map<int, int> dist;   //map of node and dist
			for(int i = 1; i <= n; i++)
			{
				dist[i] = inf;
			}
			dist[src] = 0;

			int nn = n;
			while(--n)
			{
				for(auto edge : m)
				{
					int u = edge.first.first, v = edge.first.second, w = edge.second;
					if(dist[u] == inf)
						continue;
					if(dist[u] + w < dist[v] && dist[u] != inf)
					{
						dist[v] = dist[u] + w;
					}
				}
			}
			n = nn;
			while(--n)
			for(auto edge : m)
                                {
                                        int u = edge.first.first, v = edge.first.second, w = edge.second;
					if(dist[u] == inf)
                                                continue;
                                        if(dist[u] + w < dist[v] && dist[u] != inf)
                                        {
						//negcyc.push_back(v);
						negcyc.insert(v);
						negcyc.insert(u);
				//		cout << u << " " << v << endl;
                                                dist[v] = dist[u] + w;
                                        }
                                }

		for(int i = 1; i <= nn; i++)
		{
			if(negcyc.count(i))
			{
				//v.push_back(-2);
				cout << '-' << endl;
			}
			else if(dist[i] == inf)
			{
				//v.push_back(-1);
				cout << '*' << endl;
			}
			else
			{
				//v.push_back(dist[i]);
				cout << dist[i] << endl;
			}
		}
			return dist[t];
		}

};

int main()
{
	int n, m;
	graph g;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}
	int src, t;
	cin >> src >> t;
	int res = g.bellman(n, src, t);
//	cout << (res >= inf - 1000 ? -1 : res) << endl;
/*
	for(int i = 0; i < n; i++)
	{
		if(v[i] == -2)
			cout << '-' << endl;
		else if(v[i] == -1)
			cout << '*' << endl;
		else
			cout << v[i] << endl;
	}
	*/
}
