#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <iostream>
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

int q[101][101][101][101];

int bsum[701];

int solve(int k, ll C) {
  return -1;
  int boxes = 0;
  int leftover = 0;
  int tleftover = 0;
  printf("[");
  FOR(u, 1, C+1) {
    int ob = boxes;
    boxes += k/u;
    if(leftover < k%u) boxes++, leftover += u + tleftover, tleftover += u-1;
    else leftover -= k%u;
    printf("%4d (%d/%d)", boxes-ob, leftover, tleftover);
    }
  printf("]");
  return boxes;
  }

void prepare() {

  FOR(a,0,701) bsum[a] = 1000;
  
  FOR(a,0,101) FOR(b,0,101) FOR(c,0,101) FOR(d,0,101) {

    int bs1 = 0, bs2 = 0, bs3 = 0, bs4 = 0;

    if(a>=1) 
      bs1 = 1+q[a-1][b][c][d];
    if(a>=2)
      bs2 = 1+q[a-2][b][c][d];

    if(b>=1)
      bs2 = 1 + q[a][b-1][c][d];

    if(a>=3)
      bs3 = 1+q[a-3][b][c][d];

    if(a && b)
      bs3 = 1  + q[a-1][b-1][c][d];

    if(c)
      bs3 = 1 + q[a][b][c-1][d];

    if(a >= 4)
      bs4 = 1 + q[a-4][b][c][d];
    if(a >=2 && b)
      bs4 = 1 + q[a-2][b-1][c][d];
    if(b >= 2)
      bs4 = 1 + q[a][b-2][c][d];
    if(c && a)
      bs4 = 1 + q[a-1][b][c-1][d];
    if(d)
      bs4 = 1 + q[a][b][c][d-1];

    q[a][b][c][d] = bs1 <? bs2 <? bs3; // <? bs4;

    if(a+b+c+d < bsum[q[a][b][c][d]]) bsum[q[a][b][c][d]] = a+b+c+d;
    }

  FOR(t,0,701) {
    int bs;

    int algo = solve(t, 4);

    bs = bsum[t];

    // if(bs == algo) continue;

    printf("%3d: %3d (algo=%3d)", t, bs, algo);

    FOR(a,0,bs+1) if(a<=100) FOR(b,0,bs+1-a) if(b<=100) 
    FOR(c,0,bs+1-a-b) if(c<=100)
    {
      int d = bs-a-b-c; if(d<=100)
      if(q[a][b][c][d] == t) {
        printf("  %3d %3d %3d %3d\n", a, b, c, d);
        goto xx;
        }
      }
    xx: ;
    }
  exit(0);
  }

int bonus[6] = {0, 0, 1, 0, 1, 1};

void solveCase() {
  int k;
  ll C;
  cin >> k >> C;

  int res;

  res = 0;
  if(C == 1)
    res = k;
  if(C == 2)
    res = k + (k+1) / 2;
  if(C == 3)
    res = k + (k+1) / 2 + k/3 + bonus[k%6];
  
  printf("Case #%d: %d\n", cnum, res);
  }

int main() {

  // prepare();

  if(0)
    Tests = 1;
  else if(1)
    cin >> Tests;
  else {
    string Nstr = getLine();
    Tests = atoi(Nstr.c_str());
    } 
  
  for(cnum=1; cnum<=Tests; cnum++)
    solveCase();
    
  // finish
  return 0;
  }

