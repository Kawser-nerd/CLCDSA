#include <stdio.h>
#include <stdlib.h>

#define CHEAT -1
#define BAD -2

int magic(void) {
   int first, second;
   int grid[4][4];
   int * hash = calloc(sizeof(int), 16);
   // First guess
   scanf("%d", &first);
   // First grid
   for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++) {
         scanf("%d", &grid[i][j]);
      }
   }
   // Mark first row of cards
   for(int i = 0; i < 4; i++) {
      hash[grid[first-1][i]] = 1;
   }
   // Second question
   scanf("%d", &second);
   // Second grid
   for(int i = 0; i < 4; i++){
      for(int j = 0; j < 4; j++) {
         scanf("%d", &grid[i][j]);
      }
   }
   // Mark first row of cards
   int count = 0;
   int answer = -1;
   for(int i = 0; i < 4; i++) {
      if(hash[grid[second-1][i]] == 1) {
         answer = grid[second-1][i];
         count++;
      }
   }
   //Determine answer
   if (count == 0) {
      return CHEAT;
   } else if (count == 1) {
      return answer;
   } else {
      return BAD;
   }
}

int main(void) {
   int cases;
   scanf("%d", &cases);
   for (int i = 1; i <= cases; i++) {
      int answer = magic();
      printf("Case #%d: ", i);
      if (answer == CHEAT) {
         printf("Volunteer cheated!\n");
      } else if (answer == BAD) {
         printf("Bad magician!\n");
      } else {
         printf("%d\n", answer);
      }
   }
}
