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
		int cnt[26];
		int n;
		scanf("%d", &n);
		REP(i, 0, n) scanf("%d", cnt + i);
		while (1)
		{
			vector<int> all;
			int Max = *max_element(cnt, cnt + n);
			if (Max == 0) break;
			REP(j, 0, n) if (cnt[j] == Max) all.pb(j);
			if (SZ(all) == 2) printf("%c%c ", 'A' + all[0], 'A' + all[1]), --cnt[all[0]], --cnt[all[1]];
			else printf("%c ", 'A' + all[0]), --cnt[all[0]];
		}
		printf("\n");
	}
	return 0;
}
