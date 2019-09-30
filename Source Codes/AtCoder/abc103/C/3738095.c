#include <stdio.h>

int  main(){
 int sum,n,i,a;
 sum=0;
 scanf("%d",&n);
 for(i=0;i<n;i++){
      scanf("%d",&a);
      sum+=(a-1);
  }
 printf("%d\n",sum);

 return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:8:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&a);
       ^