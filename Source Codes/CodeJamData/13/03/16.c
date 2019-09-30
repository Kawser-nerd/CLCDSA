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

const int maxn = 10000005;

int force_check(int64 x)
{
	int64 y = 0;
	for (int64 t = x; t; t /= 10) y = y * 10 + t % 10;
	return x == y;
}
int flag[maxn];
int plist[maxn];
int top = 0;
int64 alist[maxn];
int top1 = 0;
void init()
{
	fill(flag, flag+maxn, 0);
	for (int i = 1; i < maxn; ++i)
	{
		flag[i] = force_check(i);
		if (flag[i]) plist[top++] = i;
	}
	cerr << top << endl;
	for (int i = 0; i < top; ++i)
	if (force_check((int64)plist[i]*plist[i]))
	alist[top1++] = (int64)plist[i]*plist[i];
	cerr << top1 << endl;
}


int main()
{
	init();
	cerr << "init ok" << endl;
	int cas = Rint();
	while (cas--)
	{
		int64 A, B;
		scanf("%lld%lld", &A, &B);
		int ans = 0;
		for (int i = 0; i < top1; ++i)
		if (alist[i] >= A && alist[i] <= B) ++ans;
		static int id = 1;
		printf("Case #%d: %d\n", id++, ans);
		//if (id % 10 == 0) printf("%d\n", id);
	}
	return 0;
}
