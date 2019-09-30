#include <stdio.h>
#include <math.h>
#include <limits.h>

// pi * r^2

#define PRECISION 0.0000001

double f, R, t, r, g, p, aux_r;

double area(double x1, double y1, double x2, double y2) {
  double mx, my;

  //printf("(%.4lf,%.4lf) size %.4lf\n",x1,y1,x2-x1);

  if (x2-x1 < PRECISION) return 0;
  //puts("1");

  if (x1*x1 + y1*y1 >= aux_r) return 0;
  //puts("2");
  
  if (x2*x2 + y2*y2 < aux_r)
    return (x2-x1)*(y2-y1);
  //puts("3");

  mx = (x1+x2)/2.0;
  my = (y1+y2)/2.0;

  return area(x1,y1,mx,my) + 
    area(mx,y1,x2,my) +
    area(x1,my,mx,y2) +
    area(mx,my,x2,y2);
  
}

int main() {
  int i, n;
  double a;
  double x, y, factor;

  scanf("%d",&n);
  for (i=1; i<=n; i++) {
    scanf("%lf %lf %lf %lf %lf",&f, &R, &t, &r, &g);

    factor = R;
    R/=factor;
    f/=factor;
    t/=factor;
    r/=factor;
    g/=factor;

    t+= f;
    r+= f;
    g-=f+f;
    if (g<0) g=0;
    aux_r = (R-t)*(R-t);

    a = 0.0;
    for (x=r; x<R-t; x+=g+r+r)
      for (y=r; y<R-t; y+=g+r+r) {
	a += area(x,y,x+g,y+g);      
    }


    p = a / (M_PI*R*R / 4);
    printf("Case #%d: %.6lf\n", i, 1-p);
  }

  return 0;
}
