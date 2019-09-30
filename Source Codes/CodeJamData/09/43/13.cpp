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

// for each boy find a girl he likes...

#define MAXBOYS 200
#define MAXGIRLS 200

int boys, girls;

bool likes[MAXBOYS][MAXGIRLS];

int girlFor[MAXBOYS];
int boyFor[MAXGIRLS];

int queue[MAXBOYS], qb, qe;

int findMatching() {
  int comefrom[MAXGIRLS];
  
  FOR(b,0,boys) girlFor[b] = -1;
  FOR(g,0,girls) boyFor[g] = -1;
  
  int cnt = 0;
  
  FOR(b,0,boys) {
    qb = 0; qe = 1; queue[0] = b;
    
    FOR(g,0,girls) comefrom[g] = -1;

    while(qb < qe) {

      int cb = queue[qb++];

      FOR(g,0,girls) if(likes[cb][g]) if(comefrom[g] == -1) {
        comefrom[g] = cb;
//      printf("Try G%d for B%d\n", g, cb);
        if(boyFor[g] == -1) {
          int cg = g;
          while(cg != -1) {
            cb = comefrom[cg];
            swap(girlFor[cb], cg);
            boyFor[girlFor[cb]] = cb;
//          printf("%d -> %d\n", cb, girlFor[cb]);
            }
          goto nextBoy;
          }
        else {
//        printf("- go to B%d\n", boyFor[g]);
          queue[qe++] = boyFor[g];
          }
        }
      }
    
    girlFor[b] = -1; cnt++;

    nextBoy: ;
    }
  
  return cnt;
  }

void solveCase(int cnum) {
  int res = 0;
  
  int N, K;
  bool graph[128][128];
  
  int val[128][128];
  
  scanf("%d%d", &N, &K);
  FOR(n,0,N) FOR(k,0,K) scanf("%d", &val[n][k]);

//  FOR(n,0,N) FOR(k,0,K) printf("%d\n", val[n][k]);

  
  FOR(n,0,N) FOR(m,0,N) {
    graph[n][m] = true;
    FOR(k,0,K) if(val[n][k] >= val[m][k]) graph[n][m] = false;
    }
  
  boys = N; girls = N; FOR(n,0,N) FOR(m,0,N) likes[n][m] = graph[n][m];
  
/*   FOR(n,0,N) {
    FOR(m,0,N) if(graph[n][m]) printf("#"); else printf(".");
    printf("\n");
    } */
  
  printf("Case #%d: %d\n", cnum+1, findMatching());
  }

int main() {
  int N;
  string Nstr = getLine();
  N = atoi(Nstr.c_str());
  FOR(cnum,0,N) 
    solveCase(cnum);
  return 0;
  }
