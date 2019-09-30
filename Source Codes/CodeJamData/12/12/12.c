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

const int maxn = 1005;
int a[1005], b[1005];
int done[1005][2];
int main()
{
	int cas = Rint();
	while (cas--)
	{
		int n = Rint();
		for (int i = 1; i <= n; ++i) a[i] = Rint(), b[i] = Rint();
		memset(done, 0, sizeof done);
		int ans = 0, now = 0;
		int left = n;
		for (;left > 0;)
		{
			int choose = 0;
			for (int i = 1; i <= n; ++i) if (done[i][1] == 0 && b[i] <= now)
			{
				choose = i;
				break;
			}
			if (choose > 0)
			{
				if (done[choose][0]) ++now;
				else now += 2;
				done[choose][1] = 1;
				--left;
				++ans;
				continue;
			}
			for (int i = 1; i <= n; ++i) if (done[i][0] == 0 && done[i][1] == 0 && a[i] <= now)
			{
				if (choose == 0) choose = i;
				else
				{
					if (b[i] > b[choose]) choose = i;
				}
			}
			if (choose > 0)
			{
				done[choose][0] = 1;
				++now;
				++ans;
			}
			else
			{
				break;
			}
		}
		static int id = 1;
		printf("Case #%d: ", id++);
		if (left > 0) puts("Too Bad");
		else printf("%d\n", ans);
	}
	return 0;
}
