#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
  int N, K;
  char str[1050], str2[1050];
  int p[10];
  int i, j, len, n, c, min;
  
  scanf(" %d", &N);
  for(n = 0; n < N; n++)
    {
      scanf(" %d", &K);
      scanf(" %s", str);
      
      len = strlen(str);
      
      min = 100000;
      switch(K)
        {
        case 2:
          for(p[0] = 0; p[0] < K; p[0]++)
        for(p[1] = 0; p[1] < K; p[1]++)
          if(p[1] != p[0])
                        {
                          for(i = 0; i < len / K; i++)
                            {
                              for(j = 0; j < K; j++)
                                {
                                  str2[i * K + p[j]] = str[i * K + j];
                                }
                            }
                          c = 0;
                          for(i = 1; i < len; i++)
                            {
                              if(str2[i] != str2[i - 1])
                                {
                                  c++;
                                }
                            }
                          if(c < min)
                            {
                              min = c;
                            }
                        }
      
          break;
        case 3:
          for(p[0] = 0; p[0] < K; p[0]++)
        for(p[1] = 0; p[1] < K; p[1]++)
          if(p[1] != p[0])
            for(p[2] = 0; p[2] < K; p[2]++)
              if(p[2] != p[0] && p[2] != p[1])
                        {
                          for(i = 0; i < len / K; i++)
                            {
                              for(j = 0; j < K; j++)
                                {
                                  str2[i * K + p[j]] = str[i * K + j];
                                }
                            }
                          c = 0;
                          for(i = 1; i < len; i++)
                            {
                              if(str2[i] != str2[i - 1])
                                {
                                  c++;
                                }
                            }
                          if(c < min)
                            {
                              min = c;
                            }
                        }
      
          break;
        case 4:
          for(p[0] = 0; p[0] < K; p[0]++)
            for(p[1] = 0; p[1] < K; p[1]++)
              if(p[1] != p[0])
                for(p[2] = 0; p[2] < K; p[2]++)
                  if(p[2] != p[0] && p[2] != p[1])
                    for(p[3] = 0; p[3] < K; p[3]++)
                      if(p[3] != p[0] && p[3] != p[1] && p[3] != p[2])
                        {
                          for(i = 0; i < len / K; i++)
                            {
                              for(j = 0; j < K; j++)
                                {
                                  str2[i * K + p[j]] = str[i * K + j];
                                }
                            }
                          str2[len] = 0;
                          c = 0;
                          for(i = 1; i < len; i++)
                            {
                              if(str2[i] != str2[i - 1])
                                {
                                  c++;
                                }
                            }
                          if(c < min)
                            {
                              min = c;
                            }
                        }
      
          break;
        case 5:
          for(p[0] = 0; p[0] < K; p[0]++)
        for(p[1] = 0; p[1] < K; p[1]++)
          if(p[1] != p[0])
            for(p[2] = 0; p[2] < K; p[2]++)
              if(p[2] != p[0] && p[2] != p[1])
                for(p[3] = 0; p[3] < K; p[3]++)
                  if(p[3] != p[0] && p[3] != p[1] && p[3] != p[2])
                    for(p[4] = 0; p[4] < K; p[4]++)
                      if(p[4] != p[0] && p[4] != p[1] && p[4] != p[2] && p[4] != p[3])
                        {
                          for(i = 0; i < len / K; i++)
                            {
                              for(j = 0; j < K; j++)
                                {
                                  str2[i * K + p[j]] = str[i * K + j];
                                }
                            }
                          c = 0;
                          for(i = 1; i < len; i++)
                            {
                              if(str2[i] != str2[i - 1])
                                {
                                  c++;
                                }
                            }
                          if(c < min)
                            {
                              min = c;
                            }
                        }
      
          break;
          
        }
      printf("Case #%d: %d\n", n + 1, min + 1);
    }
  return 0;
}
