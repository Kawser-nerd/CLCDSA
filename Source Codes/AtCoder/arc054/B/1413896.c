#include <math.h>
#include <stdio.h>
double p;
double f(double x){
    return p*pow(2,-x/(1.5))+x;
}
int main(void){
    scanf("%lf",&p);
    double lb,ub,mid,ml,mu;
    lb=0;ub=p;
    int i;
    for(i=0;i<1000;i++){
        ml=(lb*2+ub)/3;
        mu=(lb+2*ub)/3;
        if(f(ml)<f(mu))ub=mu;
        else lb=ml;
           }
    printf("%.10lf\n",f(lb));
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%lf",&p);
     ^