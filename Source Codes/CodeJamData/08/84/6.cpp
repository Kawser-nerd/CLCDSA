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

#define t k

struct placement {
  int t[10];
  };

vector<placement> queue;

int N, K, P;

int got[50000][10];
int gq[50000];

int placeid(placement p) {
  int renum[20];
  FOR(a,0,K) renum[a] = -1;
  int rid = 0;

  FOR(a,0,P) if(p.k[a] != -1 && renum[p.k[a]] == -1) {
    renum[p.k[a]] = rid++;
    }
  
  if(rid < K) return -1;
  
  FOR(a,0,P) if(p.k[a] != -1) p.k[a] = renum[p.k[a]];
  
  FOR(id,0,Size(queue)) {
    FOR(d,0,P) if(p.k[d] != queue[id].k[d]) goto next;
    return id;
    next: ;
    }
  
//FOR(d,0,P) printf("%3d", p.k[d]); printf("\n");
  queue.push_back(p);
  return Size(queue)-1;
  }

#define Prime 30031

int solve() {
  placement PL;
  FOR(u,0,K) PL.t[u] = u;
  FOR(u,K,P) PL.t[u] = -1;

  queue.clear();
  placeid(PL);
    
  int cid = 0;
    
  while(cid < queue.size()) {
    PL = queue[cid];
    FORREV(u,1,P) PL.t[u] = PL.t[u-1];
    
    gq[cid] = 0;
    
    FOR(ini,0,K) {
      PL.t[0] = ini;
      int c2 = placeid(PL);
      if(c2 >= 0)
        got[cid][gq[cid]++] = c2;
      }
    
    cid++;
    }
  
  int QS = queue.size();

  int qtab[QS];
  FOR(u,0,QS) qtab[u] = 0;
  qtab[0] = 1;
  
  FOR(d,K,N) {
    int nqtab[QS];
    FOR(u,0,QS) nqtab[u] = 0;
    FOR(u,0,QS) FOR(b,0,gq[u]) {
      nqtab[got[u][b]] += qtab[u];
      nqtab[got[u][b]] %= Prime;
      }

    FOR(u,0,QS) qtab[u] = nqtab[u];
    }
  
  int res = 0;
  FOR(u,0,QS) if(queue[u].t[K-1] == K-1) {
    res += qtab[u];
    res %= Prime;
    }
  
//printf("%d,%d: %d\n", K,P, queue.size());
  return res;
  }

void solveCase(int cnum) {
  int res = 0;
  string s = getLine();
  sscanf(s.c_str(), "%d%d%d", &N, &K, &P);
  
  // if(false) res=1; //
  if(K == P) res = 1;
  else if(P < K) res = 0;
  else res = solve();
  
  printf("Case #%d: %d\n", cnum+1, res);
  }

int main() {
  int N;
  string Nstr = getLine();
  N = atoi(Nstr.c_str());
  FOR(cnum,0,N) 
    solveCase(cnum);
  return 0;
/*for(K=0; K<10; K++)
  for(P=1; P<11; P++) {
    solve();
    } */
  }
