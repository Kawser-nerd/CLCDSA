#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
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

const int maxn = 1010;

int cnt[maxn + 5];
int cus[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int case_cnt;
	scanf("%d", &case_cnt);
	for (int case_id = 1; case_id <= case_cnt; ++case_id)
	{
		printf("Case #%d: ", case_id);;
		memset(cnt, 0, sizeof cnt);
		memset(cus, 0, sizeof cus);
		int n, c, m;
		scanf("%d%d%d", &n, &c, &m);
		REP(i, 0, m)
		{
			int x, y;
			scanf("%d%d", &x, &y), --x, --y;
			++cnt[x], ++cus[y];
		}
		int ans = *max_element(cus, cus + c);
		int sum = 0;
		REP(i, 0, n)
		{
			sum += cnt[i];
			chkmax(ans, (sum + i) / (i + 1));
		}
		int need = 0;
		REP(i, 0, n) need += max(0, cnt[i] - ans);
		printf("%d %d\n", ans, need);
	}
	return 0;
}
