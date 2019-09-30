#include <stdio.h>
int main(void){
  int a,b;
  // a en wo b en bun hikeru.
  scanf("%d",&a);
    scanf("%d",&b);
  (a%500)<=b ? printf("Yes") : printf("No");
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b);
     ^