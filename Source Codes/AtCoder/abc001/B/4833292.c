#include <stdio.h>

int main() {
  int a,b;
  scanf("%d", &a);
  if(a<100)printf("00\n");
  if(a>=100&&a<=5000){
    b=a/100;
    if(b<10)printf("0%d\n",b);
    if(b>=10)printf("%d\n", b);
  }
  if(a>=6000&&a<=30000){
    b=a/1000;
    printf("%d\n",50+b);
  }
  if(a>=35000&&a<=70000){
    b=(((a/1000)-30)/5)+80;
    printf("%d\n",b);
  }
  if(a>70000)printf("89\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &a);
   ^