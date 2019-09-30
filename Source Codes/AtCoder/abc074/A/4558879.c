#include<stdio.h>
    int main(void){
      int n,a;
      scanf("%d",&n);
      scanf("%d",&a);
      n=n*n-a;
      printf("%d\n",n);
      return 0;
    } ./Main.c: In function ‘main’:
./Main.c:4:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&n);
       ^
./Main.c:5:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&a);
       ^