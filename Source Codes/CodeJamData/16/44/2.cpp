#define BUFSIZE 1000000
char buf[BUFSIZE];
int Tests, cnum;
// #define USEWIN
#define MANYTESTS 1
// #define LINEBYLINE

// Eryx's new template for I/O contests, May 3, 2015

#include <algorithm>
#include <string>
#include <stdio.h>
using namespace std;

#define LS <
#define Size(x) (int(x.size()))

// All macros with parameters "k,a,b" run the "k" variable in range [a,b)
#define FOR(k,a,b) for(__typeof(a) k=(a); k LS (b); ++k)

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

string getStr() {
#ifdef LINEBYLINE
  return getStr();
#else
  scanerr = scanf("%s", buf);
  return buf;
#endif
  }

#line 10 "work.cpp"

/// ----


//Eryx

// !FDI

string ability[30], tability[30];

bool workingw[30], workingm[30];

int N;

bool checkable(int left) {
  if(!left) return true;
  FOR(y,0,N) if(!workingw[y]) {
    int choices = 0;
    FOR(x,0,N) if(tability[y][x] == '1' && !workingm[x]) {
      // printf("Left %d, %d -> %d\n", left, y, x);
      workingw[y] = true;
      workingm[x] = true;
      bool b = checkable(left-1);
      workingw[y] = false;
      workingm[x] = false;
      if(!b) return false;
      choices++;
      }
    if(!choices) return false;
    }
  
  return true;
  }

int qwt[30], qmt[30];

int lowcost[1<<16][32][32];

void solveCase() {
  int res = 0;

  N = getNum();
  FOR(y,0,N) ability[y] = getStr();
  
  // proceed
  
  FOR(y,0,N) tability[y] = ability[y];

  bool deb = false; // (cnum == 8);
  if(deb) {
    FOR(y,0,N) printf("%s\n", ability[y].c_str()); printf("\n");
    }
  
  int mincost = 9999;

  int basecost = 0;
  
  int cones = 0;
  FOR(y,0,N) FOR(x,0,N) if(ability[y][x] == '1') cones++;
  
      FOR(y1,0,N) FOR(x1,0,N) FOR(y2,0,N) FOR(x2,0,N)
        if(ability[y1][x1] == '1' && ability[y1][x2] == '1' && 
           ability[y2][x1] == '1' && ability[y2][x2] == '0')
             ability[y2][x2] = '1', basecost++;

  int tid = 0;
  
  int asquares = 0;
  
  FOR(y,0,N) workingw[y] = workingm[y] = false;
  
  FOR(y,0,N) FOR(x,0,N) if(ability[y][x] == '1' && !workingw[y] && !workingm[x]) {
    int qw = 0, qm = 0;
    FOR(y1,0,N) if(ability[y1][x] == '1') workingw[y1] = true, qw++;
    FOR(x1,0,N) if(ability[y][x1] == '1') workingm[x1] = true, qm++;
    if(qw == qm) { asquares += qw*qm; continue; }
    qwt[tid] = qw, qmt[tid] = qm;
    tid++;
    }
  
  if(deb) { FOR(ti,0,tid) printf("%3d", qwt[ti]); printf("\n"); }
  if(deb) { FOR(ti,0,tid) printf("%3d", qmt[ti]); printf("\n"); }

  if(tid > 16) { printf("TID overflow\n"); exit(1); }
  
  int mleft = 0, wleft = 0;
  FOR(y,0,N) if(!workingw[y]) wleft++;
  FOR(x,0,N) if(!workingm[x]) mleft++;
  
  if(deb) printf("wleft=%d mleft=%d\n", wleft, mleft);
  
  FOR(y,0,wleft+1) FOR(x,0,mleft+1) lowcost[0][y][x] = max(x,y);
  
  FOR(t, 1, 1<<tid) {
    int subset = 0;
    for(int u=1; u < (1<<tid); u <<= 1) { /*printf("%d\n", u);*/ 
      if(u&t) subset = u; }
    
    FOR(y,0,wleft+1) FOR(x,0,mleft+1) lowcost[t][y][x] = 9999;
    
//  printf("t=%d subset=%d\n", t, subset);
    
    while(subset) {
      subset--; subset &= t;
      // subset == remaining guys      
      int allw = 0, allm = 0;
      FOR(ti,0,tid) if((t>>ti)&1) if(!((subset>>ti)&1)) {
        allw += qwt[ti];
        allm += qmt[ti];
        }
      int lcost = 0, cwt = 0, cmt = 0;
      if(allw >= allm) { lcost = allw*allw; cmt = allw-allm; }
      else { lcost = allm * allm; cwt=allm-allw; }
      
//    printf("allw=%d allm=%d lcost=%d cmt=%d cwt=%d\n", allw, allm, lcost, cmt, cwt);
//    printf("subset = %d\n", subset);

      FOR(y,cwt,wleft+1) FOR(x,cmt,mleft+1) {
        if(deb) printf("%d,%d: %d+%d\n", y,x, lcost, lowcost[subset][y-cwt][x-cmt]);
        lowcost[t][y][x] = min(lowcost[t][y][x], lcost + lowcost[subset][y-cwt][x-cmt]);
        }
      }
    }
  
  if(1) {
    int c = lowcost[(1<<tid)-1][wleft][mleft];
    int ccost = c + asquares - cones;
    if(deb) printf("c=%d cones=%d asq=%d ccost=%d\n", c, cones, asquares, ccost);
    if(ccost < mincost) mincost = ccost;
    }
    
  /* FOR(t, 0, (1<<(N*N))) { 
    FOR(y,0,N) FOR(x,0,N) tability[y][x] = ((t >> (x+y*N))&1) ? '1' : '0';
    if(checkable(N)) {
      int ccost = basecost;

      FOR(y,0,N) FOR(x,0,N)
        if(tability[y][x] == '1' && ability[y][x] == '0')
          ccost++;
        else if(tability[y][x] == '0' && ability[y][x] == '1')
          ccost += 500;

      // FOR(y,0,N) printf("%s\n", tability[y].c_str()); printf("\n => cost = %d\n", ccost);
      if(ccost < mincost) mincost = ccost;
      }
    } */
  
  printf("Case #%d: %d\n", cnum, mincost);
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
