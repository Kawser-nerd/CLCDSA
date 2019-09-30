#include<stdio.h>

int main(void){
  int n,k,i,ans=1;
  scanf("%d",&n);
  scanf("%d",&k);
  for(i=0;i<n;i++){
    if(ans<k) ans*=2;
    else ans+=k;
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&k);
   ^