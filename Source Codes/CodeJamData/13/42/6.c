#include <stdio.h>
#include <stdlib.h>

#define TRUE         1
#define FALSE        0

long long N;
long long P;
long long amo;

void handlecase();

int main() {
   freopen ("b.in", "r", stdin);
   freopen ("b.out", "w", stdout);
   int n;
   scanf ("%d ", &n);
   int i;
   for (i = 0; i < n; i++) {
      printf ("Case #%d: ", i + 1);
      handlecase();
   }
   return 0;
}

long long getBest (long long c) {
   long long i;
   long long place = amo - 1ll;
   for (i = 1ll; i <= N; i++) {
      if ((c + (1ll << i) - 1ll) >= amo) {
         return place;
      }
      place -= 1ll << (N - i);
   }
   return place;
}

long long getWorst (long long c) {
   long long i;
   long long place = 0ll;
   for (i = 1ll; i <= N; i++) {
      if (c < (1ll << i) - 1ll) {
         return place;
      }
      place += 1ll << (N - i);
   }
   return place;
}

void handlecase() {
   scanf ("%I64d %I64d ", &N, &P);
   amo = 1ll << N;
   long long min = 0ll;
   long long max = amo - 1ll;
   while (min < max) {
      long long mid = (min + max + 1ll) / 2ll;
      if (getBest (mid) < P) {
         min = mid;
      } else {
         max = mid - 1ll;
      }
   }
   long long b = min;
   min = 0ll;
   max = amo - 1ll;
   while (min < max) {
      long long mid = (min + max + 1ll) / 2ll;
      if (getWorst (mid) < P) {
         min = mid;
      } else {
         max = mid - 1ll;
      }
   }
   printf ("%I64d %I64d\n", min, b);
}

