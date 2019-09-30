#define BUFSIZE 1000000
char buf[BUFSIZE];
int Tests, cnum;
// #define USEWIN
#define MANYTESTS 1
// #define LINEBYLINE

// Eryx's new template for I/O contests, May 3, 2015

#include <algorithm>
#include <string>
#include <vector>
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
    if(c <= 0) continue;
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

string getStr() {
#ifdef LINEBYLINE
  return getStr();
#else
  scanerr = scanf("%s", buf);
  return buf;
#endif
  }

#line 10 "work.cpp"

/// ----


//Eryx

// !FDI

void solveCase() {
  int res = 0;

  int Y = getNum(), X = getNum();
  
  vector<string> mapp;
  FOR(y,0,Y) mapp.push_back(getStr());
  
  int lasty = 0;
  
  FOR(y,0,Y) {
    int lastx = 0;
    char lastch = 0;
    FOR(x,0,X) {
      if(mapp[y][x] != '?') {
        FOR(xx,lastx,x+1) FOR(yy, lasty, y+1)
          mapp[yy][xx] = mapp[y][x];
        lastx = x+1; lastch = mapp[y][x];
        }
      }
    
    if(lastch) {
      FOR(yy, lasty, y+1) FOR(xx, lastx, X) mapp[yy][xx] = lastch;
      lasty = y+1;
      }
    }
  
  FOR(y, lasty, Y) FOR(x,0,X) mapp[y][x] = mapp[y-1][x];
  
  printf("Case #%d:\n", cnum);
  FOR(y,0,Y) printf("%s\n", mapp[y].c_str());
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
