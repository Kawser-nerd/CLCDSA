#include <stdio.h>
#include <memory.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


using namespace std;
#define MAX 110

int N, M;
long long m1[MAX][2];
long long m2[MAX][2];
long long matr[MAX][MAX];

long long f(int n, int m)
{
	if (n == 0 || m == 0)
		return 0;
	n--;
	m--;
	if (matr[n][m] != -1)
		return matr[n][m];
	long long res;
	if (m1[n][1] != m2[m][1])
		res = max(f(n+1, m), f(n, m+1));
	else
	{
		long long s1 = 0;
		long long s2 = 0;
		for (int i = 0; i <= n; i++)
			if (m1[i][1] == m1[n][1])
				s1 += m1[i][0];

		for (int i = 0; i <= m; i++)
			if (m2[i][1] == m2[m][1])
				s2 += m2[i][0];

		long long t1 = 0;
		long long t2 = 0;
		res = 0;
		for (int i = 0; i <= n; i++)
		{
			
			t2 = 0;
			for (int j = 0; j <= m; j++)
			{
				res = max(res, min(s1 - t1, s2 - t2) + f(i, j));
				if (m2[j][1] == m2[m][1])
					t2 += m2[j][0];
			}
			if (m1[i][1] == m1[n][1])
				t1 += m1[i][0];
		}
	}


	matr[n][m] = res;
	return res;
}


int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; i++)
			scanf("%lld%lld", &m1[i][0], &m1[i][1]);
		for (int i = 0; i < M; i++)
			scanf("%lld%lld", &m2[i][0], &m2[i][1]);

		for (int i = 0; i < MAX; i++)
			for (int j = 0; j < MAX; j++)
				matr[i][j] = -1;
		long long res  = f(N, M);
		printf("Case #%d: %lld\n", t+1, res);
	}

	return 0;
}