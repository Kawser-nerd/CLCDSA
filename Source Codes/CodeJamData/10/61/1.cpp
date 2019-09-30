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
#define pb push_back
#define mp make_pair
#define zero(a) memset(a, 0, sizeof(a))
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef vector <int> vi;

const int maxn = 103;

int n, f[maxn][maxn];
char s[maxn];

inline void relax( int &a, int b )
{
  a = min(a, b);
}

int Go( int l, int r )
{
  if (l >= r)
    return 0;
  int &res = f[l][r];	
  if (res != -1)
    return res;
  res = 1 + Go(l + 1, r);
  for (int i = l + 1; i < r; i++)
    if (s[i] == s[l])
	  relax(res, Go(l + 1, i) + Go(i, r));
  return res;
}

int main() 
{
  int tn;
  scanf("%d", &tn);
  forab (tt, 1, tn)
  {
    scanf("%s", s);
	
	n = strlen(s);
	memset(f, -1, sizeof(f));
	printf("Case #%d: %d\n", tt, Go(0, n) * 2 + n);
  }
  return 0;
}
