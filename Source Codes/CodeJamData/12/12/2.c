#include <stdio.h>
#include <stdlib.h>


#define TRUE            1
#define FALSE           0

void handlecase ();

int N;
int nums[1001][2];
int isDone[1001][2];

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
   scanf ("%d ", &N);
   int i;
   for (i = 0; i < N; i++) {
      scanf ("%d %d ", &nums[i][0], &nums[i][1]);
      isDone[i][0] = FALSE;
      isDone[i][1] = FALSE;
   }
   int count = 0;
   int allDone = FALSE;
   int best = 0;
   int bestNum = 0;
   int stars = 0;
   while (!allDone && best != -1) {
      allDone = TRUE;
      best = -1;
      bestNum = -1;
      for (i = 0; i < N; i++) {
         if (!isDone[i][1]) {
            allDone = FALSE;
            if (nums[i][1] <= stars) { // Pick any level 2
               best = i;
               bestNum = 1;
            }
         }
         if (!isDone[i][0]) {
            if (nums[i][0] <= stars) { // Could pick level 1
               if (bestNum != 1) { // We haven't picked a level two
                  if (best == -1 || nums[i][1] > nums[best][1]) {
                     best = i;
                     bestNum = 0;
                  }
               }
            }
         }
      }
      if (best != -1) {
         if (bestNum == 1) {
            if (!isDone[best][0]) {
               isDone[best][0] = TRUE;
               stars++;
            }
            isDone[best][1] = TRUE;
            stars++;
         } else {
            isDone[best][0] = TRUE;
            stars++;
         }
         count++;
      }
   }
   if (!allDone) {
      printf ("Too Bad\n");
   } else {
      printf ("%d\n", count);
   }
}
