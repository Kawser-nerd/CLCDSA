#include<stdio.h>

int main(void)
{
  int n;
  int i;
  scanf("%d",&n);
  int a,b,c,d;

  a=0;
  b=0;
  c=1;
  d=0;

  for(i=0;i<(n/4);i++)
    {
      d=(a+b+c)%10007;
      a=(b+c+d)%10007;
      b=(c+d+a)%10007;
      c=(d+a+b)%10007;
    }
  
  if(n%4==1){
    printf("%d\n",a);
  }else if(n%4==2){
    printf("%d\n",b);
  }else if(n%4==3){
    printf("%d\n",c);
  }else if(n%4==0){
    printf("%d\n",d);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^