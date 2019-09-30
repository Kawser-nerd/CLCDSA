#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <numeric>
#include <functional>
#include <iterator>
#include <typeinfo>
#include <utility>
#include <memory>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstddef>
#include <complex>
#include <ctime>
#include <cassert>
using namespace std;

typedef long long int64;
const int inf = 2000000000;
static inline int Rint()
{
	struct X{ int dig[256]; X(){
	for(int i = '0'; i <= '9'; ++i) dig[i] = 1; dig['-'] = 1;
	}};
	static 	X fuck;int s = 1, v = 0, c;
	for (;!fuck.dig[c = getchar()];);
	if (c == '-') s = 0; else if (fuck.dig[c]) v = c ^ 48;
	for (;fuck.dig[c = getchar()]; v = v * 10 + (c ^ 48));
	return s ? v : -v;
}
typedef vector<int> vi;
typedef vi::iterator ivi;
typedef map<int, int> mii;
typedef mii::iterator imii;
typedef set<int> si;
typedef si::iterator isi;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz(x) ((int)(x).size())
#define rep(i, s, e) for (int i = (s); i < (e); ++i)
#define foreach(itr, c) for(__typeof((c).begin()) itr = (c).begin(); itr != (c).end(); ++itr)
template<typename T> static inline void cmax(T& a, const T& b){if(b>a)a=b;}
template<typename T> static inline void cmin(T& a, const T& b){if(b<a)a=b;}

const int n = 522196;
char dict[n][16];
int len[n];

int valid[12][1<<11];

static inline int check(int mask, int len)
{
	for (int i = 0; i < len; ++i) if ((mask&(1<<i)) == 0)
	for (int j = i + 1; j < len; ++j) if ((mask&(1<<j)) == 0)
	if (j - i < 5) return 0;
	return 1;
}

static inline int can_join(int m1, int len1, int m2, int len2)
{
	return check(m1 | m2 << len1, len1 + len2);
}

void init()
{
	FILE* fp = fopen("garbled_email_dictionary.txt", "r");
	rep(i, 0, n) fscanf(fp, "%s", dict[i]);
	fclose(fp);
	rep(i, 0, n) len[i] = strlen(dict[i]);
	cerr << clock() << endl;
	
	for (int i = 1; i < 12; ++i)
	{
		for (int mask = 0; mask < 1<<i; ++mask)
		{
			valid[i][mask] = check(mask, i);
		}
	}
	cerr << clock() << endl;
}

int have[55][12][1<<11];
vi have_list[55][12];
int dp[55][1<<11];
int slen;
int dfs(int start, int mask)
{
	int& ret = dp[start][mask];
	if (ret != -1) return ret;
	if (start == slen) return ret = 0;

	ret = inf;
	for (int i = 1; i < 12; ++i)
	{
		const int size = sz(have_list[start][i]);
		for (int j = 0; j < size; ++j)
		{
			int m = have_list[start][i][j];
			int cost = i - __builtin_popcount(m);
			if (can_join(mask, 11, m, i))
			{
				int t = dfs(start+i, (mask|m<<11)>>i);
				if (t != inf)
				{
					if (cost + t < ret) ret = cost + t;
				}
			}
		}
	}
	return ret;
}

char buff[256];
int get_mask(const char* str, const char* d, int len)
{
	int ret = 0;
	int flag = 1;
	for (int i = 0; i < len; ++i, flag <<= 1)
	if (str[i] == d[i]) ret |= flag;
	return ret;
}

int main()
{
	init();
	
	int T = Rint();
	rep(caseid, 0, T)
	{
		scanf("%s", buff);
		memset(have, 0, sizeof have);
		int l = strlen(buff);
		slen = l;
		rep(i, 0, 50) rep(j, 0, 12) have_list[i][j].clear();
		for (int i = 0; i < l; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int msk = get_mask(buff+i, dict[j], len[j]);
				if (valid[len[j]][msk]) have[i][len[j]][msk] = 1;
			}
			for (int x = 1; x < 12; ++x)
			for (int y = 0; y < 1 << x; ++y)
			if (have[i][x][y]) have_list[i][x].pb(y);
		}
		memset(dp, -1, sizeof dp);
		int ans = dfs(0, (1<<11)-1);
		static int id = 1;
		printf("Case #%d: %d\n", id++, ans);
	}
	return 0;
}
