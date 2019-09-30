#include <stdio.h>
int main(void){
    double ans=0,a,b,c,d,e;
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++){
        scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e);
        if (ans<a+b+c+d+e/900*110){
            ans=a+b+c+d+e/900*110;
        }
    }
    printf("%.8f\n",ans);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf%lf%lf%lf%lf",&a,&b,&c,&d,&e);
         ^