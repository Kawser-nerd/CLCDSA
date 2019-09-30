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

map<vector<int>, int> dp;

int n, Mod;

vector<int> start;

int dfs(vector<int> now)
{
	if (dp.count(now)) return dp[now];
	int &ret = dp[now];
	int sum = 0;
	REP(i, 0, Mod) (sum += now[i] * i) %= Mod;
	ret = 0;
	REP(i, 0, Mod) if (now[i])
	{
		--now[i];
		chkmax(ret, dfs(now) + (sum == i));
		++now[i];
	}
	return ret;
}

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
		printf("Case #%d: ", case_id);
		start.clear();
		scanf("%d%d", &n, &Mod);
		start.resize(Mod);
		REP(i, 0, n)
		{
			int x;
			scanf("%d", &x);
			++start[x % Mod];
		}
		printf("%d\n", dfs(start));
	}
	return 0;
}
