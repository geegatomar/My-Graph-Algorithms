#include<bits/stdc++.h>
using namespace std;
int vis[100];
vector<vector<int>> g;
map<int, int> distmp;
map<int, int> finaldist;
map<pair<int,int>, int> weights;

bool compareSecond(pair<int, int> i, pair<int, int> j)
{
	return i.second < j.second;
}

void dijkstra()
{
	while(!distmp.empty())
	{
	auto mindist = min_element(distmp.begin(), distmp.end(), compareSecond);

	int v = mindist->first;
	cout << v << " " << mindist->second << endl;
	for(auto j: g[v])
	{
		if(distmp.find(j) != distmp.end())
		{
			if(distmp[j] > distmp[v] + weights[{v, j}]);
			{
				distmp[j] = distmp[v] + weights[{v, j}];
				cout << v << " " << j << " " << distmp[j] << endl;
			}
		}
	}
	finaldist[v] = mindist->second;
	distmp.erase(v);
	cout << "finalsize: " << finaldist.size() << " , tempsize:  " << distmp.size() << endl;
	}
}

int main()
{
	int n, m, i;
	cin >> n >> m;
	g.resize(n + 1);
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;
		g[u].push_back(v);

		pair<int, int> t = make_pair(u, v);
		weights[t] = w;

		g[v].push_back(u);
	}

	int s;
//	cout << "Enter source element: ";
	cin >> s;

	for(int i = 1; i <= n; i++)
	{
		if(i == s)
			distmp[i] = 0;
		else
			distmp[i] = INT_MAX;
	}

	dijkstra();

	for(auto it = finaldist.begin(); it != finaldist.end(); it++)
	{
		cout << it->first << " : " << it->second << endl;
	}
	
}
