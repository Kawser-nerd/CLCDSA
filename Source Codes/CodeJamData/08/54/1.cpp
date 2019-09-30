#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cmath>
using namespace std;
#define PI 3.14159265358979323846264338327950288
#define MOD 10007
int T;
long long N, M;
int R;
long long forbid[15][2];
long long inv[MOD + 10];
long long prod[MOD + 10];
long long CONST[105][105];
int cmp(const void *a, const void *b) {
   return (*(long long *)a > *(long long *)b ? 1 : -1);
}
long long calc2(long long x) {
   long long ret = 0;
   while (x) {
      ret += x / MOD;
      x /= MOD;
   }
   return ret;
}
long long calc4(long long x, long long b) {
   long long t;
   if (!b)
      return 1;
   t = calc4(x, b / 2);
   if (b % 2)
      return t * t % MOD * x % MOD;
   return t * t % MOD;
}
long long calc3(long long x) {
   long long ret = 1;
   if (x == 0)
      return 1;
   ret *= calc4(prod[MOD - 1], x / MOD);
   ret *= prod[x % MOD];
   ret %= MOD;
   ret *= calc3(x / MOD);
   ret %= MOD;
   return ret;
}
long long calc(long long a, long long b) {
   long long x, y;
   x = (2 * b - a) / 3;
   y = (2 * a - b) / 3;
   if (x + 2 * y != a || y + 2 * x != b || x < 0 || y < 0)
      return 0;
   long long all = 0;
   all += calc2(x + y) - calc2(x) - calc2(y);
   if (all > 0)
      return 0;
   long long ret1, ret2, ret3;
/*   return CONST[x + y][x];*/
   ret1 = calc3(x + y);
   ret2 = calc3(x);
   ret3 = calc3(y);
   ret1 = ret1 * inv[ret2] % MOD;
   ret1 = ret1 * inv[ret3] % MOD;
   return ret1;
}
long long solve(int x) {
   long long list[15][2];
   int s = 2;
   int i, j;
   list[0][0] = 1;
   list[0][1] = 1;
   list[1][0] = N;
   list[1][1] = M;
   for (i = 0; i < R; i ++)
      if (x & (1 << i)) {
	 list[s][0] = forbid[i][0];
	 list[s ++][1] = forbid[i][1];
      }
   qsort(list, s, sizeof(long long) * 2, cmp);
   for (i = 0; i < s - 1; i ++)
      if (list[i][1] > list[i + 1][1])
	 return 0;
   long long ret = 1;
   for (i = 0; i < s - 1; i ++)
      ret = ret * calc(list[i + 1][0] - list[i][0], list[i + 1][1] - list[i][1]) % MOD;
   return ret;
}
int Count(int x) {
   int i;
   int ret = 1;
   for (i = 0; i < R; i ++)
      if (x & (1 << i))
	 ret = -ret;
   return ret;
}
int main() {
   int i, Case = 1, j;
   prod[0] = 1;
   for (i = 1; i < MOD; i ++)
      prod[i] = prod[i - 1] * i % MOD;
   for (i = 1; i < MOD; i ++)
      for (j = 1; j < MOD; j ++)
	 if (i * j % MOD == 1) {
	    inv[i] = j;
	    break;
	 }
   for (i = 0; i <= 100; i ++)
      for (j = 0; j <= i; j ++)
	 if (j == 0 || j == i)
	    CONST[i][j] = 1;
	 else
	    CONST[i][j] = (CONST[i - 1][j] + CONST[i - 1][j - 1]) % MOD;
   scanf("%d", &T);
   while (T --) {
      scanf("%lld%lld%d", &N, &M, &R);
      for (i = 0; i < R; i ++)
	 scanf("%lld%lld", &forbid[i][0], &forbid[i][1]);
      long long ret = 0;
      for (i = 0; i < (1 << R); i ++)
	 ret += Count(i) * solve(i);
      ret %= MOD;
      ret += MOD;
      ret %= MOD;
      printf("Case #%d: %lld\n", Case ++, ret);
   }
   return 0;
}

