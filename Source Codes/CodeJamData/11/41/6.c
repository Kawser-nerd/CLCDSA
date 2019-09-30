// Luke Harrison
// 4/6/11

#include <stdio.h>
#include <stdlib.h>


#define TRUE         1
#define FALSE        0

#define E            0.000000001

struct belt {
   int start;
   int end;
   int extra;
};

int numBelts;

struct belt allBelts[5001];


void handleCase (void);
void sort (int start, int finish);


int main () {
   freopen ("air.in", "r", stdin);
   freopen ("air.out", "w", stdout);
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
   int length, walkSpeed, runSpeed, maxTime;
   scanf ("%d %d %d %d %d ", &length, &walkSpeed, &runSpeed, &maxTime, &numBelts);
   double time = 0.0;
   int i;
   for (i = 0; i < numBelts; i++) {
      scanf ("%d %d %d ", &allBelts[i].start, &allBelts[i].end, &allBelts[i].extra);
      
   }
   int numOrg = numBelts;
   if (allBelts[0].start != 0) {
      allBelts[numBelts].start = 0;
      allBelts[numBelts].end = allBelts[0].start;
      allBelts[numBelts].extra = 0;
      numBelts++;
   }
   for (i = 1; i < numOrg; i++) {
      if (allBelts[i].start != allBelts[i - 1].end) {
         allBelts[numBelts].start = allBelts[i - 1].end;
         allBelts[numBelts].end = allBelts[i].start;
         allBelts[numBelts].extra = 0;
         numBelts++;
      }
   }
   if (allBelts[numOrg - 1].end != length) {
      allBelts[numBelts].start = allBelts[numOrg - 1].end;
      allBelts[numBelts].end = length;
      allBelts[numBelts].extra = 0;
      numBelts++;
   }
   sort (0, numBelts - 1);
   double timeLeftRun = (double) maxTime;
   double dis;
   double spe;
   double spe2;
   for (i = 0; i < numBelts; i++) {
      dis = (double) (allBelts[i].end - allBelts[i].start);
      spe = (double) (runSpeed + allBelts[i].extra);
      spe2 = (double) (walkSpeed + allBelts[i].extra);
      if (spe * timeLeftRun >= dis) {
         timeLeftRun -= (dis / spe);
         time += (dis / spe);
      } else {
         dis -= spe * timeLeftRun;
         time += timeLeftRun;
         timeLeftRun = 0.0;
         time += (dis / spe2);
      }
   }
   printf ("%.12lf\n", time);
}


void sort (int start, int finish) {
   if (finish - start <= 0) {
      return;
   }
   int midPoint = (start + finish) / 2;
   sort (start, midPoint);
   sort (midPoint + 1, finish);
   int i, place1, place2;
   struct belt newSizes[finish - start + 1];
   place1 = start;
   place2 = midPoint + 1;
   for (i = 0; i < finish - start + 1; i++) {
      if (place1 > midPoint) {
         newSizes[i] = allBelts[place2];
         place2++;
      } else if (place2 > finish) {
         newSizes[i] = allBelts[place1];
         place1++;
      } else {
         if (allBelts[place1].extra < allBelts[place2].extra) {
            newSizes[i] = allBelts[place1];
            place1++;
         } else {
            newSizes[i] = allBelts[place2];
            place2++;
         }
      }
   }
   for (i = 0; i < finish - start + 1; i++) {
      allBelts[start + i] = newSizes[i];
   }
}



