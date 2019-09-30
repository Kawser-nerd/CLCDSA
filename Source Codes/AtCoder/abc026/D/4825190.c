#include <stdio.h>
#include <math.h>
#define MPI 3.141592653589793238462643383279
double a,b,c;

double f(double x){
    return a*x+b*sin(c*x*MPI);
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
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf %lf %lf",&a,&b,&c);
     ^