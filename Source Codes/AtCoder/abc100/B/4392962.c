#include<stdio.h>

int main(void)
{
 int d,n;
 int i,s;

 scanf("%d%d", &d,&n);

 if(n==100) n++;

   if(d==0) s=n;

 else if(d==1) s=n*100;

 else if(d==2) s=n*100*100;

 printf("%d\n", s);
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &d,&n);
  ^