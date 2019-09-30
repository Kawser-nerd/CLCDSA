#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#include <string.h>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define forn(i, n) for (int i=0; i<(n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it=(a).begin(); it!=(a).end(); ++it)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;

const int maxn = 105;

char a[maxn][maxn];
int n, m;

int main()
{
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
  
  int tc; scanf("%d", &tc);
  for (int tt=1; tt<=tc; ++tt)
  {
    scanf("%d %d", &n, &m); gets(a[0]);
    forn (i, n) gets(a[i]);
    forn (i, n-1) forn (j, m-1)
      if (a[i][j]=='#' && a[i+1][j]=='#'&&a[i][j+1]=='#'&&a[i+1][j+1]=='#')
        a[i][j] = '/', a[i+1][j] = '\\', a[i][j+1] = '\\', a[i+1][j+1] = '/';
    int ok = 1;
    forn (i, n) forn (j, m) if (a[i][j]=='#') ok = 0;
    printf("Case #%d:\n", tt);
    if (ok) forn (i, n) puts(a[i]);
    else puts("Impossible");

    
  }
  
  return 0;
}
