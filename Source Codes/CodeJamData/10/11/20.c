// Luke Harrison
// 22/05/10

#include <stdio.h>
#include <stdlib.h>

#define TRUE         1
#define FALSE        0

char curGrid[50][50];
int size, amount;

void handleCase (FILE *input, FILE* output);

int dx[] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[] = {1, -1, 0, 1, -1, 0, 1, -1};

int doesWin (int y, int x, int dir);

int main () {
   FILE* input = fopen ("input.txt", "r");
   FILE* output = fopen ("output.txt", "w");
   int i;
   int numCases;
   fscanf (input, "%d ", &numCases);
   for (i = 0; i < numCases; i++) {
      fprintf (output, "Case #%d: ", i + 1);
      handleCase (input, output);
   }
   
   
   
   fclose (input);
   fclose (output);
   return 0;
}

void handleCase (FILE *input, FILE* output) {
   fscanf (input, "%d %d ", &size, &amount);
   int i, j;
   for (i = 1; i <= size; i++) {
      for (j = 0; j < size; j++) {
         fscanf (input, "%c ", &(curGrid[j][size - i]));
      }
   }
   // Its now in its correct orienatation
   // Now simulate gravity
   int k;
   int cont;
   for (i = size - 2; i >= 0; i--) { // Each row. Not starting at bottom
      for (j = 0; j < size; j++) {
         k = i;
         cont = TRUE;
         while (k < size - 1 && cont) {
            cont = FALSE;
            if (curGrid[k + 1][j] == '.') {
               cont = TRUE;
               curGrid[k + 1][j] = curGrid[k][j];
               curGrid[k][j] = '.';
               k++;
            }
         }
      }
   }
   // Now check who wins;
   int blueWins = FALSE;
   int redWins = FALSE;
   for (i = 0; i < size; i++) {
      for (j = 0; j < size; j++) {
         if (curGrid[i][j] == 'B' && !blueWins) {
            for (k = 0; k < 8 && !blueWins; k++) {
               if (doesWin (i, j, k)) {
                  blueWins = TRUE;
               }
            }
         } else if (curGrid[i][j] == 'R' && !redWins) {
            for (k = 0; k < 8 && !redWins; k++) {
               if (doesWin (i, j, k)) {
                  redWins = TRUE;
               }
            }
         }
      }
   }
   
   if (redWins && blueWins) {
      fprintf (output, "Both\n");
   } else if (redWins) {
      fprintf (output, "Red\n");
   } else if (blueWins) {
      fprintf (output, "Blue\n");
   } else {
      fprintf (output, "Neither\n");
   }
}


int doesWin (int y, int x, int dir) {
   char curPlayer = curGrid[y][x];
   int doesMatch = TRUE;
   int numMatched = 1;
   while (doesMatch && numMatched < amount) {
      y += dy[dir];
      x += dx[dir];
      if (y < 0 || x < 0 || y >= size || x >= size) {
         doesMatch = FALSE;
      } else {
         if (curGrid[y][x] != curPlayer) {
            doesMatch = FALSE;
         };
      }
      numMatched++;
   }
   return doesMatch;
}

