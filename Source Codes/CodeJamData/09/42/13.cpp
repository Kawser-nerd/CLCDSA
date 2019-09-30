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

int R, C, F;

string mmap[60];

void solveCase(int cnum) {
  int res = 0;
  string s = getLine();
  sscanf(s.c_str(), "%d%d%d", &R, &C, &F);
  
  C += 2; R++;
  
  FOR(y,0,R-1) mmap[y] = '#' + getLine() + '#';
  mmap[R-1] = ""; FOR(x,0,C) mmap[R-1] += '#';
  
  #define INF 1000000
  
  int crow[64][64], nrow[64][64], quick[64][64];
  FOR(a,0,64) FOR(b,0,64) crow[a][b] = quick[a][b] = INF;
  crow[1][1] = 0;
  
  int best = INF;
  
  FOR(y,0,R) {
    FOR(a,0,C) FOR(b,0,C) nrow[a][b] = INF;
    
    FOR(a,0,C) FOR(b,0,C) {
      if(a > b) continue;
      
      int at = crow[a][b];
      if(a==b && quick[y][a] < crow[a][b]) at = quick[y][a];
      
      // if(cnum ==4 && at != INF) printf("%d %d %d: %d\n", y, a,b, at);

      if(y >= R-2 && at < best) {
        best=at;
        continue;
        }
      
      int lft = a, rgt = b;

      for(int x=lft+1; x<rgt; x++) if(mmap[y][x] == '.') 
        goto nextab; // nonsense
      
      while(mmap[y][lft-1] == '.' && mmap[y+1][lft-1] == '#' && mmap[y+1][lft] == '#') lft--;
      while(mmap[y][rgt+1] == '.' && mmap[y+1][rgt+1] == '#' && mmap[y+1][rgt] == '#') rgt++;
      
      // one step to fall
      
      if(mmap[y][lft-1] == '.') lft--;
      if(mmap[y][rgt+1] == '.') rgt++;

      // printf("l/r = %d %d\n", lft, rgt);
      
      if(lft == rgt) continue; // no digging
            
      // try quick falls after 0-1 dig
      
      for(int x=lft; x<=rgt; x++) {
        if(mmap[y+1][x] == '#' && !(
          (mmap[y+1][x+1] == '#' && x+1 <= rgt) ||
          (mmap[y+1][x-1] == '#' && x-1 >= lft)
          )) continue;
        int cy = y+1;
        while(mmap[cy+1][x] == '.') cy++;
        if(cy-y > F) continue;
        quick[cy][x] <?= at+(mmap[y+1][x] == '#' ? 1 : 0);
        }
        
      // try wide cuts
      
      for(int a1=lft; a1<=rgt; a1++)
      for(int a2=a1; a2<=rgt; a2++) {
        if(FORALL(x,a1,a2+1, mmap[y+1][x] == '#') &&
           (
             (mmap[y+2][a1] == '#' && mmap[y+1][a1-1] == '#' && a1-1 >= lft) ||
             (mmap[y+2][a2] == '#' && mmap[y+1][a2+1] == '#' && a2+1 <= rgt)
             ))
        nrow[a1][a2] <?= at + (a2-a1+1);
        }

      nextab: ;        
      }
    FOR(a,0,64) FOR(b,0,64) crow[a][b] = nrow[a][b];
    }
  
  // FOR(y,0,R) printf("%s\n", mmap[y].c_str());
  //  printf("F=%d\n", F);
  
  if(best == INF)
    printf("Case #%d: No\n", cnum+1);
  else
    printf("Case #%d: Yes %d\n", cnum+1, best);
  }

int main() {
  int N;
  string Nstr = getLine();
  N = atoi(Nstr.c_str());
  FOR(cnum,0,N) 
    solveCase(cnum);
  return 0;
  }
