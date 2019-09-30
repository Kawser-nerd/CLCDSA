#define BUFSIZE 1000000
char buf[BUFSIZE];
int Tests, cnum;
// #define USEWIN
#define MANYTESTS 1
// #define LINEBYLINE

// Eryx's new template for I/O contests, May 3, 2015

#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef long double ld;

#define LS <
#define Size(x) (int(x.size()))

// All macros with parameters "k,a,b" run the "k" variable in range [a,b)
#define FOR(k,a,b) for(__typeof(a) k=(a); k LS (b); ++k)

// Bit Count
int bitc(ll r) {return r == 0 ? 0 : (bitc(r>>1) + (r&1));}

string getLine() {
  string s;
  while(!feof(stdin)) {
    char c = fgetc(stdin);
    if(c == 13) continue;
    if(c == 10) return s;
    s += c;
    }
  return s;
  }

int scanerr;

int getNum() {
#ifdef LINEBYLINE
  string s = getLine();
  return atoi(s.c_str());
#else
  int i;
  scanerr = scanf("%d", &i);
  return i;
#endif
  }

double getDouble() {
#ifdef LINEBYLINE
  string s = getLine();
  return atof(s.c_str());
#else
  double v;
  scanerr = scanf("%s", buf);
  return atof(buf);
#endif
  }

#line 10 "work.cpp"

/// ----


//Eryx

// !FDI

int N;
ld p[300];
bool chosen[300];

ld calcdraw() {
  ld rchance[300];
  FOR(u,0,10) rchance[u] = 0;
  rchance[0] = 1;
  int nbits = 0;
  FOR(z,0,N) if(chosen[z]) {
    nbits++;
    for(int u=9; u>=1; u--)
      rchance[u] = rchance[u-1] * p[z] + rchance[u] * (1-p[z]);
    rchance[0] *= (1-p[z]);
    }

  return rchance[nbits/2];
  }

void check() {
  FOR(a,0,11) FOR(b,a+1,11) FOR(c,b+1,11) FOR(d,c+1,11) FOR(e,d+1,11) FOR(f,e+1,11) {
    p[0] = a/10.0;
    p[1] = b/10.0;
    p[2] = c/10.0;
    p[3] = d/10.0;
    p[4] = e/10.0;
    p[5] = f/10.0;

    ld best = -1;
    int wbest = -1;
    
    FOR(t,0,64) {
      if(bitc(t) != 4) continue;
      FOR(s,0,6) chosen[s] = (t>>s) & 1;
      ld res = calcdraw();
      if(res > best) best = res, wbest = t;
      }
    
    FOR(s,0,6) printf("%d", (wbest>>s) & 1);
    if(wbest == 2+8+16+32) {
      printf(" %Lf\n", best);
      
      printf("%d %d %d %d %d %d\n", a,b,c,d,e,f);
      
      FOR(k,0,6) printf("%.2Lf ", p[k]); printf("\n");

      FOR(t,0,64) {
        if(bitc(t) != 4) continue;
        FOR(s,0,6) chosen[s] = (t>>s) & 1;
        ld res = calcdraw();
        FOR(s,0,6) printf("%d", chosen[s]);
        printf(" -> %Lf\n", res);
        }
      exit(1);
      }
    printf("\n"); 
    }
  exit(0);
  }

void solveCase() {
  
  ld best = -1;

  N = getNum();
  int K = getNum();
  FOR(n,0,N) p[n] = getDouble();
  
  sort(p, p+N);
  FOR(c, 0, K+1) {
    FOR(n,0,N) chosen[n] = ((n<c) || (n>=c+N-K)) ? 1 : 0;
    // FOR(n,0,N) printf("%d", chosen[n]); printf("\n");
    double res = calcdraw();
    // printf("c=%d res=%lf\n", c, res);
    if(res > best) best = res;
    }
  
  printf("Case #%d: %.12Lf\n", cnum, best);

/*  
  ld best2 = -1;
  int wbest = 0;
  FOR(c, 0, (1<<N)) if(bitc(c) == K) {
    FOR(n,0,N) chosen[n] = (c>>n) & 1;
    double res = calcdraw();
    if(res > best2) best2 = res, wbest = c;
    }
  
  if(fabs(best - best2) > 1e-9) {
    FOR(t, 0, N) printf("%d", (wbest>>t) & 1); printf(" ");
    printf("Case #%d: %.12Lf %.12Lf\n", cnum, best, best2);
    } */
  }

int main() {

  // check();

  if(!MANYTESTS) Tests = 1;
  else Tests = getNum();
  
  for(cnum=1; cnum<=Tests; cnum++)
    solveCase();
    
  // finish
  return 0;
  }

// This solution includes hidden routines to solve test cases in separate
// processes in order to make it faster. I will update them to run on a
// cluster if I get one ;)
