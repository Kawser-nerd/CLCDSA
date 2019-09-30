#include<stdio.h>
#include<stdlib.h>

long long dp[500][500]; //highest,rank
long long binom[500][500];


int main()
{

  for(int i = 0; i < 500; i++)
    {
      for(int j = 0; j < 500; j++)
	{
	  if(j>i)
	    continue;

	  if(j==0)
	    binom[i][j] = 1;
	  else
	    binom[i][j] = binom[i-1][j]+binom[i-1][j-1];

	}
    }

  
  dp[2][1] = 1;

  for(int n = 3; n < 500; n++)
    {
      for(int k = 1; k < n; k++)
	{
	  if(k==1)
	    {
	      dp[n][k] += 1;
	    }
	  for(int l = 1; l < k; l++)
	    {
	      int r = n-k-1;
	      int s = k-l-1;
	      dp[n][k] += binom[r][s]*dp[k][l];
	      dp[n][k] %= 100003;
	    }
	}
    }


  int N;
  scanf("%d",&N);
  for(int i = 1; i <= N; i++)
    {
      int k;
      scanf("%d",&k);
      int sum = 0;
      for(int j = 0; j < 500; j++)
	{
	  sum += dp[k][j];
	  sum %= 100003;
	}
      printf("Case #%d: %d\n",i,sum);
    }

  return 0;
}
