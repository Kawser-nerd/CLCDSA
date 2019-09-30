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

bool isprime[2000000];

int pw10[7] = {1, 10, 100, 1000, 10000, 100000, 1000000};

void genPrimes() {
  FOR(u,0,2000000) isprime[u] = true;
  isprime[0] = false;
  isprime[1] = false;
  FOR(u,2,2000000) if(isprime[u])
    for(int v=u+u; v<2000000; v+=u) isprime[v] = false;
  }

ll P, A, B;

ll fastpow(ll a, int d) {
  ll res = 1;
  while(d) {
    if(d&1) res = (res*a) % P;
    a = (a*a) % P; d /= 2;
    }
  return res;
  }

void solveCase() {
  int res = 0;

  int D, K;
  
  err = scanf("%d%d", &D, &K);
  
  int seq[20];
  
  FOR(u,0,K) err = scanf("%d", &seq[u]);
  
  int opts = 0;
  int next = -1;
  
  if(K > 199999) {
    FOR(p,seq[0]+1,pw10[D]) if(isprime[p])
    FOR(A,0,p) {

      ll nval; P=p;
      
      ll B = seq[1] - seq[0] * A;
      
      B %= P; if(B<0) B += P;
      
      FOR(q,0,K-1) if(seq[q+1] != (seq[q] * A + B) % P) goto nextx;
      
      nval = (seq[K-1] * A + B) % P;
      
      if(cnum == 2) printf("P=%d A=%d B=%d -> %d\n", int(P), int(A), int(B), int(nval));

      if(opts == 0) opts = 1, next = nval;
      else if(opts == 1 && next == nval) ;
      else opts = 2;
      
      nextx: ;
      }
    }
  
  else if(K == 1) {
    fprintf(stderr, "D=%d V=%d\n", D, seq[0]);
    opts = 10;
    }
  else if(seq[K-1] == seq[K-2]) {
    opts = 1; next = seq[K-1];
    }
  else if(K == 2) {
    fprintf(stderr,"#%d %d,%d,%d,%d\n", cnum, D,K, seq[0], seq[1]);
    opts = 10;
    }
  else {
    FOR(p,seq[0]+1,pw10[D]) if(isprime[p]) {
      P = p;
      ll val = seq[0] - seq[1];
      val = fastpow(val, P-2);
      val *= seq[1] - seq[2]; val %= P;
      A = val;
      B = seq[1] - A * seq[0]; B %= P;
      
      if(A<0) A += P;
      if(B<0) B += P;
      
      // if(cnum == 4) printf("P=%d A=%d B=%d 60 -> %d\n", int(P), int(A), int(B), int((60*A) % P));
      
      ll nval;
      
      FOR(q,0,K-1) if(seq[q+1] != (seq[q] * A + B) % P) goto nextp;
      
      nval = (seq[K-1] * A + B) % P;
      
      if(nval < 0) { nval += P; nval %= P; }
      
      // if(cnum == 4) printf("[%d]\n", int(nval));
      
      if(opts == 0) opts = 1, next = nval;
      else if(opts == 1 && next == nval) ;
      else opts = 2;
      
      nextp: ;
      }
    
    }
  
  if(opts != 1)
    printf("Case #%d: I don't know.\n", cnum);
  else
    printf("Case #%d: %d\n", cnum, next);
  // if(cnum == 4) exit(1);
  fflush(stdout);
  }

int main() {

  genPrimes();

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
