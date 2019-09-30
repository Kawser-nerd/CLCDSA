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

int key[256];
int k, n;
int contain[21][100];
int need[21];
int have[21];

vector<int> seq[1<<20];
int dp[1<<20];
int have_key[1<<20][200];
int flag[1<<20];
int main()
{
	int cas = Rint();
	while (cas--)
	{
		k = Rint(), n = Rint();
		for (int i = 0; i < k; ++i) key[i] = Rint() - 1;
		rep(i, 0, n)
		{
			need[i] = Rint() - 1;
			have[i] = Rint();
			rep(j, 0, have[i]) contain[i][j] = Rint() - 1;
		}
		const int limit = 1 <<n ;
		static int id = 1;
		printf("Case #%d: ", id++);
		
		{
			fill(flag, flag+limit, 0);
			for (int i = 0; i < limit; ++i)
			memset(have_key[i], 0, sizeof(have_key[i]));
			for (int i = 0; i < k; ++i) ++have_key[0][key[i]];
			flag[0] = 1;
			rep(i, 0, limit) rep(j, 0, n)
			if ((i & (1 << j)) == 0)
			{
				int next = i | 1 << j;
				if (flag[next] == 0 && have_key[i][need[j]] > 0)
				{
					memcpy(have_key[next], have_key[i], sizeof(have_key[i]));
					--have_key[next][need[j]];
					for (int x = 0; x < have[j]; ++x)
					++have_key[next][contain[j][x]];
					flag[next] = 1;
				}
			}
		}
		if (flag[limit-1] == 0) {puts("IMPOSSIBLE");continue;}
		{
			rep(i, 0, limit) vector<int>().swap(seq[i]);
			fill(dp, dp+limit, 0);
			dp[0] = 1;
			
			rep(i, 0, limit) rep(j, 0, n)
			if ((i & (1 << j)) == 0)
			{
				int next = i | 1 << j;
				if (have_key[i][need[j]] > 0)
				{
					if (dp[next] == 0)
					{
						dp[next] = 1;
						seq[next] = seq[i];
						seq[next].push_back(j);
					}
					else
					{
						vector<int> temp = seq[i];
						temp.push_back(j);
						if (temp < seq[next]) seq[next] = temp;
					}
					//cerr << next << endl;
				}
			}
		}
		
		if (seq[limit-1].empty()) {puts("IMPOSSIBLE");continue;}
		for (int i = 0; i < sz(seq[limit-1]); ++i)
		{
			printf("%d", seq[limit-1][i]+1);
			if (i < sz(seq[limit-1]) - 1) putchar(' ');
		}
		puts("");
	}
	return 0;
}
