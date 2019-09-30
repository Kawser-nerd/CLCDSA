#include <stdio.h>
int main(void){
    int n,i,j,t;
    double sum,max=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        sum=0;
        for(j=0;j<5;j++){
            scanf("%d",&t);
            if(j==4) sum+=(double)t*110/900;
            else sum+=t;
        }
        if(sum>max) max=sum;
    }
    printf("%f\n",max);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:9:13: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
             scanf("%d",&t);
             ^