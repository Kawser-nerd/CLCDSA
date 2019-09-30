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

int64 data[250];

int main()
{
	int T = Rint();
	for (int i = 0; i < T; ++i)
	{
		int64 A = Rint();
		int n = Rint();
		rep(i, 0, n) data[i] = Rint();
		sort(data, data+n);
		
		int ans = n;
		for (int remove = 0; remove < n; ++remove)
		{
			int t = 0;
			int64 now = A;
			for (int j = 0; j < n - remove; )
			{
				if (now <= data[j])
				{
					int64 inc = now - 1;
					if (inc == 0)
					{
						t = n;
						break;
					}
					now += inc;
					++t;
				}
				else
				{
					now += data[j];
					++j;
				}
			}
			if (t + remove < ans) ans = t + remove;
		}
		static int id = 1;
		printf("Case #%d: %d\n", id++, ans);
	}
	return 0;
}
