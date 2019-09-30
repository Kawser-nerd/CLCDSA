#include<stdio.h>
int main(){
  int n,m,i,a;
  scanf("%d %d",&n,&m);
  for(i=0;i<n;i++)scanf("%d",&a);
  printf("%d\n",(n-2)/(m-1)+1);
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:5:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&a);
                   ^