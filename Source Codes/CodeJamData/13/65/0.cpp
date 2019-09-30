#define _CRT_SECURE_NO_WARNINGS
//#pragma comment(linker, "/STACK:134217728")

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <numeric>
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

#define MAX 128
#define MOD 10007

int R[MAX][MAX][MAX];
int F[MAX];
int A[MAX];

int SolveTest(int test)
{
	int N;
	scanf("%d", &N);

	int i, j, k, l;
	FOR(i, 0, N)
		scanf("%d", &A[i]);

	CLEAR(R, 0);
	R[0][0][0] = 1;

	FOR(i, 0, N)
		FOR(j, 0, N)
			FOR(k, 0, N + 1)
				if(R[i][j][k] != 0)
				{
					int from = max(i, k);
					FOR(l, from, N)
					{
						if(i != 0 && A[l] > A[i - 1])
							continue;

						if(i < k && (i == 0 || A[i - 1] >= A[k - 1]) && A[k - 1] >= A[l])
							continue;

						R[l + 1][j + 1][k] += R[i][j][k];
						R[l + 1][j + 1][k] %= MOD;
					}

					if(k == 0)
						FOR(l, from, N)
						{
							R[i][j + 1][l + 1] += R[i][j][k];
							R[i][j + 1][l + 1] %= MOD;
						}
				}


	F[0] = 1;
	FOR(i, 1, N + 1)
		F[i] = F[i - 1]*i % MOD;

	Int res = 0;
	FOR(i, 0, N + 1)
		FOR(j, 0, N + 1)
			FOR(k, 0, N + 1)
				if(R[i][j][k] != 0)
				{
					if(k == 0 && j != N)
						continue;

					if(i < k && (i == 0 || A[i - 1] >= A[k - 1]))
						continue;
		
					res += (R[i][j][k])*F[N - j] % MOD;
				}

	if(N == 1)
		res = 1;

	printf("Case #%d: %d\n", test + 1, int(res % MOD));
	return 0;
}

int main()
{
	freopen("e.in", "r", stdin);
	freopen("e.out", "w", stdout);

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
