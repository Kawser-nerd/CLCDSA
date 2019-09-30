#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
//#include <iostream>
#include <set>
#include <map>
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

#define P 1000000007

ll podz[5000][100];

ll N;
int B;

void prepareP() {
  FOR(a,0,5000) FOR(b,0,100) podz[a][b] = 0;
  podz[0][0] = 1;
  FOR(ns, 1, B) for(int b=98; b>=0; b--) FOR(a,0,5000-ns) {
    podz[a+ns][b+1] += podz[a][b];
    podz[a+ns][b+1] %= P;
    }
  }

ll dolne[100][100];

void prepareD() {
  FOR(k,0,100) {
    dolne[k][0] = 1;
    FOR(t,0,100) {
      dolne[k][t+1] = (dolne[k][t] * (k-t)) % P;
      }
    }
  }

map<pair<ll, ll>, ll> memo;

ll go(ll sum, ll skl) {
  if(sum == 0) return skl == 0 ? 1 : 0;
  // printf("go [%d,%d]\n", sum, skl);
  if(memo.count(make_pair(sum,skl)))
    return memo[make_pair(sum,skl)];
  ll res = 0;

  FOR(ost,0,5000) if(ost <= sum) if((sum-ost) % B == 0) if(podz[ost][skl]) 
  FOR(nskl, 0, skl+1)  {
    res += (podz[ost][skl] * ((go((sum-ost)/B, nskl) * dolne[skl][nskl]) % P)) % P;

    if(0) fprintf(stderr, "A [%d -> %d.%d x %d %d %d@%d]\n", int(sum), int((sum-ost)/B), int(ost), 
      int(podz[ost][skl]),
      int(go((sum-ost)/B, nskl)), 
      int(dolne[skl][nskl]),
      int(nskl));
    res %= P;
    }

  // with a zero
  FOR(ost,0,5000) if(ost <= sum) if((sum-ost) % B == 0) if(podz[ost][skl-1]) 
  FOR(nskl, 1, skl+1) {
    res += (podz[ost][skl-1] * ((go((sum-ost)/B, nskl) * ((nskl * dolne[skl-1][nskl-1]) % P)) % P)) % P;

    if(0) fprintf(stderr, "B [%d -> %d.%d x %d %d %d@%d]\n", int(sum), int((sum-ost)/B), int(ost), 
      int(podz[ost][skl-1]),
      int(go((sum-ost)/B, nskl)), 
      int(dolne[skl][nskl]),
      int(nskl));
    res %= P;
    }

  if(0) fprintf(stderr, "[sum=%d skl=%d res=%d]\n", int(sum), int(skl), int(res));
  return memo[make_pair(sum,skl)] = res;
  }

void solveCase() {
 
  memo.clear();
  err = scanf("%lld%d", &N, &B);
  
  // process
  
  prepareP();
  
  ll res = 0;
  FOR(skl,0,B+1) {
    res += go(N, skl);
    res %= P;
    }
  
  printf("Case #%d: %d\n", cnum, int(res));
  fflush(stdout);
  }

int main() {

  prepareD();

  if(0)
    Tests = 1;
  else if(0)
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
