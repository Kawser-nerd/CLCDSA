#include <stdio.h>
#include <stdlib.h>

#define TRUE         1
#define FALSE        0

void handleCase();

int R, N, M, K;

int cache[6][6][6][126];

double chance[126][6][6][6];

int main () {
   freopen ("c.in", "r", stdin);
   freopen ("c.out", "w", stdout);
   int i;
   int n;
   scanf ("%d ", &n);
   for (i = 0; i < n; i++) {
      printf ("Case #%d: ", i + 1);
      handleCase();
   }
   return 0;
}

void addToCache(int *ar) {
   int i;
   for (i = 0; i < 8; i++) {
      int pro = 1;
      int j;
      for (j = 0; j < 3; j++) {
         if (i & (1 << j)) {
            pro *= ar[j];
         }
      }
      cache[ar[0]][ar[1]][ar[2]][pro]++;
   }
}

int findNumber(int *pro) {
   int i, j, k, l;
   double best = 0.0;
   int num = 222;
   for (i = 2; i <= 5; i++) {
      for (j = i; j <= 5; j++) {
         for (k = j; k <= 5; k++) {
            double probFor = 1.0;
            for (l = 0; l < 7; l++) {
               probFor *= chance[pro[l]][i][j][k];
            }
            if (probFor > best) {
               best = probFor;
               num = i * 100 + j * 10 + k;
            }
         }
      }
   }
   return num;
}

void handleCase() {
   scanf ("%d %d %d %d ", &R, &N, &M, &K);
   
   int i, j, k, l;
   for (i = 2; i <= 5; i++) {
      for (j = i; j <= 5; j++) {
         for (k = j; k <= 5; k++) {
            int ar[3];
            ar[0] = i;
            ar[1] = j;
            ar[2] = k;
            addToCache (ar);
         }
      }
   }
   for (l = 0; l <= 125; l++) {
      int count = 0;
      for (i = 2; i <= 5; i++) {
         for (j = i; j <= 5; j++) {
            for (k = j; k <= 5; k++) {
               count += cache[i][j][k][l];
            }
         }
      }
      if (count > 0) {
         for (i = 2; i <= 5; i++) {
            for (j = i; j <= 5; j++) {
               for (k = j; k <= 5; k++) {
                  chance[l][i][j][k] = (double) cache[i][j][k][l] / (double) count;
               }
            }
         }
      }
   }
   printf ("\n");
   int sums[7];
   for (i = 0; i < R; i++) {
      for (j = 0; j < 7; j++) {
         scanf ("%d ", &sums[j]);
      }
      printf ("%d\n", findNumber (sums));
   }
}

