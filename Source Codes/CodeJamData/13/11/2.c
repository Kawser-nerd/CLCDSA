#include <stdio.h>
#include <stdlib.h>

#define TRUE         1
#define FALSE        0

void handleCase();

long long r, t;

int main () {
   freopen ("a.in", "r", stdin);
   freopen ("a.out", "w", stdout);
   int i;
   int n;
   scanf ("%d ", &n);
   for (i = 0; i < n; i++) {
      printf ("Case #%d: ", i + 1);
      handleCase();
   }
   return 0;
}

int canWork (long long amo) {
   if (t / r < amo / 2) {
      return FALSE;
   }
   long long sum = (2 * r + 1ll) * amo + 2ll * (amo - 1ll) * amo;
   return sum <= t;
}

void handleCase() {
   scanf ("%I64d %I64d ", &r, &t);
   long long min = 0ll;
   long long max = (1ll << 30);
   while (min < max) {
      long long mid = (min + max + 1ll) / 2ll;
      if (canWork(mid)) {
         min = mid;
      } else {
         max = mid - 1ll;
      }
   }
   printf ("%I64d\n", min);
}

