#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>


void do_one_case(int);


int main(int argc, char **argv)
{
  int N, cnum;

  scanf("%d\n", &N);

  for(cnum=1; cnum<=N; cnum++)
    {
      do_one_case(cnum);
    }

  return 0;
}


#define MAXTRIP 100
#define MAXTRAIN 200

void do_one_case(int cnum)
{
  int i, j, k;
  int T, N[2];
  int hh1, mm1, hh2, mm2;
  struct {
      int start;
      int end; } trip[2][MAXTRIP];
  int event[MAXTRAIN];

  scanf("%d\n", &T);
  scanf("%d %d\n", &N[0], &N[1]);

  for(i=0; i<2; i++)
      for(j=0; j<N[i]; j++)
        {
          assert(4==scanf("%d:%d %d:%d\n", &hh1, &mm1, &hh2, &mm2));
          trip[i][j].start = 60*hh1 + mm1;
          trip[i][j].end = 60*hh2 + mm2;
        }

  printf("Case #%d:", cnum);
  for(i=0; i<2; i++)
    {
      int n, m, t;

      for(j=0; j<N[i]; j++)
          event[j] = 2*trip[i][j].start + 1;
      for(j=0; j<N[1-i]; j++)
          event[j + N[i]] = 2*(trip[1-i][j].end + T);

      for(j=1; j<N[0]+N[1]; j++)
        {
          t = event[j];
          for(k=j; k>0 && event[k-1]>t; k--)
              event[k] = event[k-1];
          event[k] = t;
        }

      n = m = 0;
      for(j=0; j<N[0]+N[1]; j++)
        {
          if(event[j]&1)
            {
              if(++n > m)
                  m = n;
            }
          else
              --n;
        }
      printf(" %d", m);
    }
  printf("\n");
}




