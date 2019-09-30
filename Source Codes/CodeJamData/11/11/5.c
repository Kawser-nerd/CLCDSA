// Luke Harrison
// 21/5/11


#include <stdio.h>
#include <stdlib.h>


#define TRUE         1
#define FALSE        0

int minForCase[110][110];


int findMin (int a, int b, int c);
void cache (void);
void handleCase (void);
int gcd (int a, int b);

int main () {
   freopen ("input.txt", "r", stdin);
   freopen ("output.txt", "w", stdout);
   int numT;
   scanf ("%d ", &numT);
   int i;
   for (i = 0; i < numT; i++) {
      printf ("Case #%d: ", i + 1);
      handleCase ();
   }
   return 0;
}


void cache (void) {
   int i, j;
   for (i = 0; i <= 100; i++) {
      for (j = 0; j <= 100; j++) {
         minForCase[i][j] = findMin (j, 100 - j, i - j);
      }
   }
}


int findMin (int a, int b, int c) {
   int i, j;
   int min = 100000;
   if (c == 0) {
      return a / (gcd (100, a));
   }
   for (i = 0; i <= 300; i++) {
      for (j = 0; j <= 300; j++) {
         if ((a * i - b * j) % c == 0) {
            if ((a * i - b * j) / c < min && (a * i - b * j) / c > 0) {
               min = (a * i - b * j) / c;
            }
         }
      }
   }
   return min;
}

void handleCase (void) {
   long long N;
   int D, G;
   scanf ("%I64d %d %d ", &N, &D, &G);
   
   int a = 100 / gcd (100, D);
   if ((G == 0 && D != 0) || (G == 100 && D != 100) || ((long long) a > N)) {
      printf ("Broken\n");
   } else {
      printf ("Possible\n");
   }
}

int gcd (int a, int b) {
   if (b == 0) {
      return a;
   }
   return gcd (b, a % b);
}


