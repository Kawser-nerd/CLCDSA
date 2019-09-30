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

int qb, qe;
int qx[3000], qy[3000];

int fid[50][50];
int fdi[50][50];

int res;

void spread(int x1, int y1, int x2, int y2) {
//printf("(%d,%d)-(%d,%d): %d to %d\n", x1,y1, x2,y2, fid[y1][x1], fid[y2][x2]);

  if(mp[y2][x2] == '.') {
    // go swim
    }
  else if(fid[y2][x2] == fid[y1][x1]) {
    // do nothing
    }
  else if(fid[y2][x2] == -1) {
    fid[y2][x2] = fid[y1][x1];
    fdi[y2][x2] = fdi[y1][x1]+1;
    res += fdi[y2][x2];
    qx[qe] = x2; qy[qe] =  y2; qe++;
    }
  else {
    int i1 = fid[y1][x1], i2 = fid[y2][x2];
    FOR(y,0,sy) FOR(x,0,sx) if(fid[y][x] == i2) fid[y][x] = i1;
    int d1 = fdi[y1][x1], d2 = fdi[y2][x2];
    if(d2 != d1 && d2 != d1+1) printf("ERROR!\n");
//  printf("(%d,%d)-(%d,%d): d1/d2: %d %d\n", x1,y1, x2,y2, d1, d2);
    res += (d1+1) * (d2+1);
    }
  }

void solveCase(int cnum) {
  res = 0;
  string s = getLine();
  sscanf(s.c_str(), "%d%d", &sy, &sx);
  mp.clear();
  FOR(y,0,sy) {
    mp.push_back(getLine());
//  printf("%s\n", mp[y].c_str());
    }
  
  qb = 0; qe = 0;

  int nfo = 0;
  FOR(y,0,sy) FOR(x,0,sx) {
    fid[y][x] = -1;
    fdi[y][x] = -1;
    if(mp[y][x] == 'T') {
      fid[y][x] = nfo++;
      fdi[y][x] = 0;
      qx[qe] = x; qy[qe] = y;
      qe++;
      }
    }
//printf("nfo=%d\n", nfo);
  
  while(qb < qe) {
    int x = qx[qb], y = qy[qb];
    if(x+1<sx) spread(x,y,x+1,y);
    if(x>0) spread(x,y,x-1,y);
    if(y+1<sy) spread(x,y,x,y+1);
    if(y>0) spread(x,y,x,y-1);
    qb++;
    }
  
  printf("Case #%d: %d\n", cnum+1, res);
  }

int main() {
  int N;
  string Nstr = getLine();
  N = atoi(Nstr.c_str());
  FOR(cnum,0,N) 
    solveCase(cnum);
  return 0;
  }
