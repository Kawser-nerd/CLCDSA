#include <stdio.h>
int main(void){
    int n,a[100],sum=0,i,bridge=0,tmp=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    if(sum%n!=0) printf("-1\n");
    else{
        for(i=0;i<n;i++){
            tmp+=sum/n-a[i];
            if(tmp!=0) bridge++;
        }
        printf("%d\n",bridge);
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&n);
     ^
./Main.c:6:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%d",&a[i]);
         ^