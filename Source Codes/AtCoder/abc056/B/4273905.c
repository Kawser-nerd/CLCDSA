#include <stdio.h>
#include <stdlib.h>

int max(int a,int b){
  if(a > b){
    return a;
  }
  return b;
}

int main(void){
  int W,a,b;
  scanf("%d%d%d",&W,&a,&b);

  printf("%d\n",max(abs(a-b)-W,0));

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&W,&a,&b);
   ^