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

pair<int, int> a[1004];
int vis[1004];

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int T;
  scanf("%d", &T);
  for(int i0 = 1; i0 <= T; i0++){
    int n;
    int i, j;
    int ans = 0;
    int s = 0;
    scanf("%d", &n);
    memset(vis, 0, sizeof vis);
    for(i = 0; i < n; i++){
      scanf("%d%d", &a[i].se, &a[i].fi);
    }
    sort(a, a+n);
    i = 0;
    while(i < n){
      if(s >= a[i].fi){
        if(vis[i] < 2){
          ans++;
          s += 2-vis[i];
          vis[i] = 2;
        }
        i++;
      }
      else{
        for(j = n-1; j >= 0 && (vis[j] || a[j].se > s); j--);
        if(j < 0)
          break;
        ans++;
        vis[j]++;
        s++;
      }
    }
    printf("Case #%d: ", i0);
    if(i < n)
      printf("Too Bad\n");
    else
      printf("%d\n", ans);
  }
  return 0;
}
