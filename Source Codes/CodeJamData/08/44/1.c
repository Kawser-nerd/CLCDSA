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


static int bc[65536];

void initbc()
{
  static init=0;
  int i, j;

  if(init)
      return;

  bc[0] = 0;

  for(i=1; i<65536; i*=2)
      for(j=0; j<i; j++)
          bc[i+j] = 1 + bc[j];

  init = 1;
}


void do_one_case(int cnum)
{
  static int R[65536][16][16];
  int C[16][16];
  int C2[16][16];
  static char S[60000];
  int k,l,ll;
  int i,j,n,m, i1,i2,i3, ss, nn;

  initbc();

  scanf("%d\n", &k);
  scanf("%s\n", S);
  l = strlen(S);
  assert(l%k == 0);
  ll = l/k;

  for(i=0; i<k; i++)
      for(j=0; j<k; j++)
        {
          for(n=m=0; m<l; m+=k)
              n += S[m+i] != S[m+j];
          C[i][j] = n;
          for(n=m=0; m+k<l; m+=k)
              n += S[m+i] != S[m+k+j];
          C2[i][j] = n;
        }

  nn = 1<<k;
  for(i=0; i<nn; i++)
      for(i1=0; i1<k; i1++)
          for(i2=0; i2<k; i2++)
              R[i][i1][i2] = 1000000;
  for(i1=0; i1<k; i1++)
    {
      i = 1<<i1;
      R[i][i1][i1] = 0;
    }

  for(ss=2; ss<=k; ss++)
      for(i=0; i<nn; i++)
          if(bc[i]==ss)
            {
              for(i1=0; i1<k; i1++)
                  if(i & (1<<i1))
                      for(i2=0; i2<k; i2++)
                          if(i&(1<<i2) && i1!=i2)
                            {
                              m = 10000000;
                              for(i3=0; i3<k; i3++)
                                  if(i&(1<<i3) && i1!=i3)
                                      m = imin(m, C[i1][i3] + R[i&(~(1<<i1))][i3][i2]);
                              R[i][i1][i2] = m;
                              // fprintf(stderr, "i=%d i1=%d i2=%d m=%d\n", i,i1,i2,m);
                            }
            }

  m = 10000000;
  for(i1=0; i1<k; i1++)
      for(i2=0; i2<k; i2++)
          if(i1!=i2)
              m = imin(m, C2[i2][i1] + R[nn-1][i1][i2]);

  printf("Case #%d: %d\n", cnum, m+1);
}
