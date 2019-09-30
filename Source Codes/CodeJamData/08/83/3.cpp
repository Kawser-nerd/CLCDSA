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

int N, K;

int v0[1000], v1[1000];

#define Prime 1000000009

int deg[1000];

int parent[1000];

void doDFS(int at, int from) {
  parent[at] = from;
  FOR(k,0,N-1) {
    if(v0[k] == at && v1[k] != from)
      doDFS(v1[k], at);
    if(v1[k] == at && v0[k] != from)
      doDFS(v0[k], at);
    }
  }

void solveCase(int cnum) {
  
  string s = getLine();
  sscanf(s.c_str(), "%d%d", &N, &K);
  
  FOR(u,0,N) deg[u] = 0;
  
  FOR(u,0,N-1) {
    s = getLine();
    sscanf(s.c_str(), "%d%d", &v0[u], &v1[u]);
    v0[u]--;
    v1[u]--;
    deg[v0[u]]++;
    deg[v1[u]]++;
    }
    
  int tv[2];
  
  for(int tr=0; tr<1; tr++) {

    int root = 0;
    FOR(u,0,N) if(deg[u] == 1) { root = u; if(tr) break; }

    doDFS(root, -1);
  
    ll res = K;
    
//  FOR(u,0,N) printf("%d %d\n", u, deg[u]);
    
    FOR(u,0,N) if(u != root) {
    
//    printf("At: %d parent: %d deg: %d\n", u, parent[u], deg[u]);
    
      int edgesToColor = deg[u] - 1;
      int bannedColors = deg[parent[u]];
      int colorsFree = K - bannedColors;
    
      if(colorsFree < 0) colorsFree = 0;

      FOR(v,0,edgesToColor) {
        res *= colorsFree;
        res %= Prime;
        colorsFree--;
        }
      }
    
    printf("Case #%d: %d\n", cnum+1, res);
    
    tv[tr] = res;
    }
  
/*  if(tv[0] != tv[1]) {
    printf("N,K: %d,%d\n", N,K);
    FOR(u,0,N-1) printf("%d %d\n", v0[u], v1[u]); 
    } */
  }

int main() {
  int N;
  string Nstr = getLine();
  N = atoi(Nstr.c_str());
  FOR(cnum,0,N) 
    solveCase(cnum);
  return 0;
  }
