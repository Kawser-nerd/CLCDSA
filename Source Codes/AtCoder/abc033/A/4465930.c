#include<stdio.h>
int main(void)
{
int a, b, c, d;
scanf("%1d %1d %1d %1d", &a, &b, &c, &d);
if(a==b&&b==c&&c==d){
  printf("SAME\n");
}else{
  printf("DIFFERENT\n");
}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%1d %1d %1d %1d", &a, &b, &c, &d);
 ^