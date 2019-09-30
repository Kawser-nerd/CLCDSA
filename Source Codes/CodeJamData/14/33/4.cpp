#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
//#include <iostream>
#include <set>
//#include <map>
//#include <sstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<string> vs;

int err;

#define LS <
#define Size(x) (int(x.size()))
#define LET(k,val) typeof(val) k = (val)
#define CLC(act,val) (*({act; static typeof(val) CLCR; CLCR = (val); &CLCR;}))

#define FOR(k,a,b) for(typeof(a) k=(a); k LS (b); ++k)
#define FORREV(k,a,b) for(typeof(b) k=(b); (a) <= (--k);)

#define FIRST(k,a,b,cond) CLC(LET(k, a); for(; k LS (b); ++k) if(cond) break, k)
#define LAST(k,a,b,cond) CLC(LET(k, b); while((a) <= (--k)) if(cond) break, k)
#define EXISTS(k,a,b,cond) (FIRST(k,a,b,cond) LS (b))
#define FORALL(k,a,b,cond) (!EXISTS(k,a,b,!(cond)))
#define FOLD0(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(; k LS (b); ++k) {act;}, R##k)
#define SUMTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k += (x))
#define SUM(k,a,b,x) SUMTO(k,a,b,(typeof(x)) (0), x)
#define PRODTO(k,a,b,init,x) FOLD0(k,a,b,init,R##k *= (x))
#define PROD(k,a,b,x) PRODTO(k,a,b,(typeof(x)) (1), x)
#define MAXTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k >?= (x))
#define MINTO(k,a,b,init,x)  FOLD0(k,a,b,init,R##k <?= (x))
#define QXOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (0), R##k ^= x)
#define QAND(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k &= x)
#define QOR(k,a,b,x) FOLD0(k,a,b,(typeof(x)) (-1), R##k |= x)
#define FOLD1(k,a,b,init,act) CLC(LET(k, a); LET(R##k, init); for(++k; k LS (b); ++k) act, R##k)
#define MAX(k,a,b,x) FOLD1(k,a,b,x, R##k >?= (x))
#define MIN(k,a,b,x) FOLD1(k,a,b,x, R##k <?= (x))
#define FIRSTMIN(k,a,b,x) (MIN(k,a,b,make_pair(x,k)).second)

int bitc(ll r) {return r == 0 ? 0 : (bitc(r>>1) + (r&1));}
ll gcd(ll x, ll y) {return x ? gcd(y%x,x) : y;}

// template<class T> T& operator >?= (T& x, T y) {if(y>x) x=y; return x;}
// template<class T> T& operator <?= (T& x, T y) {if(y<x) x=y; return x;}
// template<class T> T operator >? (T x, T y) {return x>y?x:y;}
// template<class T> T operator <? (T x, T y) {return x<y?x:y;}

#define Pa(xy) ((xy).first)
#define Ir(xy) ((xy).second)

string cts(char c) {string s=""; s+=c; return s;}

/// ----

#define BUFSIZE 1000000
char buf[BUFSIZE];

#ifdef DEBUG
#define DEB(x) x
#else
#define DEB(x)
#endif

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

int getNum() {
  string s = getLine();
  return atoi(s.c_str());
  }

vi parsevi(string s) {
  s = s + " ";
  int q = 0;
  bool minus = false;
  vi res;
  FOR(l,0, Size(s)) {
    if(s[l] == ' ') { res.push_back(minus?-q:q); q = 0; minus = false;}
    else if(s[l] == '-') { minus = true; }
    else { q = q * 10 + s[l] - '0'; }
    }
  return res;
  }

int Tests, cnum;

//Eryx

// !FDI

int N, M, K;

bool enc[100][100];

bool vis[100][100];

void dfs(int n, int m) {
  if(n<0||m<0||n>=N||m>=M) return;
  if(enc[n][m]) return;
  if(vis[n][m]) return;
  vis[n][m] = true;
  dfs(n-1,m);
  dfs(n+1,m);
  dfs(n,m-1);
  dfs(n,m+1);
  }

