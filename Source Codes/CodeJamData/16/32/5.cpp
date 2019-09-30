#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 50;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int cc = 1; cc <= T; ++cc)
	{
		printf("Case #%d: ", cc);
		int n;
		LL m;
		scanf("%d%I64d", &n, &m);
		if (1LL << (n - 2) < m) printf("IMPOSSIBLE\n");
		else
		{
			printf("POSSIBLE\n");
			static bool ans[maxn + 5][maxn + 5];
			REP(i, 0, n)
			{
				REP(j, 0, n)
				{
					int tmp = i < j;
					if (j == n - 1)
					{
						if (i == n - 1) tmp = 0;
						else 
						{
							if (m == 1LL << (n - 2)) tmp = 1;
							else if (i > 0) tmp = m >> (i - 1) & 1;
							else tmp = 0;
						}
					}
					ans[i][j] = tmp;
					putchar('0' + tmp);
				}
				printf("\n");
			}
			static LL dp[maxn + 5];
			memset(dp, 0, sizeof dp);
			dp[0] = 1;
			REP(i, 0, n) if (dp[i]) REP(j, i + 1, n) if (ans[i][j]) dp[j] += dp[i];
			assert(dp[n - 1] == m);
		}
	}
	return 0;
}
