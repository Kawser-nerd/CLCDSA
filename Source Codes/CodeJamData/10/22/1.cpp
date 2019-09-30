#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;
#define PI 3.14159265358979323846264338327950288
long long B, T, K, N;
int C;
long long init[55], speed[55];
int pos[55];
int main() {
   int i, j, Case = 1;
   scanf("%d", &C);
   while (C --) {
      scanf("%lld%lld%lld%lld", &N, &K, &B, &T);
      for (i = 0; i < N; i ++)
	 scanf("%lld", &init[i]);
      for (i = 0; i < N; i ++)
	 scanf("%lld", &speed[i]);
      for (i = 0; i < N; i ++)
	 if (init[i] + speed[i] * T >= B)
	    pos[i] = 1;
	 else
	    pos[i] = 0;
      long long ans = 0;
      long long left = K, cnt = 0;
      for (i = N - 1; i >= 0 && left; i --)
	 if (pos[i]) {
	    ans += cnt;
	    left --;
	 }
	 else
	    cnt ++;
      if (left)
	 printf("Case #%d: IMPOSSIBLE\n", Case ++);
      else
	 printf("Case #%d: %lld\n", Case ++, ans);
   }
   return 0;
}

