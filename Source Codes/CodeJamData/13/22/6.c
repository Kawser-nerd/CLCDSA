#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

double func(int n,int m)
{
  int x,y;
  double z;
  z=0-n*log(2);
  if(m>n/2)m=n-m;
  x=n-m;
  for(y=1;y<=m;y++)z=z+log(y+x)-log(y);
  return exp(z);
}

int main()
{
  int a,b,c,d,e,i,j,k;
  float h;
  double l,m;
  FILE *f,*g;
  f=fopen("b.in","r");
  g=fopen("b.out","w");
  fscanf(f,"%d",&a);
  for(b=1;b<=a;b++)
  {
    fscanf(f,"%d%d%d",&c,&d,&e);
    if(d<0)d=0-d;
    if(e<0)e=0-e;
    i=d+e-1;
    j=0;
    for(;i>0;i--)j=j+i;
    if(d==0){if(j+d+e+d+e+1<=c)h=1;else h=0;}
    else if(j+e+1>c)h=0;
    else if(j+d+e+e+1<=c)h=1;
    else{
      h=0;
      j=c-j;
      for(k=e+1;k<=j;k++)h=h+func(j,k);
    }
    fprintf(g,"Case #%d: ",b);
    fprintf(g,"%f\n",h);
  }
  fclose(f);
  fclose(g);
  return 0;
}