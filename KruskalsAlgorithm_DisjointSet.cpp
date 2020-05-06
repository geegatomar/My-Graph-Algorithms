#include<bits/stdc++.h>
using namespace std;
int parent[100000005];
int siz[100000005];

void make_set(int v)
{
	parent[v] = v;
	siz[v] = 1;
}

int find_set(int v)
{
	if(v == parent[v])
		return v;
	else
		return parent[v] = find_set(parent[v]);
}

int union_sets(int a, int b)
{
	a = find_set(a);
	b = find_set(b);
	if(a != b)
	{
		if(siz[a] < siz[b]) swap(a, b);
		parent[b] = a;
		siz[a] += siz[b];
	}
}

int main()
{
	map<int, pair<int, int>> pt;    //points;
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int x, y;
		cin >> x >> y;
		pt[i] = {x,y};
	}
	
	set< pair<long double, pair<int, int> >> s;   //to extract min from this
	for(int i = 1; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			int x1 = pt[i].first, y1 = pt[i].second, x2 = pt[j].first, y2 = pt[j].second;
			int x = abs(x1 - x2), y = abs(y1 - y2);
			long double dist = sqrt( x*x + y*y );
		       
			s.insert(make_pair(dist, make_pair(i, j)));
//			cout << dist << " " << i << " "<< j << endl;
		}
	}
	
	for(auto i : s)
	{
//		cout << "in set : "<< i.first << " " << i.second.first << " " << i.second.second << endl;
	}
	
	for(int i = 1; i <= n; i++)
	{
		make_set(i);
	}
	int num = n-1, e = 0;
	long double totaldist = 0;
	while(e < num)
	{
		auto p = *s.begin();    //pair
		long double dist = p.first;
	        int u = p.second.first, v = p.second.second;
//		cout << endl << dist << " " << u << " " << v << " " << find_set(u) << " " << find_set(v) << endl;
		if(find_set(u) != find_set(v))
		{
			e++;
			union_sets(u, v);
			totaldist += dist;
//			cout << "totaldist : "<< totaldist << endl;
		}	
		s.erase(s.begin());
	}
	cout << fixed << setprecision(10) << totaldist << endl;

}
