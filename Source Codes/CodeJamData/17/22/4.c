#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include <ctype.h>
#include <errno.h>
#include <limits.h>

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


#define IBSZ 1000000
#define MAXW 20000
static char ibuf[IBSZ];
static char *iword[MAXW];

static int rdints(int m, int *x)
{
  int i, n;
  long y;
  char *p;

  m = imin(m, MAXW);
  assert(fgets(ibuf, IBSZ, stdin));
  n = split(ibuf, m, iword, " \n");
  errno = 0;
  for(i=0; i<n; i++)
    {
      assert(iword[i][0]);
      y = strtol(iword[i], &p, 10);
      assert(!errno);
      assert(!*p);
      assert(y>=INT_MIN && y<=INT_MAX);
      x[i] = y;
    }
  return n;
}

static void rdnints(int m, int *x)
{
  int n;

  n = rdints(m, x);
  assert(n==m);
}

static int rd1int()
{
  int n;

  rdnints(1, &n);
  return n;
}





// First some boilerplate code

void do_one_case(int);
void init_data(void);


int main(int argc, char **argv)
{
  int T, cnum;

  init_data();

  T = rd1int();
  for(cnum=1; cnum<=T; cnum++)
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


static char s[1001][1001][1001][3];
static char color[] = "RYB";

void do_one_case(int cnum)
{
  int q[7];
  int N, R, Y, B, O, V, G;
  int h, i, j, k, l, n;

  rdnints(7, q);
  N = q[0];
  R = q[1];
  O = q[2];
  Y = q[3];
  G = q[4];
  B = q[5];
  V = q[6];
  assert(N==R+O+Y+G+B+V);
  assert(G+O+V==0);
  assert(N<=1000);
  assert(N>=3);
  /*
  for(i=0; i<=R; i++)
      for(j=0; j<=Y; j++)
          for(k=0; k<=B; k++)
              for(l=0; l<3; l++)
                  s[i][j][k][l] = 0;
  */
  for(h=0; h<3; h++)
    {
      //s[h==0][h==1][h==2][h] = 1;
      //for(n=2; n<=N; n++)
      for(l=0; l<3; l++)
          s[0][0][0][l] = 0;
      s[0][0][0][h] = 1;
      for(n=1; n<=N; n++)
          for(i=0; i<=imin(n,R); i++)
              for(j=0; j<=imin(n-i,Y); j++)
                {
                  k = n-i-j;
                  if(k>=0 && k<=B)
                    {
                      for(l=0; l<3; l++)
                        {
                          int ii, jj, kk;
                          ii = i - (l==0);
                          jj = j - (l==1);
                          kk = k - (l==2);
                          if(ii>=0 && jj>=0 && kk>=0)
                              s[i][j][k][l] = s[ii][jj][kk][(l+1)%3] 
                                            | s[ii][jj][kk][(l+2)%3];
                        }

                    }
                }
      if(s[R][Y][B][h])
        {
          for(i=0; i<=R; i++)
              for(j=0; j<=Y; j++)
                  for(k=0; k<=B; k++)
                      for(l=0; l<3; l++)
                          if(0)
                              fprintf(stderr, "%d %d %d %d: %d\n", i, j,k,l, s[i][j][k][l]);
          printf("Case #%d: ", cnum);
          i = R;
          j = Y;
          k = B;
          l = h;
          while(i+j+k)
            {
              putchar(color[l]);
              i -= (l==0);
              j -= (l==1);
              k -= (l==2);
              if(s[i][j][k][(l+1)%3])
                  l = (l+1)%3;
              else if(s[i][j][k][(l+2)%3])
                  l = (l+2)%3;
              else
                  assert(0);
            }
          putchar('\n');
          return;
        }
    }
  printf("Case #%d: IMPOSSIBLE\n", cnum);
}
