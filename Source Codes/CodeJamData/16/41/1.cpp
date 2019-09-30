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

int N,P,R,S;

string choic[20][3];

void prep() {
  choic[0][0] = "P";
  choic[0][1] = "R";
  choic[0][2] = "S";
  FOR(i,1,13) FOR(j,0,3) {
    int k = (j+1)%3;
    if(choic[i-1][k] < choic[i-1][j]) 
      choic[i][j] = choic[i-1][k] + choic[i-1][j];
    else
      choic[i][j] = choic[i-1][j] + choic[i-1][k];
    }
  }

vector<string> answers;

void solveCase() {
  int res = 0;

  N = getNum();
  R = getNum(), P = getNum(), S = getNum();
  
  answers.clear();

/*int q = 1;
  FOR(t,0,1<<N) q *= 3;
  
  FOR(i,0,q) {
    string ans = "";
    int ii = i;
    FOR(j,0,1<<N) { ans += "PRS" [ii%3]; ii /= 3; }
    
    int cP=P, cR=R, cS=S;
    for(char c: ans) 
      if(c=='P') cP--;
      else if(c=='R') cR--;
      else if(c=='S') cS--;
    
    if(cP||cR||cS) continue;
    
    string cans = ans;
    
    while(Size(ans) > 1) {
      char c0 = ans[0];
      char c1 = ans[1];
      char cr;
      if(c0 == c1) goto again;
      if(c0 == 'P' && c1 == 'R') cr = 'P';
      if(c0 == 'R' && c1 == 'P') cr = 'P';
      if(c0 == 'P' && c1 == 'S') cr = 'S';
      if(c0 == 'S' && c1 == 'P') cr = 'S';
      if(c0 == 'S' && c1 == 'R') cr = 'R';
      if(c0 == 'R' && c1 == 'S') cr = 'R';
      ans = ans.substr(2) + cr;
      }
    
    answers.push_back(cans);

    again: ;
    }
    
    */
    
  for(int cc=0; cc<3; cc++) {
    int cP=P, cR=R, cS=S;
    string ans = choic[N][cc];
    for(char c: ans) 
      if(c=='P') cP--;
      else if(c=='R') cR--;
      else if(c=='S') cS--;
    
    if(cP||cR||cS) ;
    else answers.push_back(ans);
    }

  sort(answers.begin(), answers.end());
  if(Size(answers) == 0) answers.push_back("IMPOSSIBLE");
  
  printf("Case #%d: %s\n", cnum, answers[0].c_str());
  }

#define P 1000000007

int main() {

  prep();

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
