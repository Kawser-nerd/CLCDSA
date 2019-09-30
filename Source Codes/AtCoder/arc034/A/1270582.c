#include <stdio.h>
int main(void){
    int N,i ;
    double max = 0, a,b,c,d,e;
    scanf("%d", &N);
    for(i=1;i<=N;i++){
        scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e);
        if( max< a+b+c+d+e*110/900) max =  a+b+c+d+e*110/900; 
    }
    printf("%3.10lf\n", max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &N);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e);
         ^