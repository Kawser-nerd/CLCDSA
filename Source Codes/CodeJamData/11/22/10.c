#include<stdio.h>
int p[205],v[205];
double a[10005];
double max(double x,double y)
{
  if(x<y)
    return y;
  else
    return x;
}
int main()
{
  int k,i,n,l,j,test=1;
  scanf("%d",&k);
  double t,x;
  while(k--)
    {
      scanf("%d %lf",&n,&t);
      l=0;
      for(i=0;i<n;i++)
	{
	  scanf("%d %d",&p[i],&v[i]);
	  for(j=0;j<v[i];j++)
	    a[l++]=(double)p[i];
	}
      n=l;
      double lo=0,hi=1;
      while(1)
	{
	  x=a[0]-hi;
	  //x=max(a[0]-hi,0.0);
	  for(i=1;i<n;i++)
	    {
	      if(a[i]+hi<x+t)break;
	      x=max(a[i]-hi,x+t);
	    }
	  if(i<n)
	    hi*=2;
	  else
	    break;
	}
      while(hi-lo>1e-8)
	{
	  double mid=(lo+hi)/2;
	  x=a[0]-mid;
	  //x=max(a[0]-mid,0.0);
	  for(i=1;i<n;i++)
	    {
	      if(a[i]+mid<x+t)break;
	      x=max(a[i]-mid,x+t);
	    }
	  if(i<n)
	    lo=mid;
	  else
	    hi=mid;
	}
      printf("Case #%d: %.8lf\n",test++,lo);
    }
  return 0;
}
