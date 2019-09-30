#include <stdio.h>
#include <math.h>
int main(void){
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    double s[n],sum=0,max=0,min=1e9;
    for (int i=0; i<n; i++){
        scanf("%lf",&s[i]);
        sum+=s[i];
        max=fmax(max,s[i]);
        min=fmin(min,s[i]);
    }
    if (max==min){
        printf("-1\n");
        return 0;
    }
    double p=b/(max-min);
    double q=a-(sum*p)/n;
    printf("%.8f %.8f\n",p,q);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d",&n,&a,&b);
     ^
./Main.c:8:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lf",&s[i]);
         ^