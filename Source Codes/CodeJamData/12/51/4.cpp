#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)
const int MAXN = 1004;

pair<pair<int, int>, int> a[MAXN];

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int T;
  scanf("%d", &T);
  for(int i0 = 0; i0 < T; i0++){
    printf("Case #%d: ", i0+1);
    int n;
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
      scanf("%d", &a[i].fi.fi);
      a[i].se = i;
    }
    for(i = 0; i < n; i++){
      scanf("%d", &a[i].fi.se);
      a[i].fi.se = 100-a[i].fi.se;
    }
    for(i = 0; i < n; i++){
      for(j = 1; j < n; j++){
        if(a[j-1].fi.fi*100+a[j].fi.fi*a[j-1].fi.se > a[j].fi.fi*100+a[j-1].fi.fi*a[j].fi.se)
          swap(a[j], a[j-1]);
      }
    }
    for(i = 0; i < n; i++)
      printf("%d ", a[i].se);
    printf("\n");
  }
  return 0;
}
