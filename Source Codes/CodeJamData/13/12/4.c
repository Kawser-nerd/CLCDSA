#include <stdio.h>
#include <stdlib.h>

#define TRUE         1
#define FALSE        0

void handleCase();

long long E, R, N;
long long values[10001];

int main () {
   freopen ("b.in", "r", stdin);
   freopen ("b.out", "w", stdout);
   int i;
   int n;
   scanf ("%d ", &n);
   for (i = 0; i < n; i++) {
      printf ("Case #%d: ", i + 1);
      handleCase();
   }
   return 0;
}


long long findMax (long long start, long long end, long long eneStart, long long eneEnd) {
   if (start > end) {
      return 0;
   }
   long long high = -1ll;
   long long i;
   for (i = start; i <= end; i++) {
      if (high == -1ll || values[i] > values[high]) {
         high = i;
      }
   }
   long long maxThen = eneStart + R * (high - start);
   if (maxThen > E) {
      maxThen = E;
   }
   long long recAmo = (end - high) * R;
   long long saveAmo = eneEnd - recAmo;
   if (saveAmo < 0ll) {
      saveAmo = 0ll;
   }
   long long spend = maxThen - saveAmo;
   long long value = spend * values[high];
   //printf ("max for %I64d %I64d, %I64d, %I64d == %I64d --- %I64d - %I64d %I64d - %I64d %I64d\n", start, end, eneStart, eneEnd, high, maxThen, recAmo, saveAmo, spend, value);
   value += findMax (start, high - 1ll, eneStart, maxThen - R);
   value += findMax (high + 1ll, end, saveAmo + R, eneEnd);
   return value;
}


void handleCase() {
   scanf ("%I64d %I64d %I64d ", &E, &R, &N);
   int i;
   for (i = 0; i < N; i++) {
      scanf ("%I64d ", &values[i]);
   }
   printf ("%I64d\n", findMax (0, N - 1, E, 0));
}

