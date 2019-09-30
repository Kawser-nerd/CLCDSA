#include <stdio.h>
#include <math.h>
#define PI (3.14159265f)
double absol(double x)
{
       if(x < 0)
       return (-x);
       else
       return x;
}
double getStripArea(double R, double t, double pos)
{
       if(pos > (R-t))
       {
        return 0.0f;
       }
       return absol(pos*sqrt((R-t)*(R-t)-(pos*pos))/2 - (((R-t)*(R-t)*acos(pos/(R-t)))/2));
}
double areaOf1Section(double R, double t, double x, double y, double g)
{
       double tmp;
       double v1, v2;
            
       v1 = getStripArea(R, t, y);
       v2 = getStripArea(R, t, sqrt((R-t)*(R-t)-x*x));
        
       return ((v1-v2)-absol((sqrt((R-t)*(R-t)-x*x))-y)*x);
}
double areaOf2Section(double R, double t, double x, double y, double g)
{
       double tmp;
       double v1, v2;
            
       v1 = getStripArea(R, t, y);
       v2 = getStripArea(R, t, y+g);
            
       return ((v1-v2)-g*x);
}
double areaOf3Section(double R, double t, double x, double y, double g)
{
       double tmp;
       double v1, v2;
            
       v1 = getStripArea(R, t, y+g);
       v2 = getStripArea(R, t, sqrt((R-t)*(R-t)-(x+g)*(x+g)));
            
       return (((v2-v1)-absol(((y+g)-sqrt((R-t)*(R-t)-(x+g)*(x+g)))*x))+g*(sqrt((R-t)*(R-t)-(x+g)*(x+g))-y));
}
double subtractSquare(double R, double t, double x, double y, double g)
{
       if((((x+g)*(x+g)+(y+g)*(y+g))<=((R-t)*(R-t))))
       {
                   /* Completely in            */
                   return (4*(g)*(g));
       }
       
       if(((x+g)*(x+g)+y*y)>(R-t)*(R-t))
       {
         if(((y+g)*(y+g)+x*x)>(R-t)*(R-t))
         {
          //printf("Returning 1 %lf (%lf %lf %lf)\n", 4*areaOf1Section(R,t,x,y,g), x, y, sqrt(x*x+y*y));
          return (4*areaOf1Section(R,t,x,y,g));
         }
         else
         {
          //printf("Returning 2 %lf (%lf %lf %lf)\n", 4*areaOf2Section(R,t,x,y,g), x, y, sqrt(x*x+y*y));
          return (4*areaOf2Section(R,t,x,y,g));
         }
       }  
       else
       {
         if(((y+g)*(y+g)+x*x)>(R-t)*(R-t))
         {
          //printf("Returning 3 %lf (%lf %lf %lf)\n", 4*areaOf2Section(R,t,y,x,g), x, y, sqrt(x*x+y*y));
          return (4*areaOf2Section(R,t,y,x,g));
         }
         else
         {
          //printf("Returning 4 %lf (%lf %lf %lf)\n", 4*areaOf3Section(R,t,x,y,g), x, y, sqrt(x*x+y*y));
          return (4*areaOf3Section(R,t,x,y,g));
         } 
       }        
}

int main()
{
    int n;
    double x, y;
    double f, R, t, r, g;
    double availArea;
    int cs = 0;
    scanf("%d", &n);
    while(n--)
    {
     cs++;
     scanf("%lf%lf%lf%lf%lf", &f, &R, &t, &r, &g);

     if(g < (2*f))
     {
          printf("Case #%d: %lf\n", cs, 1.0f);
          continue;
     }

     availArea = 0.0f;
     /* Now consider each square */
     for(x=(r+f); x<(R-t-f); x+=(g+2*r))
     {
       for(y=(r+f); y<(R-t-f); y+=(g+2*r))
       {
        if((x*x+y*y)<((R-t-f)*(R-t-f)))
        availArea+=subtractSquare(R, t+f, x, y, g-(2*f));
       }
     }  
     printf("Case #%d: %lf\n", cs, 1.0f-(availArea/(PI*R*R)));  
    }
    getchar();
        getchar();
            getchar();
    return 0;
}
