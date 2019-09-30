#include <stdio.h>
int main(void){
int a,b,c;
  scanf("%d %d %d",&a,&b,&c);
  
  
  
  
  if(a>=b&&b>=c){printf("%d",a*10+b+c); return 0;}//a>b>c
  if(a>=c&&c>=b){printf("%d",a*10+b+c);return 0;}//a>c>b
   if(b>=a&&a>=c){printf("%d",b*10+a+c);return 0;}//b>a>c
  if(b>=c&&c>=a){printf("%d",b*10+a+c);return 0;}//b>c>a
   if(c>=b&&b>=a){printf("%d",c*10+b+a);return 0;}//c>b>a
  if(c>=a&&a>=b){printf("%d",c*10+b+a);return 0;}//c>a>b
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a,&b,&c);
   ^