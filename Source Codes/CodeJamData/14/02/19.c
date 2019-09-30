#include<stdio.h>

void main()
{
    int i, j;
    double sec, out;
    scanf("%d", &i);
    for(j=1 ; j<=i ; j++)
    {
     double c, f, x;
     scanf("%lf", &c);
     scanf("%lf", &f);
     scanf("%lf", &x);
     sec = 0;
     out = 2;

     while( (c/out+x/(out+f)) < x/out )
     {
          sec += c/out;
          out += f;          
     }
     sec += x/out;
     printf("Case #%d: %f\n", j, sec);
    }
}
