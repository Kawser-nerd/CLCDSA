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

double p[100004];

int main()
{
  #ifdef __FIO
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  #endif
  int T;
  scanf("%d", &T);
  for(int i0 = 1; i0 <= T; i0++){
    int n, m;
    int i, j;
    double ans;
    scanf("%d%d", &n, &m);
    ans = m+1;
    p[0] = 1.;
    for(i = 1; i <= n; i++){
      scanf("%lf", &p[i]);
      p[i] *= p[i-1];
    }
    for(i = 0; i <= n; i++){
      double t = p[i]*(m-i+n-i) + (1-p[i])*(m-i+n-i+1+m);
      ans = min(ans, t);
    }
    printf("Case #%d: %lf\n", i0, ans+1);
  }
  return 0;
}
