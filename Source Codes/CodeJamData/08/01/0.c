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


#define MAXENG 100
#define MAXQUERY 1000

char name[MAXENG][110];

void do_one_case(int cnum)
{
  int S, Q;
  int i, j;
  char qbuf[110];
  int query[MAXQUERY];
  char avail[MAXENG];
  int navail, nswitch;

  scanf("%d\n", &S);

  for(i=0; i<S; i++)
      gets(name[i]);

  scanf("%d\n", &Q);
  // fprintf(stderr, "S=%d, Q=%d\n", S, Q);

  for(i=0; i<Q; i++)
    {
      gets(qbuf);
      for(j=0; j<S && strcmp(qbuf, name[j]); j++)
          ;
      assert(j<S);
      query[i] = j;
    }

  for(i=0; i<S; i++)
      avail[i] = 1;
  navail = S;
  nswitch = 0;

  for(i=Q-1; i>=0; i--)
    {
      if(avail[query[i]])
        {
          avail[query[i]] = 0;
          navail--;
          if(navail==0)
            {
              nswitch++;
              // fprintf(stderr, "$$%d: %s\n", nswitch, name[query[i]]);
              for(j=0; j<S; j++)
                  avail[j] = 1;
              avail[query[i]] = 0;
              navail = S-1;
            }
        }
    }

  printf("Case #%d: %d\n", cnum, nswitch);
}
