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


static inline int cross(double x1, double x2)
{
  if(x2>x1)
      return x1<floor(x2) && ceil(x1)<x2;
  else
      return x1>ceil(x2) && floor(x1)>x2;
}


static inline int btw(double x1, double x2)
{
  if(x2>x1)
      return (int) floor(x1+1.0);
  else
      return (int) ceil(x1-1.0);
}


int gcd(int a, int b)
{
  if(a<0) a = -a;
  if(b<0) b = -b;
  if(a<b)
    {
      int t = a;
      a = b;
      b = t;
    }
  while(b>0)
    {
      int bb = a%b;
      a = b;
      b = bb;
    }
  return a;
}


void do_one_case(int cnum)
{
  int i, j, ii, jj;
  int r0, c0, x0, y0;
  char corn[64][64], horz[64][64], vert[64][64];
  char hom[32][32];
  char homx[32][32];
  char buf[100];
  int H, W, D;


  fgets(buf, 100, stdin);
  assert(3==sscanf(buf,"%d %d %d\n", &H, &W, &D));
  assert(H>=3 && H<=30);
  assert(W>=3 && W<=30);
  assert(D<=50);

  r0 = c0 = -99;
  for(i=0; i<H; i++)
    {
      fgets(buf, 100, stdin);
      assert(strlen(buf)==W+1);
      assert(buf[W] == '\n');
      buf[W] = '\0';
      strcpy(hom[i], buf);
      strcpy(homx[i], buf);
      for(j=0; j<W; j++)
        {
          if(buf[j]=='#')
              ;
          else if(buf[j]=='.')
              assert(i>0 && i<H-1 && j>0 && j<W-1);
          else if(buf[j]=='X')
            {
              assert(i>0 && i<H-1 && j>0 && j<W-1);
              assert(r0<0 && c0<0);
              r0 = i;
              c0 = j;
            }
          else
              assert(0);
        }
    }
  assert(r0>0 && c0>0);
  homx[r0][c0] = '.';

  for(i=0; i<2*W-3; i++)
      for(j=0; j<2*H-3; j++)
          horz[i][j] = vert[i][j] = corn[i][j] = '~';
    

  for(i=0; i<H-1; i++)
      for(j=1; j<W-1; j++)
        {
          char c;
          if(hom[i][j]=='#' || hom[i+1][j]=='#')
              c = '-';
          else
              c = '.';
          horz[2*j-2][2*(H-i)-4] = c;
          horz[2*j-1][2*(H-i)-4] = c;
        }
    for(i=0; i<2*W-4; i++)
        for(j=1; j<2*H-4; j+=2)
           horz[i][j] = '.'; 

    for(i=1; i<H-1; i++)
        for(j=0; j<W-1; j++)
          {
            char c;
            if(hom[i][j]=='#' || hom[i][j+1]=='#')
                c = '|';
            else
                c = '.';
            vert[2*j][2*(H-i)-4] = c;
            vert[2*j][2*(H-i)-3] = c;
          }
    for(i=1; i<2*W-4; i+=2)
        for(j=0; j<2*H-4; j++)
            vert[i][j] = '.';

    for(i=0; i<H-1; i++)
        for(j=0; j<W-1; j++)
          {
            int foo = 0;
            char c;

            if(homx[i][j]=='#') foo+=1000;
            if(homx[i][j+1]=='#') foo+=100;
            if(homx[i+1][j]=='#') foo+=10;
            if(homx[i+1][j+1]=='#') foo+=1;

            switch(foo)
              {
                case 0:
                    c = '.';
                    break;
                case 1000:
                    c = '1';
                    break;
                case 100:
                    c = '2';
                    break;
                case 10:
                    c = '3';
                    break;
                case 1:
                    c = '4';
                    break;
                case 1100:
                case 11:
                    c = '-';
                    break;
                case 1010:
                case 101:
                    c = '|';
                    break;
                case 1001:
                    c = '\\';
                    break;
                case 110:
                    c = '/';
                    break;
                case 1110:
                case 1101:
                case 1011:
                case 111:
                    c = 'L';
                    break;
                case 1111:
                    c = '#';
                    break;
                default:
                    assert(foo==-9999);
              }
            corn[2*j][2*(H-i)-4] = c;
          }
    for(i=0; i<H-1; i++)
        for(j=1; j<W-1; j++)
          {
            char c;
            int foo = 0;

            if(homx[i][j]=='#') foo += 10;
            if(homx[i+1][j]=='#') foo += 1;
            switch(foo)
              {
                case 0:
                    c = '.';
                    break;
                case 10:
                case 1:
                    c = '-';
                    break;
                case 11:
                    c = '#';
                    break;
                default:
                    assert(foo==-9999);
              }
            corn[2*j-1][2*(H-i)-4] = c;
          }
    for(i=1; i<H-1; i++)
        for(j=0; j<W-1; j++)
          {
            char c;
            int foo = 0;

            if(homx[i][j]=='#') foo += 10;
            if(homx[i][j+1]=='#') foo += 1;
            switch(foo)
              {
                case 0:
                    c = '.';
                    break;
                case 10:
                case 1:
                    c = '|';
                    break;
                case 11:
                    c = '#';
                    break;
                default:
                    assert(foo==-9999);
              }
            corn[2*j][2*(H-i)-3] = c;
          }
    for(i=1; i<H-1; i++)
        for(j=1; j<W-1; j++)
          {
            char c;
            switch(hom[i][j])
              {
                case '.':
                    c = '.';
                    break;
                case '#':
                    c = '#';
                    break;
                case 'X':
                    c = '*';
                    break;
                default:
                    assert(c=='?' && c=='@');
                break;
              }
            corn[2*j-1][2*(H-i)-3] = c;
          }

    x0 = 2*c0 - 1;
    y0 = 2*(H-r0) - 3;
    assert(corn[x0][y0] == '*');
    D *= 2;

    if(0)
      {
        for(i=2*H-4; i>=0; i--)
          {
            for(j=0; j<2*H-3; j++)
                fprintf(stderr, "%c", horz[j][i]);
            fprintf(stderr, "\n");
          }
        fprintf(stderr, "\n");
        for(i=2*H-4; i>=0; i--)
          {
            for(j=0; j<2*H-3; j++)
                fprintf(stderr, "%c", vert[j][i]);
            fprintf(stderr, "\n");
          }
        fprintf(stderr, "\n");
        for(i=2*H-4; i>=0; i--)
          {
            for(j=0; j<2*H-3; j++)
                fprintf(stderr, "%c", corn[j][i]);
            fprintf(stderr, "\n");
          }
        fprintf(stderr, "\n");
      }

    char aflg[128][128];
    memset(aflg, 0, sizeof(aflg));
    
    for(i=0; i<=D; i+=2)
        for(j=0; j<=D; j+=2)
          {
            if(i==0 && j==0)
                continue;
            if(i*i + j*j > D*D)
                continue;
            int k = gcd(i,j);
            aflg[i/k][j/k] = 1;
          }

    int N = 0;

    for(i=0; i<=D; i++)
        for(j=0; j<=D; j++)
          {
            if(!aflg[i][j])
                continue;
            for(ii=-i; ii<=i; ii+=imax(2*i,1))
              {
                for(jj=-j; jj<=j; jj+=imax(2*j,1))
                  {
                    int div = imax(i,j);
                    double dx = ii/(div+0.0);
                    double dy = jj/(div+0.0);
                    double x = x0;
                    double y = y0;
                    double dd = 1.001*D/hypot(dx,dy);
                    double d = 0;
                    double x2, y2, s, f, x3, y3;
                    int ix, iy;

                    while(d<dd)
                      {
                        x2 = x + dx;
                        y2 = y + dy;
                        s = 1.0;
                        if(cross(x,x2))
                          {
                            f = (btw(x,x2)-x) / (x2-x);
                            assert(f<=1.0);
                            x2 = f*x2 + (1-f)*x;
                            y2 = f*y2 + (1-f)*y;
                            s *= f;
                          }
                        if(cross(y,y2))
                          {
                            f = (btw(y,y2)-y) / (y2-y);
                            assert(f<=1.0);
                            x2 = f*x2 + (1-f)*x;
                            y2 = f*y2 + (1-f)*y;
                            s *= f;
                          }

                        d += s;
                        if(d>dd)
                            break;
                        x3 = floor(x2 + 1e-7);
                        y3 = floor(y2 + 1e-7);
                        if(fabs(x2-x3) < 1e-8) x2 = x3;
                        if(fabs(y2-y3) < 1e-8) y2 = y3;
                        x = x2;
                        y = y2;
                        ix = floor(x);
                        iy = floor(y);

                        if(x==ix && y==iy)
                          {
                            char c = corn[ix][iy];
                            if(c=='|')
                                dx = -dx;
                            else if(c=='-')
                                dy = -dy;
                            else if(c=='*')
                              {
                                if(d*d*(dx*dx+dy*dy) < D*D*(1 + 1e-8))
                                    N += 1;
                                goto nextangle;
                              }
                            else if(c=='L')
                              {
                                if(4*d*d*(dx*dx+dy*dy) < D*D*(1 + 1e-8))
                                    N += 1;
                                goto nextangle;
                              }
                            else if(c=='1' && dx<=0 && dy>=0)
                                goto nextangle;
                            else if(c=='2' && dx>=0 && dy>=0)
                                goto nextangle;
                            else if(c=='3' && dx<=0 && dy<=0)
                                goto nextangle;
                            else if(c=='4' && dx>=0 && dy<=0)
                                goto nextangle;
                            else
                              {
                                assert(c != '#');
                              }
                          }
                        else if(x==ix)
                          {
                            char c = vert[ix][iy];
                            if(c=='|')
                                dx = -dx;
                          }
                        else if(y==iy)
                          {
                            char c = horz[ix][iy];
                            if(c=='-')
                                dy = -dy;
                          }
                      }
    nextangle:
                    H += 0;
                  }
              }
          }

    printf("Case #%d: %d\n", cnum, N);
    //print "Case #%d: %d" % (cnum, N)
}
