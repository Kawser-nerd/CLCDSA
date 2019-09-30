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

char car[200][200];

string scar[200];

int ibeg[30], iend[30], itot[30], imid[30];

int N;

bool incyc[26];

#define P 1000000007

char edge(int a) {
  char c = 'a' + a;
  FOR(n,0,N) if(car[n][0] == c && scar[n][Size(scar[n])-1] != c)
    return scar[n][Size(scar[n])-1] - 'a';
  return 0;
  }

ll mul(ll a, ll b) { return (a*b) % P; }

ll fac(int u) {
  ll res = 1;
  FOR(k, 2, u+1) res = mul(res, k);
  return res;
  }

int id[200];

void solveCase() {
  int res = 0;

  err = scanf("%d", &N);
  
  FOR(n, 0, N) { err = scanf("%s", car[n]); scar[n] = car[n]; 
    // printf("*%s\n", car[n]);
    }
  
  // BRUTE
  
  FOR(n,0,N) id[n] = n;
  int ile = 0;
  if(N <= 5) do {
    string t;
    FOR(n,0,N) t += scar[id[n]];
    bool ok = true;
    for(int a=0; a<26; a++) {
      char ch = 'a' + a;
      int L = Size(t);
      int c = SUM(k, 0, L, t[k] == ch ? 1 : 0);
      int fi = FIRST(k, 0, L, t[k] == ch);
      int la = LAST(k ,0, L, t[k] == ch);
      if(c && fi+c != la+1) ok = false;
      }
    // if(ok) printf("%s\n", t.c_str());
    if(ok) ile++;
    }
  while(next_permutation(id, id+N));
  else ile = -1;
  // printf("ile = %d\n", ile);
  
  bool haserror = false;
  
  ll cnt = 1;

  for(int a=0; a<26; a++) ibeg[a] = iend[a] = itot[a] = imid[a] = 0;
  
  for(int a=0; a<26; a++) {
    char ch = 'a' + a;
    for(int i=0; i<N; i++) {
      string s = car[i];
      int L = Size(s);
      int c = SUM(k, 0, L, s[k] == ch ? 1 : 0);
      if(c == L) itot[a]++;
      else if(c) {
        int fi = FIRST(k, 0, L, s[k] == ch);
        int la = LAST(k ,0, L, s[k] == ch);
        if(fi+c != la+1) haserror = true;
        else if(fi == 0) ibeg[a]++;
        else if(la == L-1) iend[a]++;
        else imid[a]++;
        }
      }
    if(imid[a] > 1) haserror = true;
    if(ibeg[a] > 1 || iend[a] > 1) haserror = true;
    if(imid[a] && ibeg[a]) haserror = true;
    if(imid[a] && iend[a]) haserror = true;
    if(imid[a] && itot[a]) haserror = true;
    
    cnt = mul(cnt, fac(itot[a]));
    
    if(0) if(ibeg[a] || imid[a] || iend[a] || itot[a])
      printf("(%d) %d %d %d %d\n", a, ibeg[a], imid[a], iend[a], itot[a]);
    }
  
  if(haserror) cnt = 0;
  else {
  
    // take cycles
    for(int a=0; a<26; a++) incyc[a] = false;
    
    int blox = 0;
    
    for(int a=0; a<26; a++) if(ibeg[a] && !iend[a]) {
      blox++;
      int z = a;
      // printf("go\n");
      while(ibeg[z]) {
        // printf(".. (%d)\n", z);
        incyc[z] = true;
        z = edge(z);
        }
      incyc[z] = true;
      // printf("  to %d\n", z);
      }
    
    int numcyc = 0, cyclen = 0;
    
    for(int a=0; a<26; a++) if(ibeg[a] && !incyc[a]) {
      numcyc++;
      int z = a;
      do {
        incyc[z] = true;
        cyclen++;
        z = edge(z);
        }
      while(z != a);
      }

    if(numcyc > 0) cnt = 0;
    
//  if(blox == 0) {
//    cnt = mul(cnt, cyclen);
//    for(int i=0; i<26; i++) if(itot[i] && !incyc[i]) cnt = 0;
//    }
//  else {
    // printf("cnt = %d blox = %d\n", int(cnt), blox);
    for(int i=0; i<26; i++) if(itot[i] && !incyc[i]) { 
      blox++; // printf("blox %d\n", i);
      }
    // printf("cnt = %d blox = %d\n", int(cnt), blox);
    cnt = mul(cnt, fac(blox));
//    }
    }
    
  // proceed
    
  printf("Case #%d: %d\n", cnum, int(cnt));

  if(ile >= 0 && ile != cnt) {
    printf("ERROR\n");
    FOR(k,0,N) printf("%s\n", car[k]);
    }
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

// This solution includes hidden routines to solve test cases in separate
// processes in order to make it faster. I will update them to run on a
// cluster if I get one ;)
