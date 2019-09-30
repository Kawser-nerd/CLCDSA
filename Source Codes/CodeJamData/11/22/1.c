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

int64 P[205], V[205];

int64 check(int64 mid, int64 c, int64 d)
{
	int64 prev = -20000000000000000LL;
	rep(i, 0, c)
	{
		int64 left_most = max(prev+d, P[i]-mid);
		int64 right_most = left_most + (V[i] - 1) * d;
		if (right_most > P[i] + mid) return 0;
		prev = right_most;
	}
	return 1;
}
int main()
{
	int cas = Rint();
	for (int caseID = 1; caseID <= cas; ++caseID)
	{
		int64 c = Rint(), d = Rint() << 1;
		rep(i, 0, c) P[i] = Rint()*2, V[i] = Rint();
		//if (caseID == 1) {check(2, c, d);}
		//continue;
		int64 l = 0, r = 20000000000000LL;
		while (l <= r)
		{
			int64 mid = l + r >> 1;
			if (check(mid, c, d)) r = mid - 1; else l = mid + 1;
		}
		printf("Case #%d: %.10f\n", caseID, 0.5*l);
	}
	return 0;
}
