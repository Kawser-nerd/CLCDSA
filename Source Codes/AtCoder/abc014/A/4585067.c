#include<stdio.h>

int main(void)
{
  int a,b;
  scanf("%d",&a);
  scanf("%d",&b);
  if(a%b==0){
    printf("0\n");
  }else{
    printf("%d\n",b-a%b);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a);
   ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&b);
   ^