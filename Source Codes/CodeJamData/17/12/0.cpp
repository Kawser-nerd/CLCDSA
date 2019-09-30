#define BUFSIZE 1000000
char buf[BUFSIZE];
int Tests, cnum;
// #define USEWIN
#define MANYTESTS 1
// #define LINEBYLINE

// Eryx's new template for I/O contests, May 3, 2015

#include <algorithm>
#include <stdio.h>
using namespace std;

typedef long long ll;

#define LS <
#define Size(x) (int(x.size()))

// All macros with parameters "k,a,b" run the "k" variable in range [a,b)
#define FOR(k,a,b) for(__typeof(a) k=(a); k LS (b); ++k)

string getLine() {
  string s;
  while(!feof(stdin)) {
    char c = fgetc(stdin);
    if(c <= 0) continue;
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

#line 10 "work.cpp"

/// ----


//Eryx

// !FDI

ll rec[64];
ll wei[64][64];

int pos[64];

void solveCase() {
  int res = 0;

  int N = getNum();
  int P = getNum();
  
  FOR(n,0,N) rec[n] = getNum();
  
  FOR(n,0,N) FOR(p,0,P) wei[n][p] = getNum();
  FOR(n,0,N) sort(wei[n], wei[n]+P);
  
  FOR(n,0,N) pos[n] = 0;
  int mul = 1;
  
  while(true) {
    bool ok = true;
    FOR(n,0,N) {
      again:
      if(pos[n] >= P) goto finish;
      if(wei[n][pos[n]] * 100 < 90 * mul * rec[n]) { /*printf("pos %d=%d\n", n, pos[n]);*/ ok = false; pos[n]++; goto again; }
      while(wei[n][pos[n]] * 100 > 110 * mul * rec[n]) { /*printf("mul=%d\n", mul);*/ ok = false; mul++; }
      }
    if(ok) {
      res++;
      FOR(n,0,N) pos[n]++;
      }
    }
  
  finish:
  printf("Case #%d: %d\n", cnum, res);
  }

#define P 1000000007

int main() {

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
