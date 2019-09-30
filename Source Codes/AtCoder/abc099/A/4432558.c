#include <stdio.h>

int main()
{
  char c = 'A';
  char d = 'B';
  char e = 'C';
  int a;
  scanf("%d",&a);
  if(a<1000){
    printf("%c%c%c",c,d,e);
  } else if (a >= 1000){
    printf("%c%c%c",c,d,e+1);
  } else {
    return 1;
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^