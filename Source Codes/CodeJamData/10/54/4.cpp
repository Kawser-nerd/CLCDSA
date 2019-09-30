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

#define MOD 1000000007

int A[72];
int C[72][72][72*72];
Int S[72][72][72];
Int Res[72][72][72][2];
Int M[72][72][2];

int SolveTest(int test)
{
	Int N;
	int B;
	scanf("%lld%d", &N, &B);

	int cnt = 0;
	while(N != 0)
	{
		A[cnt] = int(N % B);
		N /= B;
		++cnt;
	}

	int i, j, k, l, jj, kk;

	CLEAR(M, 0);
	FOR(i, 0, B + 1)
		FOR(j, i, B + 1)
		{
			M[i][j][0] = 1;
			FOR(l, 0, i)
			{
				M[i][j][0] *= j - l;
				M[i][j][0] %= MOD;
			}

			M[i][j][1] = i;
			FOR(l, 0, i - 1)
			{
				M[i][j][1] *= j - 1 - l;
				M[i][j][1] %= MOD;
			}
		}

	CLEAR(C, 0);
	C[0][0][0] = 1;
	FOR(i, 0, B - 1)
		FOR(j, 0, i + 1)
			FOR(k, 0, B*B)
				if(C[i][j][k] != 0)
				{
					C[i + 1][j][k] += C[i][j][k];
					C[i + 1][j][k] %= MOD;
					C[i + 1][j + 1][k + i + 1] += C[i][j][k];
					C[i + 1][j + 1][k + i + 1] %= MOD;
				}

	CLEAR(S, 0);
	FOR(i, 0, B)
		FOR(j, 0, B*B)
			if(C[B - 1][i][j] != 0)
			{
				S[i][j % B][j / B] += C[B - 1][i][j];
				S[i][j % B][j / B] %= MOD;
			}

	CLEAR(Res, 0);
	Res[0][0][B][0] = 1;
	FOR(i, 0, cnt)
		FOR(j, 0, B)
			FOR(k, 0, B + 1)
				FOR(l, 0, 2)
					if(Res[i][j][k][l] != 0)
					{
						int rem = A[i] - j;
						int next = 0;
						if(rem < 0)
						{
							rem += B;
							++next;
						}

						FOR(kk, 0, k + 1)
						{
							Int m = (i == 0 ? 1 : M[kk][k][l]);
							m *= Res[i][j][k][l];
							m %= MOD;

							FOR(jj, 0, kk + 1)
							{
								if(S[kk][rem][jj] != 0 && (kk != 0 || l == 0))
								{
									Res[i + 1][jj + next][kk][0] += S[kk][rem][jj]*m;
									Res[i + 1][jj + next][kk][0] %= MOD;
								}

								if(kk != 0 && S[kk - 1][rem][jj] != 0)
								{
									Res[i + 1][jj + next][kk][1] += S[kk - 1][rem][jj]*m;
									Res[i + 1][jj + next][kk][1] %= MOD;
								}
							}
						}
					}

	Int res = 0;
	FOR(i, 0, B + 1)
	{
		res += Res[cnt][0][i][0];
		res %= MOD;
	}

	printf("Case #%d: %d\n", test + 1, int(res));
	return 0;
}

int main()
{
	freopen("d.in", "r", stdin);
	freopen("d.out", "w", stdout);

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
