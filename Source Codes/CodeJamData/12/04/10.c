#include <stdio.h>
#include <stdlib.h>

#define TRUE         1
#define FALSE        0
#define EP           0.000001

struct point {
   double x;
   double y;
};

int width, height;
char grid[40][40];
char finalGrid[100][100];
struct point myPossiblePos[110 * 110];
int valid[110 * 110];
double maxDis;
struct point myPos;

void handleCase ();

struct point getPointAt (int i, int j);

double getDis (struct point p1, struct point p2);

double getDiffX (struct point p1, struct point p2);

double getDiffY (struct point p1, struct point p2);

double myAbs (double n);

int isInBetween (struct point p1, struct point p2, struct point t);

int main () {
   int n;
   freopen ("in.txt", "r", stdin);
   freopen ("out.txt", "w", stdout);
   scanf ("%d ", &n);
   int i;
   for (i = 0; i < n; i++) {
      printf ("Case #%d: ", i + 1);
      handleCase ();
   }
}


void handleCase () {
   scanf ("%d %d %lf ", &height, &width, &maxDis);
   int i, j;
   for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
         scanf ("%c ", &grid[i][j]);
         if (grid[i][j] == 'X') {
            myPos.x = (double) (j - 1);
            myPos.y = (double) (i - 1);
         }
      }
   }
   width -= 2;
   height -= 2;
   int upTo = 0;
   for (i = -maxDis; i <= maxDis; i++) {
      for (j = -maxDis; j <= maxDis; j++) {
         if (i != 0 || j != 0) {
            myPossiblePos[upTo] = getPointAt (i, j);
            if (getDis (myPossiblePos[upTo], myPos) <= maxDis * maxDis) {
               valid[upTo] = TRUE;
               upTo++;
            }
         }
      }
   }
   for (i = 0; i < upTo; i++) {
      for (j = i; j < upTo; j++) {
         if (valid[i] && valid[j] && i != j) {
            if (myAbs (getDiffX (myPossiblePos[i], myPos) * getDiffY (myPossiblePos[j], myPos) -
                       getDiffY (myPossiblePos[i], myPos) * getDiffX (myPossiblePos[j], myPos)) <= EP) {
               if (!isInBetween (myPossiblePos[i], myPossiblePos[j], myPos)) {
                  if (getDis (myPossiblePos[i], myPos) < getDis (myPossiblePos[j], myPos)) {
                     valid[j] = FALSE;
                  } else {
                     valid[i] = FALSE;
                  }
               }
            }
         }
      }
   }
   int total = 0;
   for (i = 0; i < upTo; i++) {
      if (valid[i]) {
         total++;
      }
   }
   printf ("%d\n", total);
}

double getDis (struct point p1, struct point p2) {
   double difX = getDiffX (p1, p2);
   double difY = getDiffY (p1, p2);
   return difX * difX + difY * difY;
}

double getDiffX (struct point p1, struct point p2) {
   double dif = p1.x - p2.x;
   return dif;
}

double getDiffY (struct point p1, struct point p2) {
   double dif = p1.y - p2.y;
   return dif;
}

struct point getPointAt (int i, int j) {
   int xCo;
   int yCo;
   yCo = (height * i);
   if (i < 0) {
      i = -i;
   }
   if (i % 2 == 0) {
      yCo += (int) myPos.y;
   } else {
      yCo += (height - (int) myPos.y - 1);
   }
   xCo = (width * j);
   if (j < 0) {
      j = -j;
   }
   if (j % 2 == 0) {
      xCo += (int) myPos.x;
   } else {
      xCo += (width - (int) myPos.x - 1);
   }
   struct point p;
   p.x = (double) xCo;
   p.y = (double) yCo;
   return p;
}


double myAbs (double n) {
   if (n < 0) {
      return -n;
   } else {
      return n;
   }
}

int isInBetween (struct point p1, struct point p2, struct point t) {
   int valid = FALSE;
   if ((t.x >= p1.x && t.x <= p2.x) || (t.x >= p2.x && t.x <= p1.x)) {
      if ((t.y >= p1.y && t.y <= p2.y) || (t.y >= p2.y && t.y <= p1.y)) {
         valid = TRUE;
      }
   }
   return valid;
}


