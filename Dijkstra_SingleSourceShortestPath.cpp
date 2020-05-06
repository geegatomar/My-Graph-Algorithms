#include<bits/stdc++.h>
using namespace std;
int vis[100005];

class graph
{
	public:
		unordered_map<int, list<pair<int, int>> > m;

		void addEdge(int u, int v, int w)
		{
			m[u].push_back(make_pair(v, w));
		}

		int dijkstra(int n, int src, int t)
		{
			set<pair<int, int>> d;      // set of dist, node
			map<int, int> dist;      // map of node, dist

			for(int i = 1; i <= n; i++)
			{
				dist[i] = INT_MAX;
			}

			dist[src] = 0;
			d.insert(make_pair(0, src)); 

			while( !d.empty() )
			{
				auto p = d.begin();     //extracting smallest from this set
				int x = p->second, distx = p->first;
				//vis[x] = 1;
				for(auto neighborpair : m[x])
				{
					int neighbor = neighborpair.first, w = neighborpair.second;
					if( !vis[neighbor] )
					{
//						cout << "nodex :  " << x << ",  neighbor : " << neighbor << " " << distx << " " <<dist[neighbor] << " " << w  << endl;
						if( distx + w < dist[neighbor] )
						{
							if(d.find({dist[neighbor], neighbor}) != d.end())
							{
								d.erase({dist[neighbor], neighbor});
							}

							dist[neighbor] = distx + w;
							//if already present, first remove the old node
							
							d.insert(make_pair(dist[neighbor], neighbor));
						}
					}
				}				
				vis[x] = 1;
//				cout << "to erase : " << dist[x] << " " << x << endl;
				d.erase({dist[x], x});
			}
			return dist[t];
		}
};


int main()
{
	graph g;
	int n, m, i;
	cin >> n >> m;
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g.addEdge(u, v, w);
	}
	int src, t;
	cin >> src >> t;
	int res = g.dijkstra(n, src, t);
	cout << (res == INT_MAX ? -1 : res) << endl;
}
