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
template<typename T> void cmax(T& a, const T& b){if(b>a)a=b;}
template<typename T> void cmin(T& a, const T& b){if(b<a)a=b;}
struct Pt
{
	int beg, end;
	int speed;
	int operator <(const Pt& o) const
	{
		return speed < o.speed;
	}
};
const double eps = 1e-8;
int main()
{
	int T = Rint();
	for (int caseID = 1; caseID <= T; ++caseID)
	{
		int x = Rint();
		int s = Rint();
		int r = Rint();
		int t = Rint();
		int n = Rint();
		vector<Pt> vec(n);
		rep(i, 0, n)
		{
			vec[i].beg = Rint();
			vec[i].end = Rint();
			vec[i].speed = Rint();
		}
		
		vector<Pt> seg;
		int last = 0;
		rep(i, 0, n)
		{
			if (vec[i].beg > last)
			{
				Pt tmp;
				tmp.beg = last;
				tmp.end = vec[i].beg;
				tmp.speed = s;
				seg.pb(tmp);
			}
			Pt tmp = vec[i];
			tmp.speed = vec[i].speed + s;
			seg.pb(tmp);
			last = vec[i].end;
		}
		if (seg[sz(seg)-1].end != x)
		{
			Pt tmp;
			tmp.beg = seg[sz(seg)-1].end;
			tmp.end = x;
			tmp.speed = s;
			seg.pb(tmp);
		}
		sort(all(seg));
		
		double remain = t;
		double ans = 0;
		for (int i = 0; i < sz(seg); ++i)
		{
			if (fabs(remain) > eps)
			{
				double tmp = 1.*(seg[i].end - seg[i].beg)/(seg[i].speed+r-s);
				if (tmp <= remain)
				{
					remain -= tmp;
					ans += tmp;
				}
				else
				{
					ans += remain;
					double left = seg[i].end - seg[i].beg - (seg[i].speed+r-s)*remain;
					remain = 0;
					ans += left / seg[i].speed;
				}
			}
			else
			{
				ans += 1.*(seg[i].end - seg[i].beg)/seg[i].speed;
			}
		}
		printf("Case #%d: %.16f\n", caseID, ans);
	}
	return 0;
}
