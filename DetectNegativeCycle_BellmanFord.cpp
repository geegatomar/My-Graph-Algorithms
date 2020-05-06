#include<bits/stdc++.h>
using namespace std;
set<int> negcyc;
vector<int> v;

class graph
{
        public:
                map< pair<int, int> , int> m;     //map of edge and its weight

                void addEdge(int u, int v, int w)
                {
                        m[make_pair(u, v)] = w;
                }

                int bellman(int n, int src)
                {
                        map<int, int> dist;   //map of node and dist
                        for(int i = 1; i <= n; i++)
                        {
                                dist[i] = INT_MAX - 1000;
                        }
                        dist[src] = 0;

                        int nn = n;
                        while(n--)
                        {
                                for(auto edge : m)
                                {
                                        int u = edge.first.first, v = edge.first.second, w = edge.second;
                                        if(dist[u] + w < dist[v])
                                        {
                                                dist[v] = dist[u] + w;
                                        }
                                }
                        }
                        n = nn;
                       
                        for(auto edge : m)
                                {
                                        int u = edge.first.first, v = edge.first.second, w = edge.second;
                                        if(dist[u] + w < dist[v])
                                        {
                                                //negcyc.push_back(v);
                                                negcyc.insert(v);
                                                dist[v] = dist[u] + w;
                                        }
                                }

/*		for(auto i : negcyc)
		{
			cout << i << " " ;
		}
		*/
		//cout << endl << negcyc.size() << endl;
		return negcyc.size();      
                }

};

int main()
{
        int n, m;
        graph g;
        cin >> n >> m;
	int mn = 0;
	set<int> nege;
        for(int i = 0; i < m; i++)
        {
                int u, v, w;
//		mn = min(mn, w);
                cin >> u >> v >> w;
		mn = min(mn, w);
		if(w < 0)
			nege.insert(u);
                g.addEdge(u, v, w);
        }
//        int src, t;
  //      cin >> src >> t;
    //    int res = g.bellman(n, src, t);
//      cout << (res >= INT_MAX - 1000 ? -1 : res) << endl;
	
	if(mn == 0)
		cout << 0;
	else
	{
	int flag = 0;

	for(auto it = nege.begin(); it != nege.end(); it++)
	{
		if(g.bellman(n, *it) != 0)
		{
			flag = 1;
			break;
		}
	}
        
	cout << flag ;
	}
}
