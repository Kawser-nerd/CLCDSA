#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;
#define MAX 1000
int N;
bool matr[MAX][MAX];
bool was[MAX];
int order[MAX];
int p;

void srt(int v)
{
	was[v] = true;
	for (int i = 0; i < N; i++)
		if (!was[i] && matr[v][i])
			srt(i);
	p--;
	order[p] = v;
}

bool f(int v)
{
	was[v] = true;
	bool res = false;
	for (int i = 0; i < N; i++)
		if (matr[v][i])
		{
			if (was[i])
				res = true;
			else
				res = res | f(i);
		}
	return res;
}

int main()
{
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		memset(matr, 0, sizeof(bool) * MAX * MAX);
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			int m;
			scanf("%d", &m);
			for (int j = 0; j < m; j++)
			{
				int a;
				scanf("%d", &a);
				matr[i][a-1] = true;
			}
		}
		bool res = false;
		for (int i = 0; i < N; i++)
		{
			memset(was, 0, sizeof(bool) * MAX);
			if (f(i))
			{
				res = true;
				break;
			}
		}
		printf("Case #%d: %s\n", t+1, res ? "Yes" : "No");
	}

	return 0;
}