#include<stdio.h>
#include<math.h>
int main(void){
  int n,i,j,ans=1;
  if(scanf("%d", &n)==1);
  if(n>1){
    for(i=2;i<sqrt(n);i++){
    for(j=i*i;j*i<=n;j*=i);
    if(j<=n && j>ans)ans=j;
  }
  }
  printf("%d\n",ans);
  return 0;
}