#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double result(int n, double a,double d,double* t,double* dt)
{
    double di,ti;
    if(n==1)
    {
        //if(dt[0]>d)
        //{
            ti = sqrt((2*d)/a);
            return ti;
        //}
        //di = a*t[0]*t[0]/2;
        //if(di
    }
    else
    {
        if(dt[0]>d)
        {
            ti = sqrt((2*d)/a);
            return ti;
        }
        else
        {
            //ti = sqrt((2*dt[0])/a);
            double temp = t[0]+ ((t[1]-t[0])*(d-dt[0]))/(dt[1]-dt[0]);
            di = a*temp*temp/2;
            if(di>=d)
                return temp;
            else
                return sqrt((2*d)/a);
        }
    }
}

int main()
{

	int t,n;
	//long a,b;
	scanf("%d",&t);
	int a;
	int i,j,k;
	
	for(j=0;j<t;j++)
	{
	    double d;
	    scanf("%lf",&d);
	    scanf("%d",&n);
	    scanf("%d",&a);
        double* t = (double*)malloc(n*sizeof(double));
        double* dt = (double*)malloc(n*sizeof(double));
        double* ac = (double*)malloc(a*sizeof(double));
        for(i=0;i<n;i++)
        {
            scanf("%lf",&t[i]);
            scanf("%lf",&dt[i]);
        }
        for(i=0;i<a;i++)
        {
            scanf("%lf",&ac[i]);
        }

		printf("Case #%d: \n",j+1);
        for(i=0;i<a;i++)
		{
		    double res = result(n,ac[i],d,t,dt);
		    printf("%f\n",(float)res);
		}
		
	}
	
	return 0;
}
