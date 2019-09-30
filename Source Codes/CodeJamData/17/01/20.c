#include <stdio.h>
#include <string.h>

int gDebug = 0;

int main(int argc, char **argv)
{
  int t, T;
  char line[1024];
  char S[1001];
  char count[1000];
  int len;
  int K;
  int flips;

  T = -1;
  
  gets(line);
  
  sscanf(line, "%d", &T);
  
  for (t = 1; t <= T; t++)
  {
    int i = 0;
    flips = 0;
    if (gDebug)
    {
      printf("t=%d of %d\n", t, T);    
    }
  
    gets(line);
    sscanf(line, "%s %d", S, &K);
  
    if (gDebug)
    {
      printf("[%s] [%d]\n", S, K);
    }
  
    len = strlen(S);
    
    for (i = 0; i < len; i++)
    {
      if (S[i] == '+')
        count[i] = 0;
      else
        count[i] = 1;    
      if (gDebug)
        printf("%d", count[i]);
    }
    if (gDebug)
      printf("\n");
        
    i = 0;
    while (i < len)
    {
      while ( ((count[i] % 2) == 0) && (i < len) )
        i++;
      
      if (gDebug)
        printf("i = %d\n", i);
      
      if (i + K <= len)
      {
        int j;
        for (j = i; j < i + K; j++)
        {
          count[j]++;
        }
        i++;
        flips++;
      } else if (i == len)
      {
        /* made it to the end.  all happy */
      }
      else
      {
        flips = -1;
        break;
      }
    }
 
    if (flips == -1)
      printf("Case #%d: IMPOSSIBLE\n", t);
    else 
      printf("Case #%d: %d\n", t, flips);
  }  


}
