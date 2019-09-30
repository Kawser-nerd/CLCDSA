#include <iostream>
#include <stdio.h>
#include <map>
using namespace std;

long long N,M;
long long cost(int s, int e)
{
	long long n = (e-s);
	return (2*N-n+1)*n/2;
}

map<pair<int,int>, int> m;

int main()
{
	int cc,ca;
	int i,j,k;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> N >> M;
		m.clear();
		for(i=0; i<M; i++)
		{
			int o,e,p;
			cin >> o >> e >> p;
			m[make_pair(o,e)] += p;
		}
		long long r = 0;
again:
		for(map<pair<int,int>, int>::iterator p = m.begin(); p != m.end(); p++)
			for(map<pair<int,int>, int>::iterator q = p; q != m.end(); q++)
			{
				if (q == p) continue;
				int o1 = p->first.first; int e1 = p->first.second; int p1 = p->second;
				int o2 = q->first.first; int e2 = q->first.second; int p2 = q->second;

				if (o2 <= e1 && o1 <= e2 && cost(o2, e1) + cost(o1, e2) < cost(o1, e1) + cost(o2, e2))
				{
					int sw = min(p1, p2);
					m[make_pair(o1, e1)] -= sw;
					if (m[make_pair(o1, e1)] == 0) m.erase(make_pair(o1,e1));
					m[make_pair(o2, e2)] -= sw;
					if (m[make_pair(o2, e2)] == 0) m.erase(make_pair(o2, e2));
					m[make_pair(o1, e2)] += sw;
					m[make_pair(o2, e1)] += sw;
					r += -(cost(o2, e1) + cost(o1, e2) - cost(o1, e1) - cost(o2, e2))*sw; 
					r %= 1000002013;
					goto again;
				}
			}
		printf("Case #%d: %lld\n", cc, r);
	}
}
