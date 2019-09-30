#include<stdio.h>

int main(void){
  int a,b,i,n,ans=0;
  scanf("%d %d",&a,&b);
  n = b-a;
  for(i=0;i<n;i++){
    ans+=i;
  }
  ans = ans-a;
  printf("%d\n",ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^