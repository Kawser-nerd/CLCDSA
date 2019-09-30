#include<stdio.h>
#include<stdlib.h>

int used[1000];
int groups[1000];
long long moneyat[1000];
int stepsat[1000];


int main()
{
  long long money = 0;
  
  int T;
  scanf("%d",&T);

  for(int times = 1; times <= T; times++)
    {
      for(int i = 0; i < 1000; i++)
	{
	  used[i] = 0;
	  stepsat[i] = 0;
	  moneyat[i] = 0;
	}
      money = 0;

      int R,k,N;
      scanf("%d %d %d",&R,&k,&N);

      for(int i = 0; i < N; i++)
	scanf("%d",&groups[i]);

      int r = 0;
      int idx = 0;

      while(true)
	{
	  if(used[idx]==2)
	    break;
	  if(r==R)
	    {
	      break;
	    }
	  
	  int startidx = idx;

	  used[idx]++;
	  
	  moneyat[idx] = money;
	  stepsat[idx] = r;

	  int inride = groups[idx];
	  idx++;
	  idx %= N;

	  while(inride+groups[idx]<= k && idx != startidx)
	    {
	      inride += groups[idx];
	      idx++;
	      idx %= N;
	    }

	  money += inride;

	  r++;
	}

      money -= moneyat[idx];
      R -= stepsat[idx];
      money *= R/(r-stepsat[idx]);
      R %= r-stepsat[idx];
      money += moneyat[idx];
      
      for(int i = 0; i < R; i++)
	{
	  
	  int startidx = idx;
	  int inride = groups[idx];
	  idx++;
	  idx %= N;

	  while(inride+groups[idx]<= k && idx != startidx)
	    {
	      inride += groups[idx];
	      idx++;
	      idx %= N;
	    }

	  money += inride;
	}

      printf("Case #%d: %lld\n",times, money);
    }

  return 0;
}
