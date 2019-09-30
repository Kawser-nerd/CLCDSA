#include<stdio.h>
#include<math.h>

int main(void)
{
  int ca = 1, t, n, m, i;
  int x0, y0, x1, y1, xb, yb;
  
  double r0, r1, c, CBA, CBD, CAB, CAD, area;
  
  
  scanf("%d", &t);
  
  while(ca <= t)
  {
    scanf("%d %d", &n , &m);
    
    scanf("%d %d %d %d", &x0, &y0, &x1, &y1);
    
    
    printf("Case #%d:", ca);
    for(i = 0; i < m; i++)
    {
      scanf("%d %d", &xb, &yb);  
      
      r0 = sqrt((xb - x0) * (xb - x0) + (yb - y0) * (yb - y0));
      r1 = sqrt((xb - x1) * (xb - x1) + (yb - y1) * (yb - y1));

      c = sqrt((x1-x0) * (x1-x0) + (y1-y0) * (y1-y0));
      
      CBA = acos((r1 * r1 + c * c - r0 * r0)/(2.0*r1*c));
      CBD = 2.0 * CBA;
      
      CAB = acos((r0 * r0 + c * c - r1 * r1)/(2.0*r0*c));
      CAD = 2.0 * CAB;
      
      area = (1.0/2.0) * CBD * r1 * r1 - (1.0/2.0)* r1 * r1 * sin(CBD) + (1.0/2.0) * CAD * r0 * r0 - (1.0/2.0) * r0 * r0 * sin(CAD);
      
      printf(" %.7lf", area);
    }
    printf("\n");    
    
    ca++;
  }
  
  return 0;
}