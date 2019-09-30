// Luke Harrison
// 6/5/11

#include <stdio.h>
#include <stdlib.h>


#define TRUE         1
#define FALSE        0

int badEvoke[30][30];
int formsPair[30][30];
int numEles;
int elemList[1000];

void handleCase (void);



int main () {
   freopen ("magika.in", "r", stdin);
   freopen ("magika.out", "w", stdout);
   int numCases;
   scanf ("%d ", &numCases);
   int i;
   for (i = 0; i < numCases; i++) {
      printf ("Case #%d: ", i + 1);
      handleCase ();
   }
   return 0;
}

void handleCase (void) {
   int i, j;
   for (i = 0; i < 30; i++) {
      for (j = 0; j < 30; j++) {
         badEvoke[i][j] = FALSE;
         formsPair[i][j] = -1;
      }
   }
   int numPairs;
   char pair[40];
   scanf ("%d ", &numPairs);
   for (i = 0; i < numPairs; i++) {
      scanf ("%s ", &pair[0]);
      formsPair[pair[0] - 'A'][pair[1] - 'A'] = pair[2] - 'A';
      formsPair[pair[1] - 'A'][pair[0] - 'A'] = pair[2] - 'A';
   }
   int numDes;
   char des[30];
   scanf ("%d ", &numDes);
   for (i = 0; i < numDes; i++) {
      scanf ("%s ", &des[0]);
      badEvoke[des[0] - 'A'][des[1] - 'A'] = TRUE;
      badEvoke[des[1] - 'A'][des[0] - 'A'] = TRUE;
   }
   numEles = 0;
   int size;
   scanf ("%d ", &size);
   char cur;
   for (i = 0; i < size; i++) {
      scanf ("%c ", &cur);
      elemList[numEles] = cur - 'A';
      numEles++;
      while (numEles > 1 && formsPair[elemList[numEles - 1]][elemList[numEles - 2]] != -1) {
         elemList[numEles - 2] = formsPair[elemList[numEles - 1]][elemList[numEles - 2]];
         numEles--;
      }
      for (j = 0; j < numEles; j++) {
         if (badEvoke[elemList[j]][elemList[numEles - 1]]) {
            numEles = 0;
         }
      }
   }
   printf ("[");
   for (i = 0; i < numEles - 1; i++) {
      printf ("%c, ", elemList[i] + 'A');
   }
   if (numEles > 0) {
      printf ("%c", elemList[i] + 'A');
   }
   printf ("]\n");
}

