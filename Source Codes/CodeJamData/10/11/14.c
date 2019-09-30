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


static char X[50][64];
static char w[256];
static char msg[2][2][8] = {{"Neither", "Blue"}, {"Red", "Both"}};

void scan(int N, int K, int i, int j, int di, int dj)
{
  int k;
  char c, c2;

  k = 1;
  c = X[i][j];
  //printf("---\n%d %d %c %d\n", i, j, c, w[c]);
  i += di;
  j += dj;
  while(i>=0 && i<N && j>=0 && j<N)
    {
      k++;
      c2 = X[i][j];
      if(c2 != c)
          k = 1;
      if(k==K)
          w[c] = 1;
      //printf("%d %d %c %d\n", i, j, c2, w[c2]);
      i += di;
      j += dj;
      c = c2;
    }
}


void do_one_case(int cnum)
{
  int i, j, k, N, K;
  char buf[100];
  
  w['R'] = w['B'] = 0;
  //printf("Case #%d:\n", cnum);

  fgets(buf, 100, stdin);
  assert(2==sscanf(buf,"%d %d\n", &N, &K));
  for(i=0; i<N; i++)
    {
      int l;
      fgets(X[i], 60, stdin);
      //if(strlen(X[i]) != N)
      //    fprintf(stderr, "%d %d %d |%s|\n", N, i, strlen(X[i]), X[i]);
      l = strlen(X[i]);
      assert(l==N+1);
      assert(X[i][l-1]=='\n');
      X[i][l-1] = '\0';
    }

  for(i=0; i<N; i++)
    {
      for(j=k=N-1; j>=0; k--)
        {
          while(j>=0 && X[i][j]=='.')
              j--;
          if(j<0)
              break;
          X[i][k] = X[i][j--];
        }
      while(k>=0)
          X[i][k--] = '.';
    }

  //for(i=0; i<N; i++)
  //    printf("%s\n", X[i]);

  for(i=0; i<N; i++)
    {
      scan(N, K, i, 0, 0, 1);
      scan(N, K, 0, i, 1, 0);
      scan(N, K, i, 0, -1, 1);
      scan(N, K, N-1, i, -1, 1);
      scan(N, K, i, 0, 1, 1);
      scan(N, K, 0, i, 1, 1);
    }

  printf("Case #%d: %s\n", cnum, msg[w['R']][w['B']]);
}
