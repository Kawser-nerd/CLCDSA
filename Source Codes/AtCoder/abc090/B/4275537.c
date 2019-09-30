#include<stdio.h>

int main()
{
  int a,b,i,j,k=0;
  
  scanf("%d %d",&a,&b);
  
  for(i=a;i<=b;i++){
    int s = i/10000;
    int d = i % 10000;
    int s2 = d / 1000;
    int d2 = d % 1000;
    int s3 = d2 / 100;
    int d3 = d2 % 100;
    int s4 = d3 / 10;
    int d4 = d3 % 10;
    if(s == d4 && s2 == s4)
      k++;
  }
  
  printf("%d\n",k);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&a,&b);
   ^