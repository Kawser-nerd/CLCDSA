#include <stdio.h>
#include <math.h>

typedef struct point{
  int x;
  int y;
}point;

void setPoint(point*, int, int);
void changeOrigin(const point*, point*);
void showPosition(const point *);

int
main(){
  int xa, ya, xb, yb, xc, yc;
  int length, height;
  double area;
  scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);
  
  point a = {xa, ya};
  point b = {xb, yb};
  point c = {xc, yc};
  changeOrigin(&a, &b);
  changeOrigin(&a, &c);
  area = abs(b.x*c.y - b.y*c.x)/2.;
  printf("%f\n",area);
  

  return 0;
}

void
setPoint(point *p, int x, int y){
  p -> x = x;
  p -> y = y;
}

void
changeOrigin(const point *origin, point *p){
  p -> x -= origin -> x;
  p -> y -= origin -> y;
}

void
showPosition(const point* p){
  printf("x:%d\n", p -> x);
  printf("y:%d\n", p -> y);

} ./Main.c: In function ‘main’:
./Main.c:25:10: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
   area = abs(b.x*c.y - b.y*c.x)/2.;
          ^
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d %d %d", &xa, &ya, &xb, &yb, &xc, &yc);
   ^