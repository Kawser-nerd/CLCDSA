#include <stdio.h>

int main(void){
  char a[10],b[10],c[10];

  scanf("%s",a);
  scanf("%s",b);
  scanf("%s",c);

  printf("%c%c%c\n",a[0]-32,b[0]-32,c[0]-32);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",a);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",b);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",c);
   ^