// Luke Harrison
// 12/6/11

#include <stdio.h>
#include <stdlib.h>

#define TRUE            1
#define FALSE           0

int numCards;
int cards[1001];

int numCh;
int chains[1001][2];

void sort (int start, int finish);

void handleCase (void);

int works (int amo);

int main () {
   freopen ("input.txt", "r", stdin);
   freopen ("output.txt", "w", stdout);
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
   scanf ("%d ", &numCards);
   int i;
   for (i = 0; i < numCards; i++) {
      scanf ("%d ", &cards[i]);
   }
   sort (0, numCards - 1);
   int min = 0;
   int max = numCards;
   int mid = (min + max) / 2;
   while (min < max) {
      if (works (mid)) {
         min = mid;
      } else {
         max = mid - 1;
      }
      mid = (min + max) / 2;
      if (mid == min) {
         mid++;
      }
   }
   printf ("%d\n", min);
}

int works (int amo) {
   if (amo == 0) {
      return TRUE;
   }
   if (numCards == 0) {
      return FALSE;
   }
   if (amo == 1) {
      return TRUE;
   }
   numCh = 0;
   int place;
   int i, j;
   int found;
   for (i = 0; i < numCards; i++) {
      found = FALSE;
      for (j = 0; j < numCh && !found; j++) {
         if (chains[j][0] == cards[i] - 1 && chains[j][1] < amo) {
            chains[j][0] = cards[i];
            chains[j][1]++;
            found = TRUE;
         }
      }
      if (!found) {
         chains[numCh][0] = cards[i];
         chains[numCh][1] = 1;
         numCh++;
      }
   }
   for (i = 0; i < numCh; i++) {
      found = FALSE;
      if (chains[i][1] < amo) {
         for (j = 0; j < i && !found; j++) {
            if (chains[j][0] == chains[i][0] - chains[i][1]) {
               chains[j][0] = chains[i][0];
               found = TRUE;
            }
         }
         if (!found) {
            return FALSE;
         }
      }
   }
   return TRUE;
}

void sort2 (int start, int finish) {
   if (finish - start <= 0) {
      return;
   }
   int midPoint = (start + finish) / 2;
   sort (start, midPoint);
   sort (midPoint + 1, finish);
   int i, place1, place2;
   int newCards[finish - start + 1];
   place1 = start;
   place2 = midPoint + 1;
   for (i = 0; i < finish - start + 1; i++) {
      if (place1 > midPoint) {
         newCards[i] = cards[place2];
         place2++;
      } else if (place2 > finish) {
         newCards[i] = cards[place1];
         place1++;
      } else {
         if (cards[place1] < cards[place2]) {
            newCards[i] = cards[place1];
            place1++;
         } else {
            newCards[i] = cards[place2];
            place2++;
         }
      }
   }
   for (i = 0; i < finish - start + 1; i++) {
      cards[start + i] = newCards[i];
   }
}

void sort (int start, int finish) {
   if (finish - start <= 0) {
      return;
   }
   int midPoint = (start + finish) / 2;
   sort (start, midPoint);
   sort (midPoint + 1, finish);
   int i, place1, place2;
   int newCards[finish - start + 1];
   place1 = start;
   place2 = midPoint + 1;
   for (i = 0; i < finish - start + 1; i++) {
      if (place1 > midPoint) {
         newCards[i] = cards[place2];
         place2++;
      } else if (place2 > finish) {
         newCards[i] = cards[place1];
         place1++;
      } else {
         if (cards[place1] < cards[place2]) {
            newCards[i] = cards[place1];
            place1++;
         } else {
            newCards[i] = cards[place2];
            place2++;
         }
      }
   }
   for (i = 0; i < finish - start + 1; i++) {
      cards[start + i] = newCards[i];
   }
}

