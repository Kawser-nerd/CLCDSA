#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

//#include <iostream>
//#include <set>
//#include <map>
//#include <sstream>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<string> vs;

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

#define Pa(xy) ((xy).first)
#define Ir(xy) ((xy).second)

string cts(char c) {string s=""; s+=c; return s;}

int cnum, Tests, err;

//Eryx
// (th

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

int X, Y;

char mapp[64][64];

bool isok[64][64], isat[64][64], bfall[64][64];

void dfs(int x, int y) {
  //printf("[%d %d] %c\n", x,y, mapp[y][x]);
  if(mapp[y][x] == '#') return;
  if(isok[y][x]) return;
  isok[y][x] = true;
  dfs(x-1, y);
  dfs(x+1, y);
  dfs(x, y-1);
  }

void solve(int dx, int dy, int di) {
  FOR(y,0,Y) FOR(x,0,X) isok[y][x] = false;
  dfs(dx, dy);
  int cnt = 0;
  FOR(y,0,Y) FOR(x,0,X) if(isok[y][x]) cnt++;
  FOR(y,0,Y) FOR(x,0,X) isat[y][x] = isok[y][x];
  //printf("cnt = %d\n", cnt);
  
  int stepid = 0;
  
  FOR(y,0,Y) FOR(x,0,X) 
    bfall[y][x] = (isok[y][x] && !isok[y+1][x] && mapp[y+1][x] != '#');
  
  bool goleft = true;
  
  FOR(s,0,64*128) { fag:
    if(di==399) {
      FOR(y,0,Y) {
        FOR(x,0,X) printf("%c",
          isat[y][x] ? '*' : isok[y][x] ? '_' : mapp[y][x] == '#' ? '#' : '.');
        printf("\n");
        }
      printf("\n");
      }
    bool fallagain = true;
    while(fallagain) {
      bool cfal = true;
      FOR(y,0,Y) FOR(x,0,X) if(isat[y][x] && bfall[y][x]) cfal = false;
      if(!cfal) break;
      fallagain = false;
      FORREV(y,0,Y) FOR(x,0,X) if(isok[y][x] && isat[y-1][x])
        isat[y][x] = true, isat[y-1][x] = false, fallagain = true;
      }
    if(goleft) {
      goleft = false;
      FOR(y,0,Y) FOR(x,0,X) if(isok[y][x] && isat[y][x+1])
        isat[y][x] = true, isat[y][x+1] = false, goleft = true;
      }
    else {
      goleft = true;
      FOR(y,0,Y) FORREV(x,0,X) if(isok[y][x] && isat[y][x-1])
        isat[y][x] = true, isat[y][x-1] = false, goleft = false;
      }
    }
  
  int allat = 0;
  FOR(y,0,Y) FOR(x,0,X) if(isat[y][x]) allat++;
  
  printf("%d: %d %s\n", di, cnt, allat == 1 ? "Lucky" : "Unlucky");
  }

void solveCase() {
  int res = 0;
  // proceed
  
  err=scanf("%d%d", &Y, &X);
  FOR(y,0,Y) err=scanf("%s", mapp[y]);
  
  printf("Case #%d:\n", cnum+1);
  FOR(c,0,10) FOR(y,0,Y) FOR(x,0,X) if(mapp[y][x] == '0'+c) solve(x, y, c);
  }

int main() {
  if(0) Tests = 1;
  else if(0) {
    string Nstr = getLine();
    Tests = atoi(Nstr.c_str());
    }
  else {
    err = scanf("%d", &Tests);
    }

  for(cnum=0; cnum<Tests; cnum++)
    solveCase();
    
  // finish
  return 0;
  }

// I also have a preprocessor which turns this solution into one that
// runs test cases in separate processes in order to make it faster
