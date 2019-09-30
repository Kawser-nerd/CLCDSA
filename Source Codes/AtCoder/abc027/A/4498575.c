#include <stdio.h>
int main(void){
int a,b,c,d;
  scanf("%d",&a);
    scanf("%d",&b);
    scanf("%d",&c);
  if(a==b&&a!=c){printf("%d\n",c);return 0;}
  if(a==c&&a!=b){printf("%d\n",b);return 0;}
  if(b==c&&b!=a){printf("%d\n",a);return 0;}
printf("%d\n",a);return 0;
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
./Main.c:5:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&b);
     ^
./Main.c:6:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&c);
     ^