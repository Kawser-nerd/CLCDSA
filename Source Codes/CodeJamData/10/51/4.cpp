#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <memory>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

typedef long long Int;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

int A[1 << 10];
int P[1 << 20];

int F(int n, int m)
{
	if(n == 1)
		return -1;
	if(n == 2)
		return A[0] == A[1] ? A[0] : -1;

	int res = -1;
	int i, j, k;
	FOR(i, 0, m)
		if(P[i])
		{
			int p = i;
			FOR(j, 0, n)
				if(A[j] >= p)
					break;

			if(j != n)
				continue;
			
			Int a = 0;
			Int b = -1;
			FOR(j, 0, n - 1)
			{
				if(b == -1)
					b = (((A[j + 1] - a*A[j]) % p) + p) % p;

				if(A[j + 1] != (A[j]*a + b) % p)
					break;
			}

			if(j == n - 1)
			{
				int r = (A[n - 1]*a + b) % p;
				if(res == -1)
					res = r;

				if(res != r)
					return -1;
			}

			a = -1;
			FOR(j, 0, n - 2)
			{
				if(a == -1 && (A[j] - A[j + 1] + p) % p != 0)
				{
					Int temp = 1;
					Int s = (A[j] - A[j + 1] + p) % p;
					int power = p - 2;
					for(k = 1; k <= power; k <<= 1)
					{
						if(power & k)
						{
							temp *= s;
							temp %= p;
						}

						s *= s;
						s %= p;
					}

					a = (A[j + 1] - A[j + 2] + p)*temp % p;
					break;
				}
			}

			if(a != -1)
			{
				b = -1;
				FOR(j, 0, n - 1)
				{
					if(b == -1)
						b = (((A[j + 1] - a*A[j]) % p) + p) % p;

					if(A[j + 1] != (A[j]*a + b) % p)
						break;
				}

				if(j == n - 1)
				{
					int r = (A[n - 1]*a + b) % p;
					if(res == -1)
						res = r;

					if(res != r)
						return -1;
				}
			}
		}

	return res;
}

int SolveTest(int test)
{
	int D, K;
	scanf("%d%d", &D, &K);

	int i;
	FOR(i, 0, K)
		scanf("%d", &A[i]);

	int limit = 1;
	FOR(i, 0, D)
		limit *= 10;

	int res = F(K, limit);
	if(res == -1)
		printf("Case #%d: I don't know.\n", test + 1);
	else
		printf("Case #%d: %d\n", test + 1, res);

	return 0;
}

#define MAX (1 << 20)

int main()
{
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	int i, j;
	CLEAR(P, -1);
	P[0] = P[1] = 0;
	FOR(i, 0, MAX)
		if(P[i])
			for(j = i + i; j < MAX; j += i)
				P[j] = 0;

	int T, t;
	char buf[1 << 7];
	gets(buf);
	sscanf(buf, "%d", &T);
	FOR(t, 0, T)
	{
		fprintf(stderr, "Solving %d/%d\n", t + 1, T);
		SolveTest(t);
	}

	return 0;
};
