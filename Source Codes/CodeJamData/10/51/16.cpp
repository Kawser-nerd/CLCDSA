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
int T;
int N;
long long MAXNUM;
long long A, P;
long long list[15];
int mark[1000005];
int D;
long long ans;
long long gcd(long long a, long long b) {
   return (b ? gcd(b, a % b) : a);
}
int check(long long a, long long p) {
   long long b;
   int i;
   if (p >= MAXNUM)
      return 0;
   b = (list[1] - list[0] * a) % p;
   if (b < 0)
      b += p;
   if (list[0] >= p)
      return 0;
   for (i = 0; i < N - 1; i ++)
      if ((list[i] * a + b) % p != list[i + 1])
	 return 0;
   long long next = (list[N - 1] * a + b) % p;
   if (ans == -1)
      ans = next;
   if (ans >= 0 && ans != next)
      ans = -2;
   return 0;
}
int check2(long long a) {
   for (long long p = 2; p < MAXNUM && ans != -2; p ++)
      if (mark[p] == 0)
	 check(a, p);
   return 0;
}
int main() {
   int i, j, Case = 1;
   scanf("%d", &T);
   memset(mark, 0, sizeof(mark));
   mark[0] = mark[1] = 1;
   for (i = 2; i * i <= 1000000; i ++)
      if (!mark[i])
	 for (j = i * i; j <= 1000000; j += i)
	    mark[j] = 1;
   while (T --) {
      long long maxnum = 0;
      scanf("%d%d", &D, &N);
      for (i = 0; i < N; i ++) {
	 scanf("%lld", &list[i]);
	 maxnum = max(maxnum, list[i]);
      }
      if (N == 1) {
	 printf("Case #%d: I don't know.\n", Case ++);
	 continue;
      }
      for (i = 0; i < N - 1; i ++)
	 if (list[i] == list[i + 1]) {
	    printf("Case #%d: %lld\n", Case ++, list[i]);
	    break;
	 }
      if (i < N - 1)
	 continue;
      ans = -1;
      MAXNUM = 1;
      for (i = 0; i < D; i ++)
	 MAXNUM *= 10;
      for (A = 0; A < MAXNUM && ans != -2; A ++) {
	 long long g = 0;
	 for (i = 1; i < N - 1; i ++)
	    g = gcd(g, A * (list[i] - list[0]) - (list[i + 1] - list[1]));
	 g = llabs(g);
	 if (g == 0) {
	    check2(A);
	    continue;
	 }
	 for (P = 2; P * P <= g && P < MAXNUM; P ++)
	    if (g % P == 0) {
	       if (P > maxnum)
		  check(A, P);
	       while (g % P == 0)
		  g /= P;
	    }
	 if (g > 1)
	    if (g > maxnum)
	       check(A, g);
      }
      if (ans < 0)
	 printf("Case #%d: I don't know.\n", Case ++);
      else
	 printf("Case #%d: %lld\n", Case ++, ans);
   }
   return 0;
}

