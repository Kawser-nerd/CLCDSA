#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <queue>
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

  ll L;
  int N;

int B[200];

ll INF;

ll score[100000], from[100000];

ll sofar = 0;

int maxqueue = 0;

void solveCase() {
  INF = 1000000000;
  INF *= INF;
  INF *= 2;
  
  int res = 0;

  
  err = scanf("%lld%d", &L, &N);
  
  FOR(n,0,N) err = scanf("%d", &B[n]);
  
  // proceed

  sort(B, B+N);
  
  int Max = B[N-1];
  
  priority_queue<ll> q;
  
  FOR(a,0,Max) score[a] = INF;
  score[0] = 0;
  
  q.push(0);
  
  ll sol = INF;
  
  if(0) {
    FOR(tim,0,Max) FOR(pos,0,Max) FOR(bs,0,N-1) {
      int nat = (pos + B[bs]) % Max;
      ll nval = score[pos];
      if(nat > pos) nval++;
      if(score[nat] > nval) score[nat] = nval, from[nat] = pos;
      }
  
    // if(cnum==1) FOR(u,0,100) printf("%d: %d [%d]\n", u, int(from[u]), int(score[u]));
    
    if(score[L % Max] != INF)
      sol = score[L % Max] + (L / Max);
    }
  
  int cqueue = 0;
  
  if(1) while(!q.empty()) {
    ll at = -q.top();
    q.pop(); cqueue++;
    
    if(at > L) break;

    if(at % Max == L % Max) {
      ll nsol = score[at%Max] + (L/Max);
      if(nsol < sol) sol = nsol;
      }
    
    FOR(bs,0,N-1) {
      ll nat = at + B[bs];
      int npos = nat % Max;
      int nval = score[at % Max];
      if(nat / Max == at / Max) nval++;
      if(score[npos] > nval) {
        score[npos] = nval;
        q.push(-nat);
        }
      }
    }
  
  if(sol == INF)
  printf("Case #%d: IMPOSSIBLE\n", cnum, sol);
  else
  printf("Case #%d: %lld\n", cnum, sol);
  
  if(cqueue > maxqueue) maxqueue = cqueue;
  }

int main() {

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
  
   fprintf(stderr, "queue = %d\n", maxqueue);
   
  // finish
  return 0;
  }

// This solution includes hidden routines to solve test cases in separate
// processes in order to make it faster. I will update them to run on a
// cluster if I get one ;)
