#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cassert>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

const int maxn = 100;

int l, l0, L;
char s[maxn + 5], s0[maxn + 5];

int cnt[26];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case)
	{
		scanf("%d%d%d", &l, &l0, &L);
		scanf("%s%s", s, s0);
		memset(cnt, 0, sizeof cnt);
		REP(i, 0, l) ++cnt[s[i] - 'A'];
		int len = -1;
		for (int i = l0 - 1; i >= 0; --i)
			if (!strncmp(s0, s0 + (l0 - i), i))
			{
				len = i;
				break;
			}
		double ans = (L - len) / (l0 - len);
		REP(i, 0, l0) if (!cnt[s0[i] - 'A']) ans = 0;
		double po = 1;
		REP(i, 0, l0) po *= (double)cnt[s0[i] - 'A'] / l;
		ans -= (L - l0 + 1) * po;
		ans = max(ans, 0.0);
		printf("Case #%d: %.15f\n", Case, ans);
	}
	return 0;
}
