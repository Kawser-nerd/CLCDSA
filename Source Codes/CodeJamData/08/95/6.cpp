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

int sx, sy;
vector <string> mp;

int res;

int mb[30], mt[30];

int dpo[40000], dpn[40000];

int bca[40000];

void solveCase(int cnum) {
  FOR(y,0,40000) bca[y] = bitc(y);
  res = 0;
  string s = getLine();
  sscanf(s.c_str(), "%d%d", &sy, &sx);
  mp.clear();
  FOR(y,0,sy) {
    mp.push_back(getLine());
//  printf("%s\n", mp[y].c_str());
    }

  FOR(y,0,sy) mb[y] = 0, mt[y] = 0;
  FOR(y,0,sy) FOR(x,0,sx) {
    if(mp[y][x] == '#') {
      mb[y] |= (1<<x);
      mt[y] |= (1<<x);
      }
    if(mp[y][x] == '?') {
      mt[y] |= (1<<x);
      }
    }
  
  FOR(t,0,1<<sx) dpn[t] = 0;
  
  FOR(y,0,sy) {
    FOR(t,0,1<<sx) dpo[t] = dpn[t], dpn[t] = 0;
//  if(cnum==0) printf("%d, %d: y%d\n", mb[y], mt[y], y);
    FOR(t,0,1<<sx)
      if(((t & mb[y]) == mb[y]) && ((t & mt[y]) == t))
      if((t & (t>>1) & (t>>2) & ~(mb[y]>>1)) == 0)
      if((((~t) & ((~t)>>1) & ((~t)>>2)) & (mt[y]>>1)) == 0)
        {
        FOR(u,0,1<<sx) {
//        dpn[t] >?= dpo[u] + 4*bitc(t) - 2*bitc(t&u) - 2*bitc(t&(t<<1));
          dpn[t] >?= dpo[u] + (bca[t]<<1) - bca[t&u] - bca[t&(t<<1)];
          }
        // if(cnum==0) printf("%d, %d: %d\n", t, mb[y], mt[y]);
        }
    // if(cnum == 0) FOR(t,0,1<<sx) printf("%d: %d\n", t, dpn[t]);
    }
  
  int best = 0;
  FOR(t,0,1<<sx) best >?= dpn[t];
  
  printf("Case #%d: %d\n", cnum+1, 2*best);
  }

int main() {
  int N;
  string Nstr = getLine();
  N = atoi(Nstr.c_str());
  FOR(cnum,0,N) 
    solveCase(cnum);
  return 0;
  }
