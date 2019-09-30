#include<stdio.h>

int main(void)
{
  int a;
  int b;

  scanf("%d",&a);
  scanf("%d",&b);

  if(a>b){
    printf("%d\n",(a-b)<(b+10-a)?a-b:b+10-a);
  }

   if(b>a){
     printf("%d\n",(b-a)<(a+10-b)?b-a:a+10-b);
   }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&b);
   ^