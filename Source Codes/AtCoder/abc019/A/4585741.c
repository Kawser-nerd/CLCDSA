#include<stdio.h>

int main(void)
{
  int a,b,c;
  scanf("%d%d%d",&a,&b,&c);

  if(a==b||a==c){
     printf("%d\n",a);
  }else if(b==c){
     printf("%d\n",b);
  }else  if((b-a)*(c-a)<0){
    printf("%d\n",a);
  }else if((a-b)*(c-b)<0){
    printf("%d\n",b);
  }else  if((b-c)*(a-c)<0){
    printf("%d\n",c);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^