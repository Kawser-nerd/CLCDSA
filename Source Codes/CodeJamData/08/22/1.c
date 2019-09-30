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

#define MAX 1001000
static int head[MAX];

void collapse(int n)
{
  int x, y, z;

  for(x=n; head[x]!=x;)
      x = head[x];
  for(y=n; head[y]!=y;)
    {
      z = head[y];
      head[y] = x;
      y = z;
    }
}

void do_one_case(int cnum)
{
  long long A, B, P0;
  int D, p, f, P;
  int i, n, x, y, z;

  assert(3==scanf("%lld %lld %lld\n", &A, &B, &P0));

  D = B-A+1;
  for(i=0; i<D; i++)
      head[i] = i;
  P = (P0>D) ? D : P0;

  for(p=P; p<D; p++)
    {
      if(p>2 && (p&1)==0)
          continue;
      for(f=3; f*f<=p; f+=2)
          if(p%f == 0)
              break;
      if(f*f <= p)
          continue;

      x = p - (A%p);
      if(x==p) x=0;

      collapse(x);
      z = head[x];
      for(y=x+p; y<D; y+=p)
        {
          //fprintf(stderr, "%lld %lld\n", A+x, A+y);
          collapse(y);
          head[head[y]] = z;
        }
    }

  for(i=0; i<D; i++)
      collapse(i);

  for(i=n=0; i<D; i++)
      if(head[i]==i)
        {
          //fprintf(stderr, "%lld ", A+i);
          n++;
        }

  printf("Case #%d: %d\n", cnum, n);
}
  
