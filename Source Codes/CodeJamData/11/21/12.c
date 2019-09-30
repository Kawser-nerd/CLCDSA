#include<stdio.h>
int games[105],wins[105];
char s[105][105];
double wp[105],owp[105],oowp[105],rti[105];
int main()
{
  int t,n,i,j,test=1;
  scanf("%d",&t);
  while(t--)
    {
      scanf("%d",&n);
      for(i=0;i<n;i++)
	{
	  scanf("%s",s[i]);
	  wins[i]=games[i]=0;
	  for(j=0;j<n;j++)
	    {
	      if(s[i][j]=='1')
		wins[i]++;
	      if(s[i][j]!='.')
		games[i]++;
	    }
	  wp[i]=(double)wins[i]/(double)games[i];
	}
      printf("Case #%d:\n",test++);
      for(i=0;i<n;i++)
	{
	  owp[i]=0.0;
	  for(j=0;j<n;j++)
	    {
	      if(s[i][j]!='.')
		{
		  if(s[i][j]=='1')
		    owp[i]+=(double)(wins[j])/(double)(games[j]-1);
		  else
		    owp[i]+=(double)(wins[j]-1)/(double)(games[j]-1);
		  //owp[i]+=(double)wp[j];
		  //games++;
		}
	    }
	  owp[i]/=(double)games[i];
	}
      for(i=0;i<n;i++)
	{
	  oowp[i]=0.0;
	  for(j=0;j<n;j++)
	    {
	      if(s[i][j]!='.')
		{
		  oowp[i]+=(double)owp[j];
		  //games++;
		}
	    }
	  oowp[i]/=(double)games[i];
	}
      for(i=0;i<n;i++)
	{
	  rti[i]=0.25*wp[i]+0.50*owp[i]+0.25*oowp[i];
	  printf("%.8lf\n",rti[i]);
	}
    }
  return 0;
}
