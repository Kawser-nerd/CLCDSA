#include <iostream>
#include <stdio.h>
#include <math.h>
#include <map>
#include <vector>
using namespace std;

typedef struct{
	map<pair<int,int>, int> s;
	double p;
} STATUS;

vector<STATUS> cur, next;

void drop(STATUS& status, int X, int Y)
{
	if (Y == 0)
	{
		STATUS nt = status;
		nt.s[make_pair(X, Y)] = 1;
		next.push_back(nt);
		return;
	}
	int a = status.s[make_pair(X, Y-2)];
	int b = status.s[make_pair(X-1, Y-1)];
	int c = status.s[make_pair(X+1, Y-1)];
	
	if (b && c)
	{
		STATUS nt = status;
		nt.s[make_pair(X, Y)] = 1;
		next.push_back(nt);
		return;
	}
	if (b && !c)
	{
		drop(status, X+1, Y-1);
		return;
	}
	if (!b && c)
	{
		drop(status, X-1, Y-1);
		return;
	}
	if (!b && !c && a)
	{
		STATUS nt = status;
		nt.p *= 0.5;
		drop(nt, X-1, Y-1);
		drop(nt, X+1, Y-1);
	}
	else
		drop(status, X, Y-1);
}

int main()
{
	int i,j,k;
	int cc,ca;
	int N, X, Y;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cur.clear(); next.clear();
		cin >> N >> X >> Y;

		STATUS s; s.p = 1.0;
		cur.push_back(s);

		for(i=0; i<N; i++)
		{
			next.clear();
			for(j=0; j<cur.size(); j++)
				drop(cur[j], 0, 40);
			//printf("drop %d\n", i);
			cur = next;
		//	printf("next size %d\n", next.size());
		}
		double r = 0.0;
		for(i=0; i<cur.size(); i++)
			r += cur[i].s[make_pair(X, Y)] * cur[i].p;
		printf("Case #%d: %lf\n", cc, r);
	}
}
