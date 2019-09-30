#define BUFSIZE 1000000
char buf[BUFSIZE];
int Tests, cnum;
// #define USEWIN
#define MANYTESTS 1
// #define LINEBYLINE

// Eryx's new template for I/O contests, May 3, 2015

#include <algorithm>
#include <stdio.h>
using namespace std;

#define LS <
#define Size(x) (int(x.size()))

// All macros with parameters "k,a,b" run the "k" variable in range [a,b)
#define FOR(k,a,b) for(__typeof(a) k=(a); k LS (b); ++k)

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

int scanerr;

int getNum() {
#ifdef LINEBYLINE
  string s = getLine();
  return atoi(s.c_str());
#else
  int i;
  scanerr = scanf("%d", &i);
  return i;
#endif
  }

#line 10 "work.cpp"

/// ----


//Eryx

// !FDI

int lover[500];
int qc, X, Y;

int nekst[1000], prew[1000];

char maze[200][200];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void findc(int a, int &cx, int &cy, int &cd) {
      if(a < X) cx = a, cy = 0, cd = 0;
      else if(a < X+Y) cx = X-1, cy = a-X, cd = 1;
      else if(a < X+Y+X) cx = X-1-(a-X-Y), cy=Y-1, cd = 2;
      else cx = 0, cy = Y-1-(a-X-Y-X), cd = 3;
  }

bool mazefail() {
  int loveleft = qc/2;
  while(true) {
    loveleft--;
    if(!loveleft) break;
    FOR(a,0,qc) if(lover[a] == nekst[a]) {
      int cx, cy, cd;
      findc(a,cx,cy,cd);
      
      // printf("a=%d b=%d\n", a, lover[a]);
      
      while(cx >= 0 && cy >= 0 && cx < X && cy < Y) {
        if(!maze[cy][cx]) maze[cy][cx] = "\\/\\/" [cd];
        // printf("at %d,%d,%d: %c\n", cx,cy,cd, maze[cy][cx]);
        int nekstdir;
        if(maze[cy][cx] == '/') nekstdir = (3-cd) ^ 2;
        if(maze[cy][cx] == '\\') nekstdir = (3-cd);
//      printf("nekst = %d\n", nekstdir);
        cd = nekstdir;
        cx += dx[cd]; cy += dy[cd];
        }

      cx -= dx[cd]; cy -= dy[cd]; cd ^= 2;
//    printf("end: %d,%d,%d\n", cx,cy,cd);
      int cx2, cy2, cd2;
      findc(lover[a], cx2, cy2, cd2);
      if(cx != cx2 || cy != cy2 || cd != cd2) { /*printf("not reached\n");*/ return true; }
      lover[nekst[a]] = -1;
      nekst[prew[a]] = nekst[nekst[a]];
      prew[nekst[nekst[a]]] = prew[a];
      lover[a] = -1; 
      goto nekstlover;
      }
    
    return true;
    nekstlover: ;
    }
  
  FOR(y,0,Y) FOR(x,0,X) if(!maze[y][x]) maze[y][x] = "\\/"[(y+x)&1];
  return false;
  }

void solveCase() {
  int res = 0;

  Y = getNum(), X = getNum();
  FOR(u,0,X+Y) {
    int a = getNum(), b = getNum();
    a--; b--;
    lover[a] = b; lover[b] = a;
    }
  
  qc = 2*(X+Y);
  FOR(u,0,qc) nekst[u] = (u+1) % qc;
  FOR(u,0,qc) prew[u] = (u+qc-1) % qc;
  
  FOR(y,0,200) FOR(x,0,200) maze[y][x] = 0;
  
  bool b = mazefail();
  
  printf("Case #%d:\n", cnum);
  
  if(b) { printf("IMPOSSIBLE\n"); return; }
  FOR(y,0,Y) printf("%s\n", maze[y]);
  }

#define P 1000000007

int main() {

  if(!MANYTESTS) Tests = 1;
  else Tests = getNum();
  
  for(cnum=1; cnum<=Tests; cnum++)
    solveCase();
    
  // finish
  return 0;
  }

// This solution includes hidden routines to solve test cases in separate
// processes in order to make it faster. I will update them to run on a
// cluster if I get one ;)
