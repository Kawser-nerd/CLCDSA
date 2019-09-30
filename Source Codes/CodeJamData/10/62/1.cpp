#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cctype>
#include <cmath>

#include <set>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define forab(i, a, b) for (int i = (int)(a); i <= (int)(b); i++)
#define forit(i, a) for (__typeof((a).begin()) i = (a).begin(); i != (a).end(); i++)
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair
#define zero(a) memset(a, 0, sizeof(a))
#define all(a) (a).begin(), (a).end()

#define IS(a, i) (((a) >> (i)) & 1)

int Int( string s ) { int x; stringstream ss(s); ss >> x; return x; }
string Str( int x ) { stringstream ss; ss << x; return ss.str(); }

typedef long long ll;
typedef vector <int> vi;

const int maxn = 1010;

int res;
int n, f1[maxn][maxn], f2[maxn][maxn];
vector <int> next[maxn][maxn];

void relax( int &a, int b )
{
  a = max(a, b);
}

int F( int a, int b )
{
  if (a > b)
    swap(a, b);
  return f1[a][b];
}

void Go( int a, int b )
{
  if (a > b)
    swap(a, b);
	
  f1[a][b] = 1, f2[a][b] = 0;
  forn(i, sz(next[a][b]))
  {
    int c = next[a][b][i];
	Go(a, c), Go(c, b);
	
	int len = F(a, c) + F(c, b);
//	printf("a=%d b=%d -----------------> c=%d len=%d\n", a, b, c, len);
	if (len >= f1[a][b])
	  f2[a][b] = f1[a][b], f1[a][b] = len;
	else if (len >= f2[a][b])
	  f2[a][b] = len;
  }
  if (f2[a][b])
    relax(res, f1[a][b] + f2[a][b]);
//printf("a=%d b=%d : f1=%d f2=%d\n", a, b, f1[a][b], f2[a][b]);
}

int main() 
{
  int tn;
  scanf("%d", &tn);
  
  forab(tt, 1, tn)
  {
    scanf("%d", &n);
	forn(i, n)
	  forn(j, n)
		next[i][j].clear();
	forab(i, 4, n)
	{
	  int a, b;
	  scanf("%d%d", &a, &b);
	  if (a > b)
	    swap(a, b);
	  a--, b--;
	  
	  next[a][b].pb(i - 1);
	}
	
	res = 0;
	Go(1, 2), Go(2, 0), Go(1, 0);
	relax(res, F(1, 2) + F(2, 0) + F(1, 0));
	printf("Case #%d: %d\n", tt, res);
  }
  return 0;
}
