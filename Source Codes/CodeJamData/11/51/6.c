// Luke Harrison
// 12/6/11

#include <stdio.h>
#include <stdlib.h>

#define TRUE            1
#define FALSE           0


struct point {
   double x;
   double y;
};

int width, guests;

int numL, numU;
struct point lowerP[200];
struct point upperP[200];

void handleCase (void);

double absF (double n);

double max (double n1, double n2);
double min (double n1, double n2);

double calcAr (double place);

int main () {
   freopen ("input.txt", "r", stdin);
   freopen ("output.txt", "w", stdout);
   int numCases;
   scanf ("%d ", &numCases);
   int i;
   for (i = 0; i < numCases; i++) {
      printf ("Case #%d:\n", i + 1);
      handleCase ();
   }
   return 0;
}


void handleCase (void) {
   scanf ("%d %d %d %d ", &width, &numL, &numU, &guests);
   int i;
   for (i = 0; i < numL; i++) {
      scanf ("%lf %lf ", &lowerP[i].x, &lowerP[i].y);
   }
   for (i = 0; i < numU; i++) {
      scanf ("%lf %lf ", &upperP[i].x, &upperP[i].y);
   }
   double area = (double) width * 2000.0;
   double h;
   for (i = 1; i < numL; i++) {
      h = max (lowerP[i - 1].y, lowerP[i].y) + 1000.0;
      area -= h * (lowerP[i].x - lowerP[i - 1].x);
      area += 0.5 * ((lowerP[i].x - lowerP[i - 1].x) * (absF (lowerP[i - 1].y - lowerP[i].y)));
   }
   for (i = 1; i < numU; i++) {
      h = 1000.0 - min (upperP[i - 1].y, upperP[i].y);
      area -= h * (upperP[i].x - upperP[i - 1].x);
      area += 0.5 * ((upperP[i].x - upperP[i - 1].x) * (absF (upperP[i - 1].y - upperP[i].y)));
   }
   double target = area / guests;
   for (i = 1; i < guests; i++) {
      double min = 0.0;
      double max = (double) width;
      double mid = (min + max) / 2.0;
      while (max - min > 0.0000000001) {
         if (calcAr (mid) < (target * (double) i)) {
            min = mid;
         } else {
            max = mid;
         }
         mid = (min + max) / 2.0;
      }
      printf ("%lf\n", min);
   }
}

double absF (double n) {
   if (n < 0.0) {
      return -n;
   } else {
      return n;
   }
}

double max (double n1, double n2) {
   if (n1 > n2) {
      return n1;
   } else {
      return n2;
   }
}

double min (double n1, double n2) {
   if (n1 < n2) {
      return n1;
   } else {
      return n2;
   }
}


double calcAr (double place) {
   int i;
   double area = place * 2000.0;
   double h;
   for (i = 1; lowerP[i].x < place; i++) {
      h = max (lowerP[i - 1].y, lowerP[i].y) + 1000.0;
      area -= h * (lowerP[i].x - lowerP[i - 1].x);
      area += 0.5 * ((lowerP[i].x - lowerP[i - 1].x) * (absF (lowerP[i - 1].y - lowerP[i].y)));
   }
   double dy = (lowerP[i].y - lowerP[i - 1].y) / (lowerP[i].x - lowerP[i - 1].x);
   double y = lowerP[i - 1].y + (dy * (place - lowerP[i - 1].x));
   h = max (lowerP[i - 1].y, y) + 1000.0;
   area -= h * (place - lowerP[i - 1].x);
   area += 0.5 * ((place - lowerP[i - 1].x) * (absF (lowerP[i - 1].y - y)));
   for (i = 1; upperP[i].x < place; i++) {
      h = 1000.0 - min (upperP[i - 1].y, upperP[i].y);
      area -= h * (upperP[i].x - upperP[i - 1].x);
      area += 0.5 * ((upperP[i].x - upperP[i - 1].x) * (absF (upperP[i - 1].y - upperP[i].y)));
   }
   dy = (upperP[i].y - upperP[i - 1].y) / (upperP[i].x - upperP[i - 1].x);
   y = upperP[i - 1].y + (dy * (place - upperP[i - 1].x));
   h = 1000.0 - min (upperP[i - 1].y, y);
   area -= h * (place - upperP[i - 1].x);
   area += 0.5 * ((place - upperP[i - 1].x) * (absF (upperP[i - 1].y - y)));
   return area;
}
