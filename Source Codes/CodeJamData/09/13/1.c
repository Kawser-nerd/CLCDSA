#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>

// Don't know why these two aren't in math.h
double fmin(double, double);
double fmax(double, double);

//
// A few utility functions might be nice to have around

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


static void init_p(int n, int p[])
{
  int i;
  for(i=0; i<n; i++)
      p[i] = i;
}
static inline void init_c(int n, int k, int p[]) { init_p(k, p); }
static inline void init_cb(int n, int k, int p[], int *b)
{
  *b = (1<<k)-1;
  init_c(n, k, p);
}


static int next_p(int n, int p[])
{
  int i, j, k, t;
  for(i=n-2; i>=0 && p[i]>p[i+1]; i--)
      ;
  if(i<0)
      return 0;
  for(j=i+1, k=n-1; j<k; j++, k--)
    {
      t = p[j];
      p[j] = p[k];
      p[k] = t;
    }
  t = p[i];
  for(j=i+1; p[j]<t; j++)
      ;
  p[i] = p[j];
  p[j] = t;
  return 1;
}


static int next_c(int n, int k, int c[])
{
  int i, t;
  for(i=k-1; i>=0 && ++c[i]>i+n-k; i--)
      ;
  if(i<0)
      return 0;
  for(t=c[i++]; i<k; i++)
      c[i] = ++t;
  return 1;
}


static inline int next_cb(int n, int k, int c[], int *b)
{
  int i, t;
  for(i=k-1; i>=0 && ++c[i]>i+n-k; i--)
      ;
  if(i<0)
      return 0;
  *b &= (1<<(c[i]-1))-1;
  *b |= (((1<<k)-1)>>i)<<c[i];
  for(t=c[i++]; i<k; i++)
      c[i] = ++t;
  return 1;
}
  



// First some boilerplate code

void do_one_case(int);
void init_data(void);


int main(int argc, char **argv)
{
  int N, cnum;
  char buf[100];

  init_data();

  fgets(buf, 100, stdin);
  assert(1==sscanf(buf,"%d\n", &N));

  for(cnum=1; cnum<=N; cnum++)
    {
      do_one_case(cnum);
      fflush(stdout);
    }

  return 0;
}



// And now the guts of my GCJ solution


void init_data()
{
}


double choose(int n, int k)
{
  double x,y;
  int i;

  x = y = 1.0;
  if(n<0 || k<0 || k>n)
      return 0.0;
  for(i=n-k+1; i<=n; i++)
      x *= i;
  for(i=1; i<=k; i++)
      y *= i;
  // printf("C(%d,%d) = %.0f/%.0f = %.2f\n", n,k,x,y,x/y);
  return x/y;
}

void do_one_case(int cnum)
{
  char buf[100];
  int N, C;
  int a, i, k;
  double pt[41][41];
  double p0[41], p1[41];
  double d, e, s;


  fgets(buf, 100, stdin);
  assert(2==sscanf(buf, "%d %d\n", &C, &N));

  d = 1.0 / choose(C, N);

  for(a=0; a<=C; a++)
    {
      for(k=0; a+k<N; k++)
          pt[a][k] = 0.0;
      for(; k<=N && a+k<=C; k++)
        {
          // printf("pt[%d][%d]:  %g * %g / %g\n", a, k, choose(a,N-k), choose(C-a,k), 1.0/d);
          pt[a][k] = d * choose(a, N-k) * choose(C-a, k);
        }
      for(; k<=N; k++)
          pt[a][k] = 0.0;
      s = 0.0;
      for(k=0; k<=N; k++)
          s += pt[a][k];
      /*
      for(k=0; k<=N; k++)
          printf("pt[%d][%d] = %g\n", a, k, pt[a][k]);
      printf("s=%.20f\n", s);
      */
      assert(fabs(s-1.0) < 1e-14);
    }
  /*
  for(i=0; i<=C; i++)
    {
      s = 0.0;
      for(k=0; k<=N && k<=i; k++)
          s += pt[i-k][k];
      printf("s=%.20f\n", s);
      assert(fabs(s-1.0) < 1e-14);
    }
  */

  p0[0] = 1.0;
  for(i=1; i<=C; i++)
      p0[i] = 0.0;

  e = 0.0;
  while(p0[C] < .99999999999)
    {
      /*
      for(i=0; i<=C; i++)
          printf("p0[%d] = %.20f\n", i, p0[i]);
      */
      e += 1.0 - p0[C];
      for(i=0; i<=C; i++)
        {
          s = 0.0;
          for(k=0; k<=N && k<=i; k++)
              s += p0[i-k] * pt[i-k][k];
          p1[i] = s;
        }
      for(i=0; i<=C; i++)
          p0[i] = p1[i];
    }

  printf("Case #%d: %.7f\n", cnum, e);
}
