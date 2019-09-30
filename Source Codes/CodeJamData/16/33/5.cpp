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
		int a, b, c, K;
		scanf("%d%d%d%d", &a, &b, &c, &K);
		assert(a <= b && b <= c);
		int cnt0[100][100];
		int cnt1[100][100];
		int cnt2[100][100];
		memset(cnt0, 0, sizeof cnt0);
		memset(cnt1, 0, sizeof cnt1);
		memset(cnt2, 0, sizeof cnt2);
		if (K >= c)
		{
			printf("%d\n", a * b * c);
			REP(i, 0, a) REP(j, 0, b) REP(k, 0, c)
			{
				++cnt0[i][j];
				++cnt1[i][k];
				++cnt2[j][k];
				printf("%d %d %d\n", i + 1, j + 1, k + 1);
			}
		}
		else
		{
			printf("%d\n", a * b * K);
			REP(i, 0, a)
			{
				REP(j, 0, b)
					REP(k, 0, K)
					{
						int u = i, v = j, w = (i + j + k) % c;
						++cnt0[u][v];
						++cnt1[u][w];
						++cnt2[v][w];
						printf("%d %d %d\n", u + 1, v + 1, w + 1);
					}
			}
		}
		fflush(stdout);
		REP(i, 0, a) REP(j, 0, b) assert(cnt0[i][j] <= K);
		REP(i, 0, a) REP(j, 0, c) assert(cnt1[i][j] <= K);
		REP(i, 0, b) REP(j, 0, c) assert(cnt2[i][j] <= K);
	}
	return 0;
}
