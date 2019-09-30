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

const int maxn = 100005;
double p[maxn];
double dp[maxn][2];
int main()
{
	int cas = Rint();
	while (cas--)
	{
		int a = Rint(), b = Rint();
		for (int i = 1; i <= a; ++i) scanf("%lf", p+i);
		dp[0][0] = 1;
		dp[0][1] = 0;
		for (int i = 1; i <= a; ++i)
		{
			dp[i][0] = dp[i-1][0] * p[i];
			dp[i][1] = dp[i-1][1] + dp[i-1][0] * (1 - p[i]);
		}
		double ans = b-a+1+dp[a][1]*(b + 1);
		for (int i = 1; i <= a; ++i)
		{
			double t = (a - i + 1) + (b - i + 1) + 1 + dp[i-1][1] * (b + 1);
			cmin(ans, t);
		}
		cmin(ans, 2.+b);
		static int id = 1;
		printf("Case #%d: %.16f\n", id++, ans);
	}
	return 0;
}
