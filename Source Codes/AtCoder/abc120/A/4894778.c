#include<stdio.h>
int main(void)
{
  int a,b,c,d,i;

  scanf("%d %d %d",&a,&b,&c);
  if(1>a) return 1;
  else if (c>100) return 1;
  for(i=0;i<c;i=i+a){
    d=b/a;
  }
  if(d>=c) printf("%d\n",c);
  else if(d==0) printf("%d\n",d);
  else printf("%d\n",d);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d",&a,&b,&c);
   ^