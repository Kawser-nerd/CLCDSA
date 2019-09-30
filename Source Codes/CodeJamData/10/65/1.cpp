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

#include <complex>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<int> vll;
typedef vector<string> vs;
typedef complex<ld> cld;

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

int su;

cld p[2000];

int stable[2000][2000];

bool isort(int a, int b) {
  if(abs(arg(p[a] - p[su]) -arg(p[b] - p[su])) < 1e-9) {
    return abs(p[a] - p[su]) > abs(p[b] - p[su]);
    }
  return arg(p[a] - p[su]) < arg(p[b] - p[su]);
  }

#define A(x) arg(p[stable[at][x]]-p[at])
#define D(x) abs(p[stable[at][x]]-p[at])

int best, N, R;

int bscore(int at, int prev, ld maxl, int score) {

  // printf("[%4d] %4d %4d %lf\n", score, at, prev, double(maxl));

  if(score > best) best = score; 

  ld qarg = arg(p[at] - p[prev]);

  int ati = 0;

  // printf("qarg = %lf\n", qarg);

  if(A(0) < qarg-1e-9) {
    while(ati < N+1 && A(ati) < qarg-1e-9) ati++;
    }
  else {
    while(ati < N+1 && A(ati) >= qarg-1e-9) ati++;
    if(ati < N+1) {
      while(ati < N+1 && A(ati) < qarg-1e-9) ati++;
      }
    }

  // printf("ati = %d\n", ati);
  // exit(0);

  FOR(pl,0,N+1) {
    int ti = (ati + pl) % (N+1);

    int pid = stable[at][ti];
        
    if(pid == at) continue;

    ld dist = D(ti);

    // if(cnum == 6) printf("{pt %d [%d,%d] D%lf}\n", pid, int(p[pid].real()), int(p[pid].imag()), double(dist));

    if(dist <= maxl - 0.1) {
      bscore(stable[at][ti], at, maxl - dist, score+1);
      maxl = dist - 0.75;
      }

    }
  
  }

void solveCase() {
  int res = 0;

  scanf("%d%d", &N, &R);

  FOR(n,0,N) {
    int x, y;
    scanf("%d%d", &x, &y);
    p[n] = cld(x,y);
    }

  // if(cnum != 6) return;

  p[N] = cld(-R, 0);

  FOR(u,0,N) {
    su = u;
    FOR(a,0,N+1) stable[u][a] = a;
    sort(stable[u], stable[u]+N+1, isort);

    // printf("%d: ", u); FOR(a,0,N+1) printf(" %d", stable[u][a]); printf("\n");
    }

  best  = 0;
  bscore(0, N, R, 0);
  
  // proceed
  
  printf("Case #%d: %d\n", cnum, best);
  // exit(0);
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

