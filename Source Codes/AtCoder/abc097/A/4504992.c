#include<stdio.h>
int main(void)
{
  int a, b, c, n;
  scanf("%d %d %d %d", &a, &b, &c, &n);
  if(abs(b-a)<=n&&abs(c-b)<=n||abs(c-a)<=n){
    printf("Yes\n");
  }else{
    printf("No\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:6: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
   if(abs(b-a)<=n&&abs(c-b)<=n||abs(c-a)<=n){
      ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d", &a, &b, &c, &n);
   ^