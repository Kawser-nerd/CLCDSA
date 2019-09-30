#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <cmath>
#include <cstring>
#include <string>
#include <iostream>
#include <complex>
#include <sstream>
#include <climits>
#include <cassert>
using namespace std;
 
typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
 
#define REP(i,n) for(int i=0;i<(n);++i)
#define SIZE(c) ((int)((c).size()))
#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FOREACH(i,x) for (__typeof((x).begin()) i=(x).begin(); i!=(x).end(); ++i)
#define FORD(i,a,b) for (int i=(a)-1; i>=(b); --i)
#define ALL(v) (v).begin(), (v).end()
 
#define pb push_back
#define mp make_pair
#define st first
#define nd second

int R,C;
char mapa[100][100];
bool visited[100][100];
int pasek[100][100];

struct Pasek {
  int r, c1, c2;
  int id;
  Pasek(int _id, int _r, int _c1, int _c2):id(_id),r(_r),c1(_c1),c2(_c2){}
  Pasek(){}
};

int getRight(Pasek p, int k) {
  int x = p.r;
  int y = max(p.c1, p.c2 - k);
  
  if (mapa[x+1][y] == '#') return pasek[x][y];  
  return visited[x+1][y] ? pasek[x+1][y] : -1;
}

int getLeft(Pasek p, int k) {
  int x = p.r;
  int y = min(p.c2, p.c1 + k);
  
  if (mapa[x+1][y] == '#') return pasek[x][y];  
  return visited[x+1][y] ? pasek[x+1][y] : -1;  
}

int NC;
bool check(int r, int c) {
  REP(i,R)REP(j,C) visited[i][j] = false;  
  visited[r][c] = true;
  queue<PII> Q;
  Q.push(PII(r,c));
  NC = 0;
  while(!Q.empty()) {
    ++NC;
    PII p = Q.front();
    Q.pop();
    int x = p.first, y = p.second;
    if (mapa[x-1][y] != '#' && !visited[x-1][y]) {
      visited[x-1][y] = true;
      Q.push(PII(x-1,y));
    }
    if (mapa[x][y-1] != '#' && !visited[x][y-1]) {
      visited[x][y-1] = true;
      Q.push(PII(x,y-1));
    }    
    if (mapa[x][y+1] != '#' && !visited[x][y+1]) {
      visited[x][y+1] = true;
      Q.push(PII(x,y+1));
    }        
  }
  
  vector<Pasek> paski;
  int pid = 0;
  REP(i,R) {
    int j = 0;
    while (j < C) {
      if (!visited[i][j]) {
        ++j;
        continue;
      }
      int j1 = j, j2 = j;
      while (visited[i][j2+1]) ++j2;
      for (int k = j1; k <= j2; ++k)
        pasek[i][k] = pid;
        
      paski.push_back(Pasek(pid, i, j1, j2));
      
      ++pid;
      j = j2 + 1;
    }  
  }
  bool active[pid];
  REP(i,pid) active[i] = true;

  
  int rounds = 0;
  while(true) {
    //if (rounds++ > 10000) break;
    bool okl1[100], okl2[100], okr1[100], okr2[100];
    REP(i,100) okl1[i] = okr1[i] = true;
    REP(i,100) okl2[i] = okr2[i] = false;    
    
    REP(i,paski.size()) {
      if (!active[i]) continue;
      REP(j,100) {
        int r = getRight(paski[i], j);
        if (r == -1) okr1[j] = false;
        else if (r != i) okr2[j] = true;     
      }

      REP(j,100) {
        int r = getLeft(paski[i], j);
        if (r == -1) okl1[j] = false;
        else if (r != i) okl2[j] = true;                
      }               
    }

    REP(j,100) {
      if (okl1[j] && okl2[j]) {
        bool active2[pid];
        REP(i,pid) active2[i] = active[i];
        REP(i,pid) active[i] = false;
        REP(i,pid) if (active2[i]) active[getLeft(paski[i], j)] = true;
        goto success;
      }    
    }

    REP(j,100) {
      if (okr1[j] && okr2[j]) {
        bool active2[pid];
        REP(i,pid) active2[i] = active[i];
        REP(i,pid) active[i] = false;
        REP(i,pid) if(active2[i]) active[getRight(paski[i], j)] = true;
        goto success;
      }    
    }
  
    break;
    success:;  
  }
  
  int cnt = 0;
  REP(i,pid) cnt += active[i];
  return cnt == 1;
}

void scase(int CASEID) {
  scanf("%d%d",&R,&C);
  REP(i,R) scanf("%s",mapa[i]);
  bool lucky[20];
  int nc[20];
  int caves = 0;
  REP(i,R)REP(j,C) {
    if (mapa[i][j] >= '0' && mapa[i][j] <= '9') {
      int cave = mapa[i][j] - '0';
      caves = max(caves, cave+1);
      lucky[cave] = check(i,j);
      nc[cave] = NC;
    }
  }
  printf("Case #%d:\n", CASEID);
  REP(i,caves) printf("%d: %d %s\n",i, nc[i], lucky[i] ? "Lucky" : "Unlucky");
}

int main() {
  int T;
  scanf("%d",&T);
  FOR(t,1,T+1)scase(t);
}
