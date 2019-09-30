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

ll pos[64];

#undef LS
#define LS !=

void addp(set<ll>& dest, set<ll> src, ll bonus) {
  FOR(it,src.begin(),src.end()) dest.insert(*it + bonus);
  }

ll best = 0, F;

void trybest(set<ll>& ls, set<ll> &rs, ll bonus) {
  if(rs.empty() || ls.empty()) return;
  typeof(ls.begin()) li = ls.begin();
  typeof(rs.begin()) ri = rs.end(); ri--;

  while(true) {
    ll cval = *li + *ri;
    // printf("%d\n", cval+bonus <= F);
    if(cval+bonus <= F && cval+bonus > best) best = cval+bonus;
    if(cval+bonus <= F) { 
      li++; if(li == ls.end()) return;
      }
    else { if(ri == rs.begin()) return; ri--; }
    }
  }

void solveCase() {
  int N;

  cin >> N;

  FOR(k,0,N) cin >> pos[k];

  cin >> F;

  /*
  N = 30;
  int step = 1;
  pos[0] = 0; pos[29] = 0;
  FOR(k,1,15) pos[k] = pos[k-1] + step, step *= k;
  FOR(k,0,15) pos[29-k] = 1 + 2*pos[14] - pos[k];
  FOR(k,0,30) cout << pos[k] << endl;
  F = (pos[29] - pos[0]) * 2;
  cout << F << endl; */
  
  sort(pos, pos+N);

  F /= 2;

  F -= (pos[N-1] - pos[0]);
  
  // printf("[F = %d]\n", int(F));

  if(F < 0) {
    cout << "Case #" << cnum << ": NO SOLUTION" << endl;
    return;
    }

  best = 0;

  if(N>=4) {

  set<ll> partial[31][16];

  partial[1][0].insert(0);
  partial[N-2][0].insert(0);

  int cutat = N/2;
     
  FOR(ps,2,cutat) FOR(n,0,16) {
    ll aval = n * (pos[ps] - pos[ps-1]);
    if(n) addp(partial[ps][n], partial[ps-1][n-1], aval);
    if(n<15) addp(partial[ps][n], partial[ps-1][n+1], aval);
    addp(partial[ps][n], partial[ps-1][n], aval);
    // if(Size(partial[ps][n]))
    //   printf("%3d %3d %7d\n", ps, n, Size(partial[ps][n]));
    }

  for(int ps = N-3; ps >= cutat; ps--) FOR(n,0,16) {
    ll aval = n * (pos[ps+1] - pos[ps]);
    if(n) addp(partial[ps][n], partial[ps+1][n-1], aval);
    if(n<15) addp(partial[ps][n], partial[ps+1][n+1], aval);
    addp(partial[ps][n], partial[ps+1][n], aval);
    // if(Size(partial[ps][n]))
    //   printf("%3d %3d %7d\n", ps, n, Size(partial[ps][n]));
    }
 
  // printf("x\n");
  FOR(n0,0,16) FOR(n1,0,16) FOR(na,0,16) if(abs(n1-na) <= 1 && abs(n0-na) <= 1)
    trybest(partial[cutat-1][n0], partial[cutat][n1], na * (pos[cutat] - pos[cutat-1]));

  //  printf("y\n");
}

   notry:
  cout << "Case #" << cnum << ": " << (best + pos[N-1] - pos[0]) * 2 << endl;

  return;
  }

int main() {

  /*FOR(a,1,31) printf("%2d: %d\n", a, best(1,a));
  return 0;
  */

  // solveCase(); return 0;

  cin >> Tests;
  
  for(cnum=1; cnum<=Tests; cnum++)
    solveCase();
    
  // finish
  return 0;
  }

