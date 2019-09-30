#include <stdio.h>
#include <math.h>
int main(void){
  int x,i,j,max=1;
  scanf("%d",&x);
  for(i=1;i<=x;i++){
    for(j=2;j<=x;j++){
      int num=pow(i,j);
      if(num<=x&&max<num) max=num;
      if(num>x) break;
    }
  }
  printf("%d\n",max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x);
   ^