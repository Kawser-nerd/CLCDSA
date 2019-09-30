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

int64 get_worst(int n, int64 x)
{
	int64 tot = x + 1;
	int64 history[64] = {0};
	int now = 0;
	while (tot >= 2) history[now++] = 1, tot /= 2;
	int64 ret = 0;
	for (int i = 0; i < n; ++i)
	ret = ret * 2 + history[i];
	return ret+1;
}
int64 solve0(int n, int64 p)
{
	int64 l = 0, r = (1LL << n) - 1;
	while (l <= r)
	{
		int64 mid = l + r >> 1;
		if (get_worst(n, mid) > p) r = mid - 1;
		else l = mid + 1;
	}
	return r;
}
int64 get_best(int n, int64 x)
{
	int64 tot = (1LL << n) - x;
	int64 history[64] = {0};
	int now = 0;
	while (tot >= 2) history[now++] = 1, tot /= 2;
	int64 ret = 0;
	for (int i = 0; i < n; ++i)
	ret = ret * 2 + 1 - history[i];
	return ret+1;
}
int64 solve1(int n, int64 p)
{
	int64 l = 0, r = (1LL << n) - 1;
	while (l <= r)
	{
		int64 mid = l + r >> 1;
		if (get_best(n, mid) <= p) l = mid + 1;
		else r = mid - 1;
	}
	return r;
}
int main()
{
	int t = Rint();
	for (int id = 1; id <= t; ++id)
	{
		int64 n, p;
		scanf("%lld%lld", &n, &p);
		printf("Case #%d: ", id);
		cout << solve0(n, p) << " " << solve1(n, p) << endl;
	}
	return 0;
}
