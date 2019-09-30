#include<stdio.h>

int main(void){
  int n,m,max=0,ans=1,i,j;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    m=i;
    for(j=0;;j++){
      if(m%2==0) m/=2;
      else break;
    }
    if(max<j){
      max=j;
      ans=i;
    }
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^