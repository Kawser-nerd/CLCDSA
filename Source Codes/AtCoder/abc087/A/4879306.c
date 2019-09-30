#include<stdio.h>

int main(void){
  int x,a,b;
  scanf("%d",&x );
  scanf("%d",&a );
  scanf("%d",&b );

  x -= a;
  printf("%d",x%b);
  return 0;

} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&x );
   ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a );
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&b );
   ^