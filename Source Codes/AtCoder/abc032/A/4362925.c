#include <stdio.h>

int main(void){
  int a,b,n;
  scanf("%d%d%d",&a,&b,&n);

  for(int i = n;;i++){
    if(i%a == 0 && i%b == 0){
      printf("%d\n",i);
      break;
    }
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&n);
   ^