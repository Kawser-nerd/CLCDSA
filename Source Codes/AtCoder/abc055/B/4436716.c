#include<stdio.h>

int main(void){
  int i,n;
  long int ans=1;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    ans=i*ans%1000000007;
  }
  printf("%ld",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^