#include<stdio.h>

int main(void){
  int n;
  char a[5];
  scanf("%s",a);
  scanf("%d",&n);
  printf("%c%c\n",a[(n-1)/5],a[(n-1)%5]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",a);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^