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

const int maxn = 200;

int n, K;
double a[maxn + 5];

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
		scanf("%d%d", &n, &K);
		REP(i, 0, n) scanf("%lf", a + i);
		sort(a, a + n);
		vector<double> b;
		double ans = 0;
		REP(num, 0, K + 1)
		{
			b.clear();
			REP(j, 0, num) b.pb(a[j]);
			REP(j, n - (K - num), n) b.pb(a[j]);
			static double f[maxn + 5][maxn + 5];
			memset(f, 0, sizeof f);
			f[0][0] = 1;
			REP(i, 0, K) REP(j, 0, i + 1) f[i + 1][j + 1] += f[i][j] * b[i], f[i + 1][j] += f[i][j] * (1 - b[i]);
			chkmax(ans, f[K][K >> 1]);
		}
		printf("%.15f\n", ans);
	}
	return 0;
}
