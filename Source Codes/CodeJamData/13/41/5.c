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

const int64 mod = 1000002013;

struct Pt
{
	int s, t, c;
	int operator < (const Pt& o) const
	{
		if (s != o.s) return s < o.s;
		return t > o.t;
	}
};
Pt data[1024];

vector<Pt> compose(const vector<Pt>& in)
{
	map<pair<int, int>, int64> t;
	rep(i, 0, in.size()) if(in[i].c) t[mp(in[i].s, in[i].t)] += in[i].c;
	vector<Pt> ret;
	foreach(iter, t)
	{
		Pt temp;
		temp.s = iter->first.first;
		temp.t = iter->first.second;
		temp.c = iter->second;
		ret.pb(temp);
	}
	return ret;
}
int main()
{
	int T = Rint();
	for (int cid = 1; cid <= T; ++cid)
	{
		int n = Rint();
		int m = Rint();
		rep(j, 0, m) data[j].s = Rint(), data[j].t = Rint(), data[j].c = Rint();
		int64 ans0 = 0;
		rep(i, 0, m)
		{
			int64 diff = data[i].t - data[i].s;
			int64 x = diff * (diff - 1) / 2 % mod;
			ans0 = (ans0 + x * data[i].c % mod) % mod;
		}
		sort(data, data+m);
		vector<Pt> u;
		rep(i, 0, m) u.pb(data[i]);
		for (;;)
		{
			vector<Pt> v;
			const int size = sz(u);
			int flag = 0;
			for (int i = 0; i < size; ++i) if (u[i].c)
			for (int j = i+1; j < size; ++j) if (u[j].c)
			{
				if (i == j) continue;
				if (u[j].s <= u[i].s) continue;
				if (u[j].s > u[i].t) break;
				if (u[j].t <= u[i].t) continue;
				int64 how = min(u[i].c, u[j].c);
				if (!how) continue;
				u[i].c -= how, u[j].c -= how;
				Pt temp;
				temp.s = u[i].s;
				temp.t = u[j].t;
				temp.c = how;
				v.pb(temp);
				temp.s = u[j].s;
				temp.t = u[i].t;
				v.pb(temp);
				flag = 1;
			}
			for (int i = 0; i < size; ++i) if (u[i].c)
			v.pb(u[i]);
			sort(v.begin(), v.end());
			u = compose(v);
			if (!flag) break;
		}
		int64 ans1 = 0;
		rep(i, 0, u.size())
		{
			int64 diff = u[i].t - u[i].s;
			int64 x = diff * (diff - 1) / 2 % mod;
			ans1 = (ans1 + x * u[i].c % mod) % mod;
		}
		int64 ans = ans1 - ans0;
		if (ans < 0) ans += mod;
		printf("Case #%d: ", cid);
		printf("%lld\n", ans);
	}
	return 0;
}
