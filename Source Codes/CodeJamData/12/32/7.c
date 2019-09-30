#include <stdio.h>
#include <math.h>


int N,A;
double D;


double max(double a,double b)
{
    return (a>b)?a:b;
}

int main()
{
    int T,c;
    int i;
    scanf("%d",&T);
    for(c=1;c<=T;c++)
    {
        double x1,t1,x2,t2;
        scanf("%lf %d %d",&D,&N,&A);
        scanf("%lf %lf",&t1,&x1);
        if (N==1)
        {
            printf("Case #%d:\n",c);
            for(i=0;i<A;i++)
            {
                double acel;
                scanf("%lf",&acel);
                printf("%.8lf\n",sqrt(D/(0.5*acel)));
            }
            continue;
        }
        //N==2
        scanf("%lf %lf",&t2,&x2);
        double c_vel=(x2-x1)/(t2-t1);
        printf("Case #%d:\n",c);
        for(i=0;i<A;i++)
        {
            double acel;
            scanf("%lf",&acel);
            printf("%.8lf\n",max((D-x1)/c_vel,sqrt(D/(0.5*acel))));
        } 
    }
    return 0;
}