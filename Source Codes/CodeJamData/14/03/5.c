#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#define true 1
#define false 0

int min(int a, int b){
   if (a<b) {
      return a;
   }
   return b;
}


void grid() {
   int C, R, M;
   scanf("%d%d%d", &R, &C, &M);
   //printf("%d x %d, %d\n", R, C, M);
   int total = R*C;
   int dots = total - M;
   if (dots == 0) {
      // Mines are EVERYWHERE!
      printf("Impossible\n");
   } else if (M == 0) {
      // No mine case
      for (int i = 0; i < R; i++) {
         for (int j = 0; j < C; j++) {
            if (i==0 && j == 0) {
               printf("c");
            } else {
               printf(".");
            }
         }
         printf("\n");
      }
   } else if (dots == 1) {
      // All but 1 square is mines
      for (int i = 0; i < R; i++) {
         for (int j = 0; j < C; j++) {
            if (i==0 && j == 0) {
               printf("c");
            } else {
               printf("*");
            }
         }
         printf("\n");
      }
   } else if (R == 1 || C == 1) {
      // 1d case (boring)
      for (int i = 0; i < R; i++) {
         for (int j = 0; j < C; j++) {
            if (dots > 0) {
               dots--;
               if (i==0 && j == 0) {
                  printf("c");
               } else {
                  printf(".");
               }
            } else {
               printf("*");
            }
         }
         printf("\n");
      }
   } else if (dots >= 4) {
      dots -= 4;
      int m = 0;
      int n = 0;
      int m_max = min(dots/2, C-2);
      int n_max = min(dots/2, R-2);
      int sum_max = min(m_max+n_max, dots/2);
      int m_min = (int)ceil((double)(dots - 2* n_max)/(2+n_max));
      int n_min = (int)ceil((double)(dots - 2* m_max)/(2+m_max));
      //printf("Trying n from %d to %d, m from %d to %d, sum_max %d\n", n_min, n_max, m_min, m_max, sum_max);
      if (m_min > m_max || n_min > n_max) {
         printf("Impossible\n");
         return;
      } else {
         for (m = m_min; m <= m_max; m++) {
            for (n = n_min; n <= n_max; n++) {
               if (dots <= 2*m+2*n + m*n &&
                     dots >= 2*m+2*n) {
                  int square = dots - 2*m -2*n;
                  for (int i = 0; i < R; i++) {
                     for (int j = 0; j < C; j++) {
                        if (i==0 && j == 0) {
                           printf("c");
                        } else if ((i < 2 && j < m+2)||(j < 2 && i< n+2)) {
                           printf(".");
                        } else if (square > 0 && (i< 2+n && j< m+2)) {
                           printf(".");
                           square--;
                        } else {
                           printf("*");
                        }
                     }
                     printf("\n");
                  }
                  return;
               }
            }
         }
      }
      printf("Impossible\n");
   } else {
      printf("Impossible\n");

   }
}




int main(void) {
   int cases;
   scanf("%d", &cases);
   for (int i = 1; i <= cases; i++) {
      printf("Case #%d:\n", i);
      grid();
   }
}
