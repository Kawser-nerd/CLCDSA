#include<stdio.h>

int main(void)
{
  int a,b;
  int temp;
  int i;
  int digit=0;
  scanf("%d%d",&a,&b);
  temp=b;
  while(b>0)
    {
      b/=10;
      digit++;
    }
  
  for(i=0;i<digit;i++){
    a=a*10;
  }

  printf("%d\n",(a+temp)*2);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&a,&b);
   ^