#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>


inline static double fsqr(double x) { return x*x; }
inline static int isqr(int x) { return x*x; }
inline static int imin(int x, int y) { return x<y ? x : y; }
inline static int imax(int x, int y) { return x>y ? x : y; }


static int split(char *s, int m, char **v, char *r)
{
  int n=0;
  char *x;

  for(x=s;;)
    {
      while(*x && strchr(r, *x))
          x++;
      if(!*x)
          break;
      assert(n<m);
      v[n++] = x;
      while(*x && !strchr(r, *x))
          x++;
      if(!*x)
          break;
      *x++ = 0;
    }
  return n;
}


static int splitn(char *s, int m, char **v, char *r)
{
  int n=0;
  char *x;

  for(x=s;;)
    {
      assert(n<m);
      v[n++] = x;
      while(*x && !strchr(r, *x))
          x++;
      if(!*x)
          break;
      *x++ = 0;
    }
  return n;
}




void do_one_case(int);


int main(int argc, char **argv)
{
  int N, cnum;
  char buf[100];

  fgets(buf, 100, stdin);
  assert(1==sscanf(buf,"%d\n", &N));

  for(cnum=1; cnum<=N; cnum++)
    {
      do_one_case(cnum);
    }

  return 0;
}


void do_one_case(int cnum)
{
  int K, N, r, d;
  int p, k, i;

  printf("Case #%d:", cnum);
  scanf("%d\n", &K);
  scanf("%d", &N);
  for(r=0; r<N; r++)
    {
      scanf("%d", &d);
      p = 0;
      k = K;
      for(i=1; i<=K; i++)
        {
          p += i;
          if(p>k)
            {
              p = 1 + ((p-1)%k);
            }
          if(p==d)
            {
              printf(" %d", i);
              break;
            }
          else if(p<d)
              d--;
          p--;
          k--;
        }
    }
  printf("\n");
}
