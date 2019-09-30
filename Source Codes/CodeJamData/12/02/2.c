#include <stdio.h>
#include <stdlib.h>

// Output 0 if no way this guy can get >= bound;
// Output 1 if this guy can get >= bound via surprise;
// Else output 2.
/*
k, k, k   -> 3k
k, k, k+1 -> 3k+1
k, k+1, k+1 -> 3k+2

k, k, k+2 -> 3k+2, only works for scores >= 2 && <= 28
k, k+1, k+2 -> 3k+3
k, k+2, k+2 -> 3k+4
*/ 

int check_bound(int score, int bound) {
   if ((score+2)/3 >= bound) return 2;
   else if (score >= 2 && score <= 28 && (score+4)/3 >= bound) return 1;
   else return 0;
}

// Main

int main() {
   int num_cases, num_scores, num_surp, bound, i, score, j, k;

   scanf("%d", &num_cases);

   for(i=0; i<num_cases; i++) {
      int potential=0, num=0;

      scanf("%d %d %d", &num_scores, &num_surp, &bound);

      for(j=0; j<num_scores; j++) {
         scanf("%d", &score);
         k = check_bound(score, bound);
         if (k==2) num++;
         else if (k==1) potential++;
      }

      if (potential > num_surp) potential = num_surp;
      printf("Case #%d: %d\n", i+1, num+potential);
   }

   return 0;
}
