#include<stdio.h>
int main(){
  int n,d[110],min=1e9,i,j,s;
  scanf("%d",&n);
  for(i=0;i<n;i++)scanf("%d",&d[i]);
  for(i=-100;i<101;i++){
    for(j=s=0;j<n;j++)s+=(d[j]-i)*(d[j]-i);
    if(min>s)min=s;
  }
  printf("%d\n",min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:5:19: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++)scanf("%d",&d[i]);
                   ^