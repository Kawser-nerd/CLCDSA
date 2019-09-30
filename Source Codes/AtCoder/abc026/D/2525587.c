#include <stdio.h>
#include <math.h>
#define M_PI 3.141592653589793238462643383279
 
    double a,b,c;
 
 
double f(double x){
    return a*x+b*sin(c*x*M_PI);
}
 
int main(void){
    scanf("%lf %lf %lf",&a,&b,&c);
    double left=0.0;
    double right=1145141919;
    for(int i=0;i<10000;i++){
        double mid=(left+right)/2;
        if(f(mid)>100)right=mid;
        else left=mid;
    }
    printf("%.10f\n",left);
    return 0;
} ./Main.c:3:0: warning: "M_PI" redefined
 #define M_PI 3.141592653589793238462643383279
 ^
In file included from ./Main.c:2:0:
/usr/include/math.h:372:0: note: this is the location of the previous definition
 # define M_PI  3.14159265358979323846 /* pi */
 ^
./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf %lf %lf",&a,&b,&c);
     ^