int shape[1200][1200], qsh;

int bestenc[8000][1024];

int tri[1200];

void prepare() {
  FOR(n,0,1200) tri[n] = n*(n+1)/2;  
  FOR(n,0,1200) FOR(m,0,1200) shape[n][m] = 0; qsh = 1;
  FOR(n,1,1001) FOR(m,1,1001) if(n*m <= 1000 && n<=m) {
    shape[n][m] = shape[m][n] = qsh++;
    }
  // printf("qsh = %d\n", qsh);

  FOR(sh,0,8000) FOR(z,0,1024) bestenc[sh][z] = 999999;

  FOR(x, 1, 1001) FOR(y, 1, 1001) if(shape[x][y]) {
    if(y <= 2 || x <= 2) FOR(z,0,x*y+1) bestenc[shape[y][x]][z] = z;
    }

  FOR(x, 1, 1001) FOR(y, 1,x+1) if(shape[x+2][y+2]) {
    int rec = (x+2) * (y+2);
    int sh = shape[x+2][y+2];
    for(int a=0; a <= y && a <= x; a++) 
    for(int b=0; a+b <= y+2 && b <= x; b++)
    for(int c=0; c <= y && a+c <= x+2; c++)
    for(int d=0; c+d <= y+2 && b+d <= x+2; d++) {
      int area = (rec - tri[a] - tri[b] - tri[c] - tri[d]);
      int enc = 2*x + 2*y + 4 - a - b - c - d;
      bestenc[sh][area] = min(bestenc[sh][area], enc);
      }
    FORREV(z,0,1023) bestenc[sh][z] = min(bestenc[sh][z], bestenc[sh][z+1]);
    int sh1 = shape[x+1][y+2];
    int sh2 = shape[x+2][y+1];
    FORREV(z,0,1023) bestenc[sh][z] = min(bestenc[sh][z], bestenc[sh1][z]);
    FORREV(z,0,1023) bestenc[sh][z] = min(bestenc[sh][z], bestenc[sh2][z]);
    }
  }

void solveCase() {
  err = scanf("%d%d%d", &N, &M, &K);
  
  int tab = bestenc[shape[N][M]][K];
  printf("Case #%d: %d\n", cnum, tab);
  
  /*
  
  int P = N*M;
  int bestile = P;
  for(int k = 0; k < (1<<P); k++) {
    int z = k;
    int ile = 0;
    int area = 0;
    FOR(n,0,N) FOR(m,0,M) { vis[n][m] = false; enc[n][m] = (z&1); if(z&1) ile++; z >>= 1; }
    FOR(n,0,N) FOR(m,0,M)
      if(n==0 || m==0 || n==N-1 || m==M-1) dfs(n, m);
    FOR(n,0,N) FOR(m,0,M) if(!vis[n][m]) area++;
    if(area >= K && ile < bestile)
      bestile = ile;
    
    if(0) if(ile == bestile) {
      FOR(n,0,N) {
        FOR(m,0,M) {
          if(enc[n][m]) printf("["); else printf(" ");
          if(vis[n][m]) printf("x"); else printf(" ");
          if(enc[n][m]) printf("]"); else printf(" ");
          }
        printf("\n");
        }
      printf("\n");
      }
    }
  
  int tab = bestenc[shape[N][M]][K];
  if(bestile != tab) printf("Case #%d: %d vs %d\n", cnum, bestile, tab); */
  }

int main() {

  prepare();

  if(0)
    Tests = 1;
  else if(1)
    err = scanf("%d", &Tests);
  else {
    string Nstr = getLine();
    Tests = atoi(Nstr.c_str());
    }
  
  for(cnum=1; cnum<=Tests; cnum++)
    solveCase();
    
  // finish
  return 0;
  }

// This solution includes hidden routines to solve test cases in separate
// processes in order to make it faster. I will update them to run on a
// cluster if I get one ;)
