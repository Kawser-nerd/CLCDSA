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


void do_one_case(int cnum)
{
  char buf[200];
  char A[128][128];
  double wp[128], owp[128], oowp[128];
  int w[128], l[128];
  int i,j,N;

  fgets(buf, 100, stdin);
  assert(1==sscanf(buf,"%d\n", &N));

  for(i=0; i<N; i++)
    {
      fgets(A[i], 120, stdin);
      assert(N+1==strlen(A[i]));
      assert(A[i][N]=='\n');
    }

  for(i=0; i<N; i++)
    {
      w[i] = l[i] = 0;
      for(j=0; j<N; j++)
          if(A[i][j]=='0')
              l[i]++;
          else if(A[i][j]=='1')
              w[i]++;
      wp[i] = w[i] / ((double) w[i] + l[i]);
    }
  for(i=0; i<N; i++)
    {
      double s = 0.0;

      for(j=0; j<N; j++)
          if(A[i][j]=='0')
              s += (w[j] - 1.0) / (w[j] + l[j] - 1.0);
          else if(A[i][j]=='1')
              s += w[j] / (w[j] + l[j] - 1.0);
      owp[i] = s / (w[i] + l[i]);
    }
  for(i=0; i<N; i++)
    {
      double s = 0.0;

      for(j=0; j<N; j++)
          if(A[i][j]!='.')
              s += owp[j];
      oowp[i] = s / (w[i] + l[i]);
    }

  printf("Case #%d:\n", cnum);
  for(i=0; i<N; i++)
      printf("%.12g\n", .25*wp[i] + .5*owp[i] + .25*oowp[i]);
}
