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

void moveother(int& at, int goal, int ttgo) {
  if(abs(at-goal) < ttgo) at = goal;
  else if(at<goal) at += ttgo;
  else at -= ttgo;
  }

string dict[20000];
string dlst[300];

int points[20000];
int bro[20000];
int pset[20000];

int inset[20000], ssi;

bool iscomp(int a, int b) {
  if(pset[a] != pset[b]) return pset[a] < pset[b];
  return a < b;
  }

void solveCase() {

  int N, M;
  
  scanf("%d%d", &N, &M);
  char buf[100];
  for(int a=0; a<N; a++) {
    scanf("%s", buf);
    dict[a] = buf;
    }
  for(int b=0; b<M; b++) {
    scanf("%s", buf);
    dlst[b] = buf;
    }
  
  printf("Case #%d:", cnum);
  
  for(int b=0; b<M; b++) {
    for(int a=0; a<N; a++)
      points[a] = 0, bro[a] = (a+1) % N, pset[a] = 0;

    for(int p=-1; p<26; p++) {
      char c = p==-1 ? '.' : dlst[b][p];
      for(int a=0; a<N; a++) if(bro[a] < a) {
        int at0 = bro[a], at = at0, wl = Size(dict[a]);
        bool exist = false;
        ssi = 0;
        //printf("[");
        do {
          inset[ssi] = at; 
          pset[at] = 0;
          if(p == -1) pset[ssi] = Size(dict[at]);
          else for(int p=0; p<wl; p++) if(dict[at][p] == c)
            pset[at] |= (1<<p);
          if(pset[at] != 0) exist = true;
          // printf("%d:%d,", at, pset[ssi]);
          if(at == bro[at]) exit(1);
          at = bro[at];
          ssi++;
          }
        while(at != at0);
        //printf("]");
        if(exist) for(int i=0; i<ssi; i++) {
          if(pset[inset[i]] == 0) points[inset[i]]++;
          }
        sort(inset, inset+ssi, iscomp);
        inset[ssi] = 15000; pset[150000] = -777;
        int lf = 0;
        for(int la=1; la<=ssi; la++) if(pset[inset[la]] != pset[inset[lf]]) {
          // lf .. la-1
          // printf("{%d %d}", lf, la-1);
          for(int u=lf; u<la-1; u++) bro[inset[u]] = inset[u+1];
          bro[inset[la-1]] = inset[lf];
          lf = la;
          }
        }
      }
    
    int idx = -1, mpt = -1;
    for(int k=0; k<N; k++) if(points[k] > mpt)  mpt = points[k], idx = k;
    printf(" %s", dict[idx].c_str());
    }
  printf("\n");
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
