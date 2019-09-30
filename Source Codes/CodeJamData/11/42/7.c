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

char buff[512][512];
int64 mat[512][512];
int64 tree[512][512];
int64 treex[512][512];
int64 treey[512][512];

void update(int64 tree[512][512], int x, int y, int v, int r, int c)
{
	for (; x <= r; x += x & -x)
	for (int yy = y; yy <= c; yy += yy & -yy)
	tree[x][yy] += v;
}

int64 query(int64 tree[512][512], int x, int y)
{
	int64 ret = 0;
	for (; x; x -= x & -x)
	for (int yy = y; yy; yy -= yy & -yy) ret += tree[x][yy];
	return ret;
}
int64 query(int64 tree[512][512], int x1, int y1, int x2, int y2)
{
	int64 ans = query(tree, x2, y2);
	ans += query(tree, x1-1, y1-1);
	ans -= query(tree, x2, y1-1);
	ans -= query(tree, x1-1, y2);
	return ans;
}
int main()
{
	int T = Rint();
	for (int caseID = 1; caseID <= T; ++caseID)
	{
		int r, c, d;
		memset(tree, 0, sizeof tree);
		memset(treex, 0, sizeof treex);
		memset(treey, 0, sizeof treey);
		scanf("%d%d%d", &r, &c, &d);
		rep(i, 1, r+1) scanf("%s", buff[i]);
		rep(i, 1, r+1) rep(j, 1, c+1) mat[i][j] = buff[i][j-1] - 48;
		rep(i, 1, r+1) rep(j, 1, c+1)
		{
			update(treex, i, j, mat[i][j]*i, r, c);
			update(treey, i, j, mat[i][j]*j, r, c);
			update(tree, i, j, mat[i][j], r, c);
		}
		int ans = min(r, c);
		for (; ans >= 3; --ans)
		{
			int k = ans;
			rep(i, 1, r+1) rep(j, 1, c+1)
			if (i + k - 1 <= r) if (j + ans - 1 <= c)
			{
				int64 totx = query(treex, i, j, i + k - 1, j + k - 1);
				int64 toty = query(treey, i, j, i + k - 1, j + k - 1);
				int64 weight = query(tree, i, j, i + k - 1, j + k - 1);
				totx -= mat[i][j] * i;
				toty -= mat[i][j] * j;
				weight -= mat[i][j];
				
				totx -= mat[i][j+k-1] * i;
				toty -= mat[i][j+k-1] * (j+k-1);
				weight -= mat[i][j+k-1];
				
				totx -= mat[i+k-1][j] * (i+k-1);
				toty -= mat[i+k-1][j] * j;
				weight -= mat[i+k-1][j];
				
				totx -= mat[i+k-1][j+k-1] * (i+k-1);
				toty -= mat[i+k-1][j+k-1] * (j+k-1);
				weight -= mat[i+k-1][j+k-1];
				if (weight == 0) goto ok;
				if (k % 2 == 1)
				{
					int64 x = (i + i + k - 1) >> 1;
					int64 y = (j + j + k - 1) >> 1;
					if (totx % weight == 0 && toty % weight == 0 && totx / weight == x && toty / weight == y)
					{
						goto ok;
					}
				}
				else
				{
					int64 x = i + i + k - 1;
					int64 y = j + j + k - 1;
					if (totx * 2 % weight == 0 && toty * 2 %  weight == 0 && (totx * 2) / weight == x && (toty * 2) / weight == y)
					{
						goto ok;
					}
				}
			}
			
			
		}
		ok:;
		if (ans < 3) printf("Case #%d: IMPOSSIBLE\n", caseID);
		else printf("Case #%d: %d\n", caseID, ans);
	}
	return 0;
}
