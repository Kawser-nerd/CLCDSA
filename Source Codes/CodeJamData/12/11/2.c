#include <stdio.h>
#include <stdlib.h>


#define TRUE            1
#define FALSE           0

void handlecase ();


int A, B;
double freq[100001];
double comFreq[100001];


int main () {
   freopen ("in.txt", "r", stdin);
   freopen ("out.txt", "w", stdout);
   int n;
   int i;
   scanf ("%d ", &n);
   for (i = 0; i < n; i++) {
      printf ("Case #%d: ", i + 1);
      handlecase ();
   }
   return 0;
}


void handlecase () {
   scanf ("%d %d", &A, &B);
   comFreq[0] = 1.0;
   int i;
   for (i = 0; i < A; i++) {
      scanf ("%lf ", &freq[i]);
      comFreq[i + 1] = comFreq[i] * freq[i];
   }
   double bestExp = 100000000.0;
   for (i = A; i > 0; i--) {
      double exp = (double) ((B - A) + (2 * (A - i)) + 1) + ((double) (B + 1)) * (1.0 - comFreq[i]);
      if (exp < bestExp) {
         bestExp = exp;
      }
   }
   if ((double) B + 2 < bestExp) {
      bestExp = B + 2;
   }
   printf ("%lf\n", bestExp);
}
