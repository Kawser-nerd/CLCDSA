#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
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

template<class T> T& operator >?= (T& x, T y) {if(y>x) x=y; return x;}
template<class T> T& operator <?= (T& x, T y) {if(y<x) x=y; return x;}
template<class T> T operator >? (T x, T y) {return x>y?x:y;}
template<class T> T operator <? (T x, T y) {return x<y?x:y;}

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

int NS[32][32], WE[32][32], MO[32][32], TI[32][32];
int N, M;

int timego[64][64];

#define INF 2000000000

void solveCase(int cnum) {
  int res = 0;
  
  scanf("%d%d", &N, &M);
  
  FOR(n,0,N) FOR(m,0,M) scanf("%d%d%d",
    &NS[n][m], &WE[n][m], &TI[n][m]
    );
  
  FOR(n,0,N) FOR(m,0,M) {
    MO[n][m] = NS[n][m] + WE[n][m];
    TI[n][m] %= MO[n][m];
    TI[n][m] -= MO[n][m];
    }
  
  FOR(n,0,64) FOR(m,0,64) timego[n][m] = INF;
  
  timego[2*N-1][0] = 0;
  
  int curtime = -1;
  
  while(true) {
  
    int nexttime = INF;
    
    FOR(n,0,64) FOR(m,0,64)
      if(timego[n][m] > curtime && timego[n][m] < nexttime)
        nexttime = timego[n][m];

    curtime = nexttime;
    
    if(curtime == INF) break;
    
    FOR(n,0,64) FOR(m,0,64) if(timego[n][m] == curtime) {
      
      if(n&1) {if(n < 2*N-1)
        timego[n+1][m] <?= timego[n][m] + 2;}
      else {if(n)
        timego[n-1][m] <?= timego[n][m] + 2;}
      if(m&1) {if(m < 2*M-1)
        timego[n][m+1] <?= timego[n][m] + 2;}
      else {if(m)
        timego[n][m-1] <?= timego[n][m] + 2;}
      
      int rn = n/2, rm = m/2;
      
      // T >= curtime
      // (T-TI) / (NS+WE) < NS
      
      int modval = (curtime-TI[rn][rm]) % MO[rn][rm];
      
      if(modval < NS[rn][rm]) {
        timego[n^1][m] <?= timego[n][m] + 1;
        timego[n][m^1] <?= timego[n][m] + NS[rn][rm]-modval + 1;
        }
      else {
        timego[n][m^1] <?= timego[n][m] + 1;
        timego[n^1][m] <?= timego[n][m] + MO[rn][rm]-modval + 1;
        }
      }
    }
  
  printf("Case #%d: %d\n", cnum+1, timego[0][2*M-1]);
  }

int main() {
  int N;
  string Nstr = getLine();
  N = atoi(Nstr.c_str());
  FOR(cnum,0,N) 
    solveCase(cnum);
  return 0;
  }
