#include<stdio.h>
int main(void)
{
int a, b, c, n;
scanf("%1d %1d %1d", &a, &b, &c);
n=a-c;
if(n==0){
  printf("Yes");
}else{
  printf("No");
}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%1d %1d %1d", &a, &b, &c);
 ^