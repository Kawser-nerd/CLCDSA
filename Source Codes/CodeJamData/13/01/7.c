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


void check_quad(char *x, int *xwon, int *ywon, int *dot)
{
  int i;
  int xx=1, oo=1;

  for(i=0; i<4; i++)
    {
      switch(x[i])
        {
          case 'X':
              oo = 0;
              break;
          case 'O':
              xx = 0;
              break;
          case 'T':
              break;
          case '.':
              xx = oo = 0;
              *dot = 1;
              break;
          default:
              assert(0);
        }
    }

  if(xx)
      *xwon = 1;
  else if(oo)
      *ywon = 1;
}


void do_one_case(int cnum)
{
  char b[4][8];
  char t[4];
  int i,j;
  int xwon=0, owon=0, dot=0;

  for(i=0; i<4; i++)
    {
      fgets(b[i], 7, stdin);
      assert(strlen(b[i])==5 && b[i][4]=='\n');
    }

  for(i=0; i<4; i++)
      check_quad(b[i], &xwon, &owon, &dot);
  for(j=0; j<4; j++)
    {
      for(i=0; i<4; i++)
          t[i] = b[i][j];
      check_quad(t, &xwon, &owon, &dot);
    }
  for(i=0; i<4; i++)
      t[i] = b[i][i];
  check_quad(t, &xwon, &owon, &dot);
  for(i=0; i<4; i++)
      t[i] = b[i][3-i];
  check_quad(t, &xwon, &owon, &dot);

  assert(!(xwon && owon));

  printf("Case #%d: ", cnum);
  if(xwon)
      printf("X won\n");
  else if(owon)
      printf("O won\n");
  else if(dot)
      printf("Game has not completed\n");
  else
      printf("Draw\n");

  fgets(b[0], 7, stdin);
}
