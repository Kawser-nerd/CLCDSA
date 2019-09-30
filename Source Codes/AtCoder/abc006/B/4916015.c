#include <stdio.h>
     
    int main(void) {
      int A,a[1000000],i;
      scanf("%d",&A);
    a[1]=0;
    a[2]=0;
    a[3]=1;
    for(i=4;i<=A;i++){
        a[i]=(a[i-1]+a[i-2]+a[i-3])%10007;
    }
    printf("%d\n",a[A]);
      
      return 0;
    } ./Main.c: In function ‘main’:
./Main.c:5:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&A);
       ^