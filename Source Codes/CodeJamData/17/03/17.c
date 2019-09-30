#include <stdio.h>
#include <string.h>

int gDebug = 0;

void Solve(long long N, long long K, long long *pMax, long long *pMin);

int main(int argc, char **argv)
{
  int t, T;
  char line[1024];
  long long N, K;
  long long maxVal, minVal;


  T = -1;
  
  gets(line);
  
  sscanf(line, "%d", &T);
  
  for (t = 1; t <= T; t++)
  {
      gets(line);
      
      sscanf(line, "%lld %lld", &N, &K);
      
      if (gDebug)
        printf("t=%d of %d N=%lld K=%lld\n", t, T, N, K);
      
      maxVal = -1;
      minVal = -1;
      
      Solve(N, K, &maxVal, &minVal);
      
      printf("Case #%d: %lld %lld\n", t, maxVal, minVal);
  }  


}

void Solve(long long N, long long K, long long *pMax, long long *pMin)
{
  long long maxVal;
  long long minVal;
  long long newK;
  
  if (gDebug)
  {
    printf("N %lld K %lld\n", N, K);  
  }
  
  if ((N % 2) == 0)
  {
    /* even N */
    maxVal = (N/2);
    minVal = maxVal - 1;
  }
  else
  {
    /* odd N */
    maxVal = (N - 1) / 2;
    minVal = maxVal;
  }
  
  if (gDebug)
  {
    printf("min %lld max %lld\n", minVal, maxVal);
  }
  
  if (K == 1)
  {
    *pMax = maxVal;
    *pMin = minVal;
    return;  
  }

  K = K - 1;

  if (K == 1)
  {
    newK = K;
    Solve(maxVal, newK, pMax, pMin);
  }
  else
  {
      if ((K % 2) == 1)
      {
        /* odd number of people */
        /* Odd ones will go to max, even ones to min */
        /* last one will be odd.  max side gets the last person */
        newK = K / 2;
        newK++;
        Solve(maxVal, newK, pMax, pMin);      
      }
      else
      {
        /* even number of people */
        /* odd numbers will go to max, even will go to min */
        /* last will be even, so will go to min */
        newK = K / 2;
        Solve(minVal, newK, pMax, pMin);            
      }     
  }
  
}
