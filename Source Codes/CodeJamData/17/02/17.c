#include <stdio.h>
#include <string.h>

int gDebug = 0;

int IsTidy(long long N);
long long SolveLarge(char *p);

int main(int argc, char **argv)
{
  int t, T;
  char line[1024];
  long long N;
  long long tidy;

  T = -1;
  
  gets(line);
  
  sscanf(line, "%d", &T);
  
  for (t = 1; t <= T; t++)
  {
      gets(line);
      
      if (gDebug)
        printf("[%s]\n", line);
      
      tidy = SolveLarge(line);      
      
      printf("Case #%d: %lld\n", t, tidy);
  }  


}

long long SolveLarge(char *p)
{
  int len, i, j;
  long long tidy;
  char pCopy[80];
  int a, b;
  
  /* add a leading 0 */
  strcpy(pCopy, "0");
  strcat(pCopy, p);
  
  len = strlen(pCopy);

  if (gDebug)
    printf("START [%s]\n", pCopy);
  
  for(i = len-1; i > 0; i--)
  {
    a = pCopy[i-1];
    b = pCopy[i];
    
    /* Digits ab.  Not tidy if a>b */
    
    if (a > b)
    {
      /* a is guaranteed to be non-zero */
      pCopy[i-1] = a - 1;
      
      for (j = i; j < len; j++)
        pCopy[j] = '9';
    }
  }
  

  if (gDebug)
    printf("END [%s]\n", pCopy);


  
  /* convert to long long to remove leading zeroes and also to check with IsTidy */
  sscanf(pCopy, "%lld", &tidy);

  /* sanity check */
  
  if (IsTidy(tidy))
    return tidy;

  /* should never get here */

  printf("Error: N [%s] tidy %lld\n", p, tidy);

  return -1;
}

int IsTidy(long long N)
{
  while (N > 9)
  {
    int d1, d10;
    
    d1 = N % 10;
    d10 = (N / 10) % 10;
    if (d1 < d10)
      return 0;
    N = N / 10;
  }

  return 1;
}
