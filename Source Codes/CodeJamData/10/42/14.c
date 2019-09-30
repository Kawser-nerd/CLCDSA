// Luke Harrison
// 06/06/10

#include <stdio.h>
#include <stdlib.h>

#define TRUE               1
#define FALSE              0

#define MAX                1000000000

int numRounds;

void handleCase (FILE *input, FILE *output);

int howManyCanMiss[5000];

int costs[5000];

int updateTree (int toUpdate, int value, int nodeStart, int nodeEnd, int place);

int findCost (int currentMinus, int nodeStart, int nodeEnd, int place);

int min (int n1, int n2);
int max (int n1, int n2);


int main () {
   FILE *input = fopen ("input.txt", "r");
   FILE *output = fopen ("output.txt", "w");
   int i;
   int numCases;
   fscanf (input, "%d ", &numCases);
   for (i = 1; i <= numCases; i++) {
      fprintf (output, "Case #%d: ", i);
      handleCase (input, output);
      //printf ("\n");
   }
   return 0;
}


void handleCase (FILE *input, FILE *output) {
   int i, j;
   fscanf (input, "%d ", &numRounds);
   
   for (i = 0; i < 5000; i++) {
      howManyCanMiss[i] = MAX;
   }
   
   int upTo = 1 << (numRounds);
   int value;
   for (i = 0; i < upTo; i++) {
      fscanf (input, "%d ", &value);
      updateTree (i, value, 0, upTo - 1, 1);
   }
   int cost;
   for (i = 0; i < numRounds; i++) {
      upTo = 1 << (numRounds - i - 1);
      for (j = 0; j < upTo; j++) {
         fscanf (input, "%d ", &cost);
         costs[upTo + j] = cost;
      }
   }
   upTo = 1 << (numRounds);
   fprintf (output, "%d\n", findCost (0, 0, upTo - 1, 1));
   
}



int updateTree (int toUpdate, int value, int nodeStart, int nodeEnd, int place) {
   if (nodeStart == nodeEnd) {
      howManyCanMiss[place] = value;
      return value;
   }
   int midPoint = (nodeStart + nodeEnd) / 2;
   int minLeft;
   int minRight;
   if (toUpdate <= midPoint) {
      minLeft = updateTree (toUpdate, value, nodeStart, midPoint, place * 2);
   } else {
      minLeft = howManyCanMiss[place * 2];
   }
   if (toUpdate > midPoint) {
      minRight = updateTree (toUpdate, value, midPoint + 1, nodeEnd, (place * 2) + 1);
   } else {
      minRight = howManyCanMiss[(place * 2) + 1];
   }
   howManyCanMiss[place] = min (minLeft, minRight);
   return howManyCanMiss[place];
}



int min (int n1, int n2) {
   if (n1 < n2) {
      return n1;
   } else {
      return n2;
   }
}


int max (int n1, int n2) {
   if (n1 > n2) {
      return n1;
   } else {
      return n2;
   }
}




int findCost (int currentMinus, int nodeStart, int nodeEnd, int place) {
   //printf ("Checking %d %d %d %d %d\n", currentMinus, nodeStart, nodeEnd, place, howManyCanMiss[place]);
   int totalCost = 0;
   int bestCost = 0;
   int midPoint = (nodeStart + nodeEnd) / 2;
   if (nodeStart == nodeEnd) {
      return 0;
   }
   if (howManyCanMiss[place] + currentMinus > 0) {
      //printf ("Need %d %d\n", place, costs[place]);
      totalCost += findCost (currentMinus - 1, nodeStart, midPoint, place * 2);
      totalCost += findCost (currentMinus - 1, midPoint + 1, nodeEnd, (place * 2) + 1);
      bestCost = totalCost;
   } else {
      bestCost = -1;
   }
   totalCost = 0;
   totalCost += findCost (currentMinus, nodeStart, midPoint, place * 2);
   totalCost += findCost (currentMinus, midPoint + 1, nodeEnd, (place * 2) + 1);
   totalCost += costs[place];
   if (bestCost == -1) {
      bestCost = totalCost;
   } else {
      bestCost = min (bestCost, totalCost);
   }
   return bestCost;
}
