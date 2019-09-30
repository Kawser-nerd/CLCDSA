#include <stdio.h>

int main(void){
  int x;
  scanf("%d",&x);
  for(int i=1; i*i*i*i<=x; i++) {
    if(i*i*i*i==x) {
      printf("%d\n",i);
      break;
    }
  }
  return 0;  
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x);
   ^