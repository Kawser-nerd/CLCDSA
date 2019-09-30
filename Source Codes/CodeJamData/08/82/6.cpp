#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
//#include <iostream>
//#include <set>
#include <map>
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

struct offer {
  int s;
  int e;
  int col;
  };

map<string, int> names;

offer off[400];

bool cok[1000];

void solveCase(int cnum) {
  int res = 0;
  
  names.clear();
  
  int N = getNum();
  
  int difc = 0;
  
  FOR(a,0,N) {
    string s = getLine();
    char buf[80];
    sscanf(s.c_str(), "%s%d%d", &buf, &off[a].s, &off[a].e);
    
    if(names.count(buf) == 0) {
      names[buf] = difc++;
      }
    
    off[a].col = names[buf];
    }
  
  // sort(off, off+N, offersort);
  
  int best = 1000;
  
  FOR(a,0,1000) cok[a] = false;
  
  for(int c0=0; c0<difc; c0++)
  for(int c1=0; c1<=c0; c1++)
  for(int c2=0; c2<=c1; c2++) {
    cok[c0] = true;
    cok[c1] = true;
    cok[c2] = true;
    
    int atsec = 0;
    int ssf = 0;
    while(atsec < 10000) {
//    printf("at: %d\n", atsec);
      int next = -1;
      FOR(a,0,N)
        if(cok[off[a].col] && off[a].s <= atsec+1)
          next >?= off[a].e;
      if(next <= atsec) break;
      atsec = next; ssf++;
      }
//  printf("at: %d ssf: %d\n", atsec, ssf); 
    
    if(atsec == 10000) best <?= ssf;

    cok[c0] = false;
    cok[c1] = false;
    cok[c2] = false;
    }

  if(best == 1000)
    printf("Case #%d: IMPOSSIBLE\n", cnum+1, best);
  else
    printf("Case #%d: %d\n", cnum+1, best);
  }

int main() {
  int N;
  string Nstr = getLine();
  N = atoi(Nstr.c_str());
  FOR(cnum,0,N) 
    solveCase(cnum);
  return 0;
  }
