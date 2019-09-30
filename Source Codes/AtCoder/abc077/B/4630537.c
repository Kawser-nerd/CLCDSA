#include <stdio.h>
#include <math.h>
int main(void){
  int n,i,j,max=1;
  scanf("%d",&n);
  for(i=1;i<=n;i++){
    if(i*i<=n&&max<i*i) max=i*i;
    if(i*i>n) break;
  }
  printf("%d\n",max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^