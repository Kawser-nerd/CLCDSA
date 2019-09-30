#include <stdio.h>

int main(void){
  int n;
  scanf("%d",&n);
  if (n % 3 == 0){
    printf("%s","YES");
  }else{
    printf("%s","NO");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^