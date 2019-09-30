// Luke Harrison
// 6/5/11

#include <stdio.h>
#include <stdlib.h>


#define TRUE         1
#define FALSE        0

#define ORANGE       0
#define BLUE         1

int curIns[101][2];

void handleCase (void);



int main () {
   freopen ("bot.in", "r", stdin);
   freopen ("bot.out", "w", stdout);
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
   int numIns;
   scanf ("%d ", &numIns);
   int i;
   char person;
   for (i = 0; i < numIns; i++) {
      scanf ("%c %d ", &person, &curIns[i][1]);
      if (person == 'O') {
         curIns[i][0] = ORANGE;
      } else {
         curIns[i][0] = BLUE;
      }
   }
   int timeTaken = 0;
   int curOrg = 1;
   int curBlue = 1;
   int leftBlueTime = 0;
   int leftOrangeTime = 0;
   int dis;
   for (i = 0; i < numIns; i++) {
      if (curIns[i][0] == ORANGE) {
         dis = abs (curIns[i][1] - curOrg);
         if (leftOrangeTime > dis) {
            timeTaken++;
            leftBlueTime++;
         } else {
            timeTaken += (dis - leftOrangeTime) + 1;
            leftBlueTime += (dis - leftOrangeTime) + 1;
         }
         leftOrangeTime = 0;
         curOrg = curIns[i][1];
      } else {
         dis = abs (curIns[i][1] - curBlue);
         if (leftBlueTime > dis) {
            timeTaken++;
            leftOrangeTime++;
         } else {
            timeTaken += (dis - leftBlueTime) + 1;
            leftOrangeTime += (dis - leftBlueTime) + 1;
         }
         leftBlueTime = 0;
         curBlue = curIns[i][1];
      }
   }
   printf ("%d\n", timeTaken);
}

