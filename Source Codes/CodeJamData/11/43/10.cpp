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
#include <cassert>
#include <complex>
using namespace std;
#define PI 3.14159265358979323846264338327950288
int T;
long long N;
long long primes[1000005];
int tot;
int mark[1000005];
inline int calc(long long n, long long p) {
   int ret = 0;
   while (n >= p) {
      n /= p;
      ret ++;
   }
   return ret;
}
int main() {
   int i, j, Case = 1;
   scanf("%d", &T);
   memset(mark, 0, sizeof(mark));
   tot = 0;
   for (i = 2; i <= 1000; i ++)
      if (!mark[i])
	 for (j = i * i; j <= 1000000; j += i)
	    mark[j] = 1;
   for (i = 2; i <= 1000000; i ++)
      if (!mark[i])
	 primes[tot ++] = i;
   while (T --) {
      scanf("%lld", &N);
      long long ans = 0;
      for (i = 0; i < tot; i ++) {
	 int tmp = calc(N, primes[i]);
	 ans += tmp - 1;
	 if (tmp <= 1)
	    break;
      }
      printf("Case #%d: %lld\n", Case ++, ans + 1);
   }
   return 0;
}

