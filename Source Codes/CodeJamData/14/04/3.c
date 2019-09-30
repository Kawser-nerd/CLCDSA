#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

int comp(const double * a,const double * b) {
   if (*a==*b) {
      return 0;
   } else if (*a < *b) {
      return -1;
   } else{
      return 1;
   }
}

void scores(void) {
   int n;
   int war_score = 0, deceit_score = 0;
   scanf("%d", &n);
   double naomi_blocks[1000];
   double ken_blocks[1000];
   for (int i = 0; i < n; i++) {
      scanf("%lf", &naomi_blocks[i]);
   }
   qsort(naomi_blocks, n, sizeof(double), comp);
   for (int i = 0; i < n; i++) {
      scanf("%lf", &ken_blocks[i]);
   }
   qsort(ken_blocks, n, sizeof(double), comp);
   int k_ptr = n-1;
   for (int i = n-1; i >= 0; i--) {
      if (ken_blocks[k_ptr] > naomi_blocks[i]) {
         k_ptr--;
      } else {
         war_score++;
      }
   }
   k_ptr = 0;
   for (int i = 0; i < n; i++) {
      if (ken_blocks[k_ptr] > naomi_blocks[i]) {

      } else {
         k_ptr++;
         deceit_score++;
      }
   }

   printf("%d %d\n", deceit_score, war_score);
}

int main(void) {
   int cases;
   scanf("%d", &cases);
   for (int i = 1; i <= cases; i++) {
      printf("Case #%d: ", i);
      scores();
   }
}
