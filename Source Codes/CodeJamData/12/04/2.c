#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Sloppy method... :/

#define DS 1.0e-6
#define EPS 1.0e-11

int gcd(int a, int b) {
   a = abs(a); b = abs(b);
   if (b==0) return a;
   else return gcd(b, a%b);
}


// Cast ray from a point to the next gridline.

void cast_ray(double x0, double y0, int rayx, int rayy, 
              double *x1, double *y1) {
   double nextx, nexty;

   if (rayx > 0) nextx = ceil(x0 + DS);
   else          nextx = floor(x0 - DS);
   if (rayy > 0) nexty = ceil(y0 + DS);
   else          nexty = floor(y0 - DS);

   if (rayx == 0) {
      (*y1) = nexty; (*x1) = x0;
      return;
   } else if (rayy == 0) {
      (*y1) = y0; (*x1) = nextx;
      return;
   }   

   // Non-degenerate cases. 

   double step1, step2, step;

   step1 = (nexty - y0) / rayy;
   step2 = (nextx - x0) / rayx;

//if (step1 <= EPS || step2 < EPS) printf("ERROR %lf %lf!!!\n", step1, step2);

   step = step1 < step2 ? step1 : step2;

   (*x1) = x0 + rayx * step;
   (*y1) = y0 + rayy * step;
}

// Check whether a point is between the first two points.

int check_hit(double x1, double y1, double x2, double y2, 
              double x3, double y3) {
   double dx1,dy1, dx2,dy2;

   dx1 = x2-x1; dy1 = y2-y1;
   dx2 = x3-x1; dy2 = y3-y1;

   if (fabs(dy2*dx1 - dy1*dx2) > EPS) return 0;  // Not collinear.
   if ((x3-x1)*(x3-x2) < EPS && (y3-y1)*(y3-y2) < EPS) return 1;
   else return 0;
}

// Do appropriate reflection for walls & corners.

void check_wall(int board[64][64], double x, double y, int *rx, int *ry) {
   int ix, iy;

   ix = (int)(x+EPS); iy = (int)(y+EPS);

   // Check for wall.

   if (fabs(x - ix) < EPS && fabs(y - iy) > EPS) {
//printf("(a) --> %d %d %lf %lf\n", ix, iy, x, y);
      if ((*rx) > 0 && board[iy][ix]) 
         *rx = -(*rx); 
      if ((*rx) < 0 && board[iy][ix-1])
         *rx = -(*rx);
      return;
   } else if (fabs(x - ix) > EPS && fabs(y - iy) < EPS) {
//printf("(b) --> %d %d %lf %lf\n", ix, iy, x, y);
      if ((*ry) > 0 && board[iy][ix])
         *ry = -(*ry); 
      if ((*ry) < 0 && board[iy-1][ix])
         *ry = -(*ry); 
      return;
   } else if (fabs(x - ix) > EPS && fabs(y - iy) > EPS)
      return;

   // Ok, corner.

   int nextx, nexty;
   int side1x, side1y, side2x, side2y;

   if ((*rx)>0 && (*ry)>0) {
      nextx = ix; nexty = iy; 
      side1x = ix;   side1y = iy-1;
      side2x = ix-1; side2y = iy;
   } else if ((*rx)>0 && (*ry)<0) {
      nextx = ix; nexty = iy-1;
      side1x = ix; side1y = iy;
      side2x = ix-1; side2y = iy-1;
   } else if ((*rx)<0 && (*ry)>0) {
      nextx = ix-1; nexty = iy;
      side1x = ix-1; side1y = iy-1;
      side2x = ix; side2y = iy;
   } else {
      nextx = ix-1; nexty = iy-1;
      side1x = ix-1; side1y = iy;
      side2x = ix; side2y = iy-1;
   }   

//printf("A - %d %d; B - %d %d; C - %d %d [%d%d%d]\n", side1x, side1y, side2x, side2y, nextx, nexty, board[side1y][side1x], board[side2y][side2x], board[nexty][nextx]);
   if (!board[nexty][nextx]) return;   // Not blocked.

   if (board[side1y][side1x] && board[side2y][side2x]) { 
      (*rx) = -(*rx); (*ry) = -(*ry);
   } else if (board[side1y][side1x] && !board[side2y][side2x]) {
      (*rx) = -(*rx);
   } else if (!board[side1y][side1x] && board[side2y][side2x]) {
      (*ry) = -(*ry);
   } else 
      (*rx) = (*ry) = 0;

}


// Test whether a particular ray will reach back.

int test_ray(int board[64][64], int sizex, int sizey, int posx, int posy,
              int rayx, int rayy, int d) {
   double x0, y0, x1, y1, x2, y2;
   double dx, dy;   // distance traveled.

   x1 = x0 = posx + 0.5; y1 = y0 = posy + 0.5;
   dx = dy = 0.0;

   // Ray casting?

   while (dx*dx + dy*dy <= d*d+EPS) {
      cast_ray(x1, y1, rayx, rayy, &x2, &y2);
if (x2<0.0 || x2>sizex || y2<0.0 || y2>sizey) printf("ERRRR!!! %lf %lf\n", x2, y2);
//printf("%lf %lf %lf %lf %lf %lf\n", x1, y1, x2, y2, x0, y0);
      if (dx+dy > EPS && check_hit(x1, y1, x2, y2, x0, y0)) {
         dx += fabs(x0 - x1); dy += fabs(y0 - y1);
         if (dx*dx + dy*dy <= d*d+EPS) { 
//printf("dist = %lf\n", sqrt(dx*dx + dy*dy));
            return 1;
         }
         else return 0;
      }

      check_wall(board, x2, y2, &rayx, &rayy);
//printf(">>%d %d\n", rayx, rayy);

      if (rayx == 0 && rayy == 0) return 0;

      dx += fabs(x2 - x1); dy += fabs(y2 - y1); // Use with caution!
      x1 = x2; y1 = y2;
   }

   return 0;
}

// Analyse each board.

int analyse_board() {
   int board[64][64];
   int posx, posy;
   int h, w, d, j, k;

   scanf("%d %d %d", &h, &w, &d);

   // Read board.

   for(j=0; j<h; j++) {
      char line[80];
      scanf("%s", line);

      for(k=0; k<w; k++) {
         if (line[k] == '#') board[j][k] = 1;
         else board[j][k] = 0;
         if (line[k] == 'X') {posx=k; posy=j;}
      }
   }

   // Test light rays.

   int distx, disty, count=0;

   for(distx = -d; distx <= d; distx++)
   for(disty = -d; disty <= d; disty++) 
      if (gcd(distx, disty) == 1 && distx*distx + disty*disty <= d*d) {
         if (test_ray(board, w, h, posx, posy, distx, disty, d)) {
//            printf("%d %d ok.\n", distx, disty);
            count++;
         } 
//else
//printf("%d %d not ok.\n", distx, disty);
      }

   return count;
}


int main() {
   int i, cases;

   scanf("%d", &cases);
   for(i=0; i<cases; i++) 
      printf("Case #%d: %d\n", i+1, analyse_board());

   return 0;
}
