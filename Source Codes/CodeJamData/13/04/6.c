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


#define MAXN 20
#define MAX2N (1<<MAXN)
#define MAXK 200
#define MAXTK 40


void do_one_case(int cnum)
{
  char buf[1000];
  char *word[50];
  static unsigned char next[MAX2N];
  int type[MAXN];
  int keys[MAXN][MAXK];
  int ikeys[MAXK];
  //int kk[MAXK];
  int p[MAXN];
  int N, K;
  int i, ii, j, jj, k, l, n, b, ti;

  fgets(buf, 100, stdin);
  assert(2==sscanf(buf,"%d %d\n", &K, &N));

  for(i=0; i<MAXK; i++)
      ikeys[i] = 0;
  for(i=0; i<MAXN; i++)
      for(j=0; j<MAXK; j++)
          keys[i][j] = 0;
  
  fgets(buf, 1000, stdin);
  l = split(buf, 50, word, " \n");
  assert(l<=MAXTK && l==K);
  for(i=0; i<l; i++)
    {
      j = atoi(word[i]);
      assert(j>=1 && j<=MAXK);
      ikeys[j-1]++;
    }
  for(i=0; i<N; i++)
    {
      fgets(buf, 1000, stdin);
      l = split(buf, 50, word, " \n");
      k = atoi(word[0]);
      assert(k>=1 && k<=MAXK);
      type[i] = k-1;
      k = atoi(word[1]);
      assert(k>=0 && k<=MAXTK && l==k+2);
      for(j=2; j<l; j++)
        {
          k = atoi(word[j]);
          assert(k>=1 && k<=MAXK);
          keys[i][k-1]++;
        }
      keys[i][type[i]]--;
    }

  memset(next, 255, 1<<N);
  next[(1<<N)-1] = 222;

  for(n=N; n>0; n--)
    {
      init_cb(N, n, p, &b);
      do
        {
          if(next[b] > 250)
              continue;

          for(i=0; i<n; i++)
            {
              ii = p[i];
              ti = type[ii];
              k = ikeys[ti] - keys[ii][ti];
              for(j=0; j<n; j++)
                {
                  jj = p[j];
                  k += keys[jj][ti];
                }
              if(k>0)
                {
                  int bb = b & ~(1<<ii);
                  if(next[bb] > ii)
                      next[bb] = ii;
                }
            }
        }
      while(next_cb(N, n, p, &b));
    }
  printf("Case #%d:", cnum);
  if(next[0] > 250)
    {
      printf(" IMPOSSIBLE\n");
      return;
    }
  b = 0;
  for(i=0; i<N; i++)
    {
      j = next[b];
      assert(j<N);
      printf(" %d", j+1);
      b |= 1<<j;
    }
  assert(b+1 == 1<<N);
  assert(next[b] == 222);
  printf("\n");
}
