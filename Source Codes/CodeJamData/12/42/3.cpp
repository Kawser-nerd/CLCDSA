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

int r[1200];

int y[1200], x[1200];

ll sqr(ll x) { return x*x; }
ll hyp(ll x, ll y) { return x*x+y*y; }

int ord[1200];

void solveCase() {
  int res = 0;
  // proceed
  
  int N, X, Y;
  err=scanf("%d%d%d", &N, &X, &Y);
  FOR(a,0,N) err=scanf("%d", &r[a]);
  
  FOR(a,0,N) ord[a] = a;
  
  FOR(a,1,N)
    if(a>0 && r[ord[a]] > r[ord[a-1]]) swap(ord[a], ord[a-1]), a -= 2;
    
  // FOR(a,0,N) printf("%d\n", r[ord[a]]);
  
  // sort(r, r+N);
  // reverse(r, r+N);
  
  srand(time(NULL));
  
  FOR(a,0,N) {

    bool ok = false;
    
    while(!ok) { 

    int xx = rand() % (X+1);
    int yy = rand() % (Y+1);

      ok = true;
      FOR(b,0,a) if(hyp(xx-x[ord[b]], yy-y[ord[b]]) < sqr(r[ord[a]]+r[ord[b]])) ok = false;
      if(ok) {
        x[ord[a]] = xx, y[ord[a]] = yy;
        //printf("%d R%d: %d,%d\n", ord[a], r[ord[a]], xx, yy);
        break;
        }
      }
    }
  
  FOR(a,0,N) FOR(b,0,N) if(a!=b) if(hyp(x[a]-x[b], y[a]-y[b]) < sqrt(r[a]+r[b])) 
    printf("err %d %d\n", a, b);
  
  printf("Case #%d:", cnum+1);
  FOR(u,0,N) printf(" %d %d", x[u], y[u]);
  printf("\n");
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
