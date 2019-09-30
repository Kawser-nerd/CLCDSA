#include<stdio.h>

int main(void){
  int n,a,b,ans=0,sum,i,j;
  scanf("%d%d%d",&n,&a,&b);
  for(i=1;i<=n;i++){
    sum=0;
    j = i;
    for(;j;j/=10) sum+=j%10;
    if(a<=sum && sum<=b) ans+=i;
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&a,&b);
   ^