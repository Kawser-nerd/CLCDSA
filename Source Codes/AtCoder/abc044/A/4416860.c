#include <stdio.h>
#include <math.h>
#include <string.h>
int main(void){
  int n,k,x,y,i,sum=0;
  scanf("%d%d%d%d",&n,&k,&x,&y);
  for(i=1;i<=n;i++){
    if(i>k) sum+=y;
    else sum+=x;
  }
  printf("%d",sum);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d",&n,&k,&x,&y);
   ^