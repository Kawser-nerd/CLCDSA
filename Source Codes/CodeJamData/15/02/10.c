#include<stdio.h>

int main()
{
  int t,m,d,p[1010],max,i,tem,j,ans,q=1;
  scanf("%d",&t);

  while(t--)
  {
      max=0;
      scanf("%d",&d);
      for(i=0;i<d;i++)
      {
        scanf("%d",&p[i]);
        if(p[i]>max) max=p[i];
      }
      ans=max;
      for(i=1;i<=max;i++)
      {
          tem=i;
          for(j=0;j<d;j++)
            if(p[j]%i==0)
              tem+=p[j]/i-1;
            else
              tem+=p[j]/i;
        if(ans>tem) ans=tem;
      }
      printf("Case #%d: %d\n",q++,ans);
  }
  return 0;
}
