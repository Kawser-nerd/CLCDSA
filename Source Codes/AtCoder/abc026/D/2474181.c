#include<stdio.h>
#include<math.h>
#define pi 3.1415926535897932384626433837295028841971694

int main()
{
    double a,b,c,l=0,r=1000,m,x;
    scanf("%lf %lf %lf",&a,&b,&c);
    while(r-l>=0.000000000001){
    	m=(l+r)/2;
    	x=a*m+b*sin(c*m*pi);
    	if(x<100) l=m;
    	else r=m;
    }
    printf("%.12lf\n",(l+r)/2);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf %lf %lf",&a,&b,&c);
     ^