#include <algorithm>
#include <string>
#include <vector>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

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

#define MAXM 16384

int S, M;
int gr[MAXM], x[MAXM], y[MAXM];
int vers[MAXM];
int conn[MAXM];
int edges[MAXM];
int faces[MAXM];

int board[8000][8000];

int ufind(int a) {
  int b = a;
  while(gr[b] != b) b = gr[b];
  while(a != b) {int c = gr[a]; gr[a] = b; a = c; }
  return a;
  }

void funion(int a, int b) {
  if(a == -1 || b == -1) return;
  //printf("union %d -> %d\n", a, b);
  a = ufind(a);
  b = ufind(b);
  gr[a] = b;
  if(a != b) conn[b] |= conn[a], edges[b] += edges[a], faces[b] += faces[a], vers[b] += vers[a];
  edges[b]++;
  }

bool inboard(int x, int y) {
  if(x <= 0 || y <= 0) return false;
  if(x >= 2*S || y >= 2*S) return false;
  if(x-y >= S || y-x >= S) return false;
  return true;
  }

void funionb(int x0, int y0, int x1, int y1) {
  if(!inboard(x0,y0)) return;
  if(!inboard(x1,y1)) return;
  funion(board[y0][x0], board[y1][x1]);
  }  

void addface(int x0, int y0, int x1, int y1, int x2, int y2) {
  if(!inboard(x0,y0)) return;
  if(!inboard(x1,y1)) return;
  if(!inboard(x2,y2)) return;
  if(board[y0][x0] >= 0 && board[y1][x1] >= 0 && board[y2][x2] >= 0)
    faces[ufind(board[y0][x0])]++;
  }

void solveCase() {
  int res = 0;
  // proceed
  
  err = scanf("%d%d", &S, &M);
  FOR(z,0,M) err=scanf("%d%d", &x[z], &y[z]);
  
  string ans;
  
  int mid = -1;
  
  FOR(u,0,M) {
    gr[u] = u;
    faces[u] = edges[u] = conn[u] = 0;
    vers[u] = 1;
    int yy = y[u], xx = x[u];
    board[yy][xx] = u;
    if(xx == 1 && yy == 1) conn[u] |= 1;
    else if(xx == 1 && yy == S) conn[u] |= 2;
    else if(xx == S && yy == 2*S-1) conn[u] |= 4;
    else if(xx == 2*S-1 && yy == 2*S-1) conn[u] |= 8;
    else if(xx == 2*S-1 && yy == S) conn[u] |= 16;
    else if(xx == S && yy == 1) conn[u] |= 32;
    else if(xx == 1) conn[u] |= 64;
    else if(yy == 1) conn[u] |= 128;
    else if(xx == 2*S-1) conn[u] |= 256;
    else if(yy == 2*S-1) conn[u] |= 512;
    else if(xx-yy == S-1) conn[u] |= 1024;
    else if(yy-xx == S-1) conn[u] |= 2048;
    
    funionb(xx,yy,xx-1,yy);
    funionb(xx,yy,xx+1,yy);
    funionb(xx,yy,xx,yy-1);
    funionb(xx,yy,xx,yy+1);
    funionb(xx,yy,xx-1,yy-1);
    funionb(xx,yy,xx+1,yy+1);
    
    addface(xx,yy,xx+1,yy,xx+1,yy+1);
    addface(xx,yy,xx,yy+1,xx+1,yy+1);
    addface(xx,yy,xx,yy+1,xx-1,yy);
    addface(xx,yy,xx-1,yy,xx-1,yy-1);
    addface(xx,yy,xx,yy-1,xx-1,yy-1);
    addface(xx,yy,xx,yy-1,xx+1,yy);
    
    int uuu = ufind(board[yy][xx]);
    
    bool bridge = bitc(conn[uuu] & 63) >= 2;
    bool fork = bitc(conn[uuu] & (64|128|256|512|1024|2048)) >= 3;
    bool ring = vers[uuu] + faces[uuu] <= edges[uuu];
    
    //printf("%4d. (%4x,%4x) G%4d C%03x V%d E%d F%d\n", u, xx, yy, uuu, conn[uuu], vers[uuu], faces[uuu], edges[uuu]);
    
    if(bridge || fork || ring) {
      if(bridge) ans +="-bridge";
      if(fork) ans +="-fork";
      if(ring) ans +="-ring";
      mid = u+1;
      break;
      }
    }

  FOR(u,0,M) board[y[u]][x[u]] = -1;
  
  if(mid >= 1) 
    printf("Case #%d: %s in move %d\n", cnum+1, ans.c_str()+1, mid);
  else
    printf("Case #%d: none\n", cnum+1);

  }

int main() {
  FOR(a,0,8000) FOR(b,0,8000) board[a][b] = -1;
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
