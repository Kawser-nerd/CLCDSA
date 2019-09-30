#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int M,V;
int g[10001], v[10001];
int best[10001][2];

int calc(int p, int dv)
{
	if (best[p][dv] >= 0)
		return best[p][dv];
	if (p > (M-1)/2)
	{
		if (v[p] == dv)
			return 0;
		else
			return 1000000;
	}
	int& r = best[p][dv];
	r = 1000000;
	int t;
	if (g[p] == 1) // AND gate
	{
		if (dv == 1)
		{
			t = calc(p*2, 1) + calc(p*2+1, 1);
			if (t < r ) r = t;
		}
		else
		{
			t = calc(p*2, 1) + calc(p*2+1, 0);
			if (t < r) r = t;
			t = calc(p*2, 0) + calc(p*2+1, 1);
			if (t < r) r = t;
			t = calc(p*2, 0) + calc(p*2+1, 0);
			if (t < r ) r = t;
		}
	}
	else // OR gate
	{
		if (dv == 1)
		{
			t = calc(p*2, 1) + calc(p*2+1, 1);
			if (t < r) r = t;
			t = calc(p*2, 1) + calc(p*2+1, 0);
			if (t < r) r = t;
			t = calc(p*2, 0) + calc(p*2+1, 1);
			if (t < r) r = t;
		}
		else
		{
			t = calc(p*2, 0) + calc(p*2+1, 0);
			if (t < r) r = t;
		}
	}
	if (v[p]) // changable
	{
		if (g[p] == 1) // calc as or gate
		{
			if (dv == 1)
			{
				t = calc(p*2, 1) + calc(p*2+1, 1) + 1;
				if (t < r) r = t;
				t = calc(p*2, 1) + calc(p*2+1, 0) + 1;
				if (t < r) r = t;
				t = calc(p*2, 0) + calc(p*2+1, 1) + 1;
				if (t < r) r = t;
			}
			else
			{
				t = calc(p*2, 0) + calc(p*2+1, 0) + 1;
				if (t < r) r = t;
			}
		}
		else // calc as and gate
		{
			if (dv == 1)
			{
				t = calc(p*2, 1) + calc(p*2+1, 1) + 1;
				if (t < r ) r = t;
			}
			else
			{
				t = calc(p*2, 1) + calc(p*2+1, 0) + 1;
				if (t < r) r = t;
				t = calc(p*2, 0) + calc(p*2+1, 1) + 1;
				if (t < r) r = t;
				t = calc(p*2, 0) + calc(p*2+1, 0) + 1;
				if (t < r ) r = t;
			}
		}
	}
	return r;
}

int main()
{
	int cc,ca;
	int i,j,k;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		cin >> M >> V;
		for(i=1; i<=(M-1)/2; i++)
		{
			int a,b;
			cin >> a >> b;
			g[i] = a;
			v[i] = b;
		}
		for(;i<=M; i++)
			cin >> v[i];
		for(i=0; i<=10000; i++) for(j=0; j<2; j++) best[i][j] = -1;
		int r = calc(1, V);
		if (r == 1000000)
			printf("Case #%d: IMPOSSIBLE\n", cc);
		else
			printf("Case #%d: %d\n", cc, r);
	}
}
