#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <queue>

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

int Z;
int zx[1000], zy[1000], zm[1000];

int iabs(int x) { return x>0?x:-x;}

typedef pair<int, pair<int, int> > str;

int bestsc[1000], bestaltsc[1000];

void solveCase() {
  int res = 0;
  
  err=scanf("%d", &Z);
  FOR(z,0,Z) err=scanf("%d%d%d", &zx[z], &zy[z], &zm[z]);
  
  for(int u=1; u<Z; u++) if(zm[u] < zm[u-1])
    swap(zm[u], zm[u-1]), swap(zx[u], zx[u-1]), swap(zy[u], zy[u-1]);
 
  zx[666] = zy[666] = 0;
  
  int bestscore = 0;
  
  priority_queue<str> q;
  
  FOR(u,0,Z) {
    int ttg = 100*max(iabs(zx[u]), iabs(zy[u]));
    if(ttg < zm[u]) ttg = zm[u];
    if(ttg <= zm[u] + 1000) q.push(make_pair(-ttg, make_pair(1, u)));
  }
      
  FOR(u,0,Z) bestsc[u] = bestaltsc[u] = 0;
  while(!q.empty()) {
     str S = q.top();
     q.pop();
     int tim = -S.first;
     int zid = S.second.second;
     int zsc = S.second.first;
     //printf("T=%d ID=%d (%d,%d,%d) sc=%d\n", tim, zid, zx[zid], zy[zid], zm[zid], zsc);
     if(zsc > bestscore) bestscore = zsc;
     if(1) { if(bestsc[zid] < zsc) {
       // bestaltsc[zid] = bestsc[zid];
       bestsc[zid] = zsc;
     } else continue; }
       
     FOR(t,0,Z) if(t != zid) {
       int ttg = tim + max(750, 100*max(iabs(zx[t]-zx[zid]), iabs(zy[t]-zy[zid])));
       if(ttg < zm[t]) ttg = zm[t];
       //printf("got: %d (%d)\n", ttg, t);
       if(ttg <= zm[t] + 1000) q.push(make_pair(-ttg, make_pair(zsc+1, t)));
     }
  }
  //printf("Z=%d\n", Z);
  
  /*for(int u=0; u<Z; u++) {
    //printf("u=%d q=%d\n", u, q);
    int oq = q;
    for(int t=0; t<oq; t++) {
	zid[q] = u;  tim[q] = ttg; zsc[q] = zsc[t]+1;
	zfr[q] = t;
	//printf("zsc=%d (%d)\n", zsc[q], t);
	if(zsc[q] > bestscore) bestscore = zsc[q];
	q++;
      }
    }
    
    int ttg = 100*max(iabs(zx[u]), iabs(zy[u]));
    if(ttg < zm[u]) ttg = zm[u];
    if(ttg <= zm[u] + 1000) {
      zid[q] = u; tim[q] = ttg; zsc[q] = 1;
      zfr[q] = -1;
      q++;
      if(bestscore == 0) bestscore = 1;
    }
    
  } */
  // proceed
  
  //FOR(t,0,q) printf("%2d. I=%d T=%d S=%d [%d]\n", t, zid[t], tim[t], zsc[t], zfr[t]);
  
  printf("Case #%d: %d\n", cnum+1, bestscore);
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
