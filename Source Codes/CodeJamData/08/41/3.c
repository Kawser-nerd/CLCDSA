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
  int M, V;
  int i, j, k, l, t;

  const int logic[2][2][2] = {{{0,1},{1,1}},{{0,0},{0,1}}};
  double cost[11000][2];
  int gate[11000], change[11000];

  scanf("%d %d\n", &M, &V);
  for(i=0; 2*i<M-2; i++)
      scanf("%d %d\n", &gate[i], &change[i]);
  for(; i<M; i++)
    {
      scanf("%d\n", &t);
      cost[i][t] = 0;
      cost[i][1-t] = 1e30;
    }
  for(i=(M-1)>>1; --i>=0;)
    {
      cost[i][0] = cost[i][1] = 1e20;
      for(j=0; j<2; j++)
          for(k=0; k<2; k++)
              for(l=0; l<2; l++)
                {
                  double x = cost[2*i+1][k] + cost[2*i+2][l] + (j!=gate[i])*(1+(!change[i])*1e25);
                  if(x<cost[i][logic[j][k][l]])
                     cost[i][logic[j][k][l]] = x;
                  // cost[i][logic[j][k][l]] = fmin(cost[i][logic[j][k][l]], x);
                }
    }

#if 0
  for(i=0; i<M; i++)
      fprintf(stderr, "%d %g %g\n", i, cost[i][0], cost[i][1]);
#endif

  if(cost[0][V] > M)
      printf("Case #%d: IMPOSSIBLE\n", cnum);
  else
      printf("Case #%d: %.0f\n", cnum, cost[0][V]);
}

