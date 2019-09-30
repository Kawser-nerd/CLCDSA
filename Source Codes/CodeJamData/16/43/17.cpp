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

const int max0 = 16, max1 = 50, max2 = 1000;

int n, m;

int N;
int a[max1 + 5];

int idr[max0 + 5][max0 + 5];
int idc[max0 + 5][max0 + 5];

int fa[max2 + 5];

int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }

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
		printf("Case #%d: \n", cc);
		scanf("%d%d", &n, &m);
		N = (n + m) << 1;
		REP(i, 0, N) scanf("%d", a + i), --a[i];
		int now = 0;
		REP(i, 0, m) idr[0][i] = now++;
		REP(i, 0, n) idc[i][m] = now++;
		for (int i = m - 1; i >= 0; --i) idr[n][i] = now++;
		for (int i = n - 1; i >= 0; --i) idc[i][0] = now++;
		REP(i, 1, n) REP(j, 0, m) idr[i][j] = now++;
		REP(i, 0, n) REP(j, 1, m) idc[i][j] = now++;
		static char ans[max0 + 5];
		bool find = 0;
		REP(i, 0, 1 << (n * m))
		{
			static char tmp[max0 + 5];
			REP(j, 0, now) fa[j] = j;
			REP(j, 0, n) REP(k, 0, m)
			{
				int cur = j * m + k;
				bool ty = i >> cur & 1;
				if (ty) tmp[cur] = '/', fa[get(idc[j][k])] = get(idr[j][k]), fa[get(idc[j][k + 1])] = get(idr[j + 1][k]);
				else tmp[cur] = '\\', fa[get(idc[j][k + 1])] = get(idr[j][k]), fa[get(idc[j][k])] = get(idr[j + 1][k]);
			}
			find = 1;
			for (int j = 0; j < N; ++j) if (get(a[j]) != get(a[j ^ 1])) { find = 0; break; }
			if (find) { memcpy(ans, tmp, sizeof ans); break; }
		}
		if (!find) puts("IMPOSSIBLE");
		else
		{
			REP(i, 0, n) 
			{
				REP(j, 0, m) putchar(ans[i * m + j]);
				putchar('\n');
			}
		}
	}
	return 0;
}
