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

char mat[16][16];

static inline int check_win(int who)
{
	rep(i, 0, 4)
	int point = 0;
	rep(i, 0, 4)
	{
		int point = 0;
		int t = 0;
		rep(j, 0, 4) point += mat[i][j] == who,
		t += mat[i][j] == 'T';
		if (point == 4 || point == 3 && t == 1) return 1;
	}
	rep(i, 0, 4)
	{
		int point = 0;
		int t = 0;
		rep(j, 0, 4) point += mat[j][i] == who,
		t += mat[j][i] == 'T';
		if (point == 4 || point == 3 && t == 1) return 1;
	}
	{
		int point = 0;
		int t = 0;
		rep(j, 0, 4) point += mat[j][j] == who,
		t += mat[j][j] == 'T';
		if (point == 4 || point == 3 && t == 1) return 1;
	}
	{
		int point = 0;
		int t = 0;
		rep(j, 0, 4) point += mat[j][3-j] == who,
		t += mat[j][3-j] == 'T';
		if (point == 4 || point == 3 && t == 1) return 1;
	}
	return 0;
}
int main()
{
	int cas = Rint();
	while (cas--)
	{
		rep(i, 0, 4)
		scanf("%s", mat[i]);
		int point = 0;
		rep(i, 0, 4) rep(j, 0, 4) point += mat[i][j] == '.';
		
		static int id = 1;
		printf("Case #%d: ", id++);
		if (check_win('X')) {puts("X won"); continue;}
		if (check_win('O')) {puts("O won"); continue;}
		puts(point == 0 ? "Draw" : "Game has not completed");
	}
	return 0;
}
