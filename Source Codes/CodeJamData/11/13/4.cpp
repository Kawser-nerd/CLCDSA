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

void moveother(int& at, int goal, int ttgo) {
  if(abs(at-goal) < ttgo) at = goal;
  else if(at<goal) at += ttgo;
  else at -= ttgo;
  }

int c[999], s[999], t[999];

bool have[999];

void solveCase() {

  int N, M;
  
  scanf("%d", &N);
  for(int i=0; i<N; i++) scanf("%d%d%d", c+i, s+i, t+i);

  scanf("%d", &M); M += N;
  for(int i=N; i<M; i++) scanf("%d%d%d", c+i, s+i, t+i);
  
  int best = -1;
  
  for(int ss=0; ss<=M; ss++) {
    for(int k=0; k<M; k++) have[k] = true;
    int haven = N;
    int cscore = 0;
    int turns = 1;
    int toget = ss;
    
    again:
    // printf("T %d S %d H %d\n", turns, cscore, haven);
    if(haven > M) { haven = M; }
    
    // free turns
    if(turns) for(int k=0; k<haven; k++) if(have[k] && t[k]) {
      // printf("[get %d for turns]\n", k);
      haven += c[k], cscore += s[k], turns += t[k]-1, have[k] = false;
      goto again;
      }

    // get a card source 'toget' times
    if(toget && turns) {
      int maxscore = -1, idx = -1;
      for(int k=0; k<haven; k++) if(have[k] && c[k] && s[k] > maxscore) idx = k, maxscore = s[k];
      if(idx >= 0) {
        // printf("[get %d for cards]\n", idx);
        haven += c[idx], cscore += s[idx], turns += t[idx]-1, have[idx] = false;
        toget--;
        goto again;
        }
      }
    
    // get a score source
    if(turns) {
      int maxscore = -1, idx = -1;
      for(int k=0; k<haven; k++) if(have[k] && s[k] > maxscore) idx = k, maxscore = s[k];
      if(idx >= 0) {
        // printf("[get %d for score]\n", idx);
        haven += c[idx], cscore += s[idx], turns += t[idx]-1, have[idx] = false;
        goto again;
        }
      }
    
    if(cscore > best) best = cscore;
    }
      
  printf("Case #%d: %d\n", cnum, best);
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
    
  // finish
  return 0;
  }

// This solution includes hidden routines to solve test cases in separate
// processes in order to make it faster. I will update them to run on a
// cluster if I get one ;)
