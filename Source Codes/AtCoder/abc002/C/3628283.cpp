#include <iostream>
#include <cmath>
#include <stdio.h>
int main(){
  double x1,x2,x3,y1,y2,y3;
  std::cin>>x1>>y1>>x2>>y2>>x3>>y3;
  y2-=y1;y3-=y1;
  x2-=x1;x3-=x1;
  printf("%.1lf\n",std::abs((double)(x2*y3-x3*y2))/2.0);
  return 0;
}