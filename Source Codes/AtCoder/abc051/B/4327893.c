#include<stdio.h>
int main(){
  int k,s,i,j,ans=0;
  scanf("%d%d",&k,&s);
  for(i=0;i<=k;i++){
    for(j=0;j<=k;j++){
      if(s-i-j<=k&&s-i-j>=0) ans++;
    }
  }
  printf("%d",ans);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&k,&s);
   ^