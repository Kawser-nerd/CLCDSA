#include<stdio.h>
int main(){
  int n,m,s=0,i;
  scanf("%d %d",&n,&m);
  s=100*(n-m)+1900*m;
  for(i=0;i<m;i++)s*=2;
  printf("%d\n",s);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^