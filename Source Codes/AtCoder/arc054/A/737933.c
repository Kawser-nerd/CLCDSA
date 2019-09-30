#include <stdio.h>
int main(void)
{
  int l,x,y,s,d;
  int l1,l2,s1,s2;
  int i;
  double m;
  double a,b;
  scanf("%d %d %d %d %d",&l,&x,&y,&s,&d);
  l1=(d-s+l)%l;
  l2=(s-d+l)%l;
  s1=x+y;
  if(y-x>0)
    s2=y-x;
  else
    s2=-1;
  a=(double)l1/(double)s1;
  b=(double)l2/(double)s2;
  if(a>0)
    m=a;
  if(a>b&&b>0)
    m=b;
  printf("%.10f\n",m);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d %d %d",&l,&x,&y,&s,&d);
   ^