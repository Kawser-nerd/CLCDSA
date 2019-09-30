#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
#include <iostream>
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

#define x1 XX
#define y1 YY

int sx, sy, x1, y1, x2, y2, xs, ys;

int qu[2000000];
bool mp[1048576];

void getcord(int& x, int& y) {
  string s = getLine();
  sscanf(s.c_str(), "%d %d", &x, &y);
  }

bool ok(int x, int y) {
  return x >= 0 && x < sx && y >= 0 && y < sy;
  }

int lsize(int cx, int step, int siz) {
//printf("lsize(%d,%d,%d)\n", cx, step, siz);
  if(step == 0) return 2000000;
  if(step > 0) return 1 + (siz-1-cx) / step;
  if(step < 0) return lsize(siz-1-cx, -step, siz);
  }

void solveCase(int cnum) {
  ll res = 0;
  
  getcord(sx, sy);
  getcord(x1, y1);
  getcord(x2, y2);
  getcord(xs, ys);
  
  if(x1 == 0 && x2 == 0) {
    swap(x1, y1);
    swap(x2, y2);
    swap(xs, ys);
    swap(sx, sy);
//  printf("%d %d %d %d %d %d %d %d\n", sx,sy,xs,ys,x2,y2,x1,y1);
    }
  
  if(y1*ll(x2) == y2*ll(x1)) {
    int qb = 0, qe = 1;
    qu[0] = xs;
    FOR(y,0,sx) mp[y] = false;
    mp[xs] = true;
    while(qb < qe) {
      int cx = qu[qb];
      int cy = ys + y1 * ll(cx-xs) / x1;
      
      if(ok(cx+x1, cy+y1)) if(!mp[cx+x1]) {
        mp[cx+x1] = true;
        qu[qe++] = cx+x1;
        }

      if(ok(cx+x2, cy+y2)) if(!mp[cx+x2]) {
        mp[cx+x2] = true;
        qu[qe++] = cx+x2;
        }
      qb++;
      }
    res = qe;
    }
  
  else {
//  printf("main\n");
    while(ok(xs, ys)) {
      res += lsize(xs, x2, sx) <? lsize(ys, y2, sy);

      while(!ok(xs+x1, ys+y1)) {
        xs += x2; ys += y2;
        if(!ok(xs,ys)) goto done;
        }
      
      xs += x1; ys += y1;
      }
    }
  
  done: 
  cout << "Case #" << cnum+1 << ": " << res << endl;
  // printf("Case #%d: %d\n", cnum+1, res);
  }

int main() {
  int N;
  string Nstr = getLine();
  N = atoi(Nstr.c_str());
  FOR(cnum,0,N) 
    solveCase(cnum);
  return 0;
  }
