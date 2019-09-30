#include<stdio.h>
#include<math.h>
int main(){
  int n;
  scanf("%d",&n);
  n=(int)sqrt(n);
  printf("%d",n*n);
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^