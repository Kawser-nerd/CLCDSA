#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <cctype>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>
#include <cmath>
#include <cstring>
using namespace std;

typedef vector <int > VI;
typedef vector < VI > VVI;
typedef long long LL;
typedef vector < LL > VLL;
typedef vector < double > VD;
typedef vector < string > VS;
typedef pair<int,int> PII;
typedef vector <PII> VPII;
typedef istringstream ISS;

#define ALL(x) x.begin(),x.end()
#define REP(i,n) for (int i=0; i<(n); ++i)
#define FOR(var,pocz,koniec) for (int var=(pocz); var<=(koniec); ++var)
#define FORD(var,pocz,koniec) for (int var=(pocz); var>=(koniec); --var)
#define FOREACH(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); ++it)
#define PB push_back
#define PF push_front
#define MP(a,b) make_pair(a,b)
#define ST first
#define ND second
#define SIZE(x) (int)x.size()

map<vector<string>,int> mapa;
vector<vector<string> > kolejka;
int n,m;

int koncowy(const vector<string> &stan){
  REP(i,n) REP(j,m){
    if (stan[i][j] == 'o') return 0;
  }
  return 1;
}

int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int vis[100][100];

#define JEST_BOX(x,y,z) (x[y][z] == 'o' || x[y][z] == 'w')

inline int between(int a,int b,int c){
  return a >= b && a <= c;
}

void dfs(int i,int j,const vector<string> &stan){
  vis[i][j] = 1;
  REP(ruch,4){
    int ni = i+dx[ruch];
    int nj = j+dy[ruch];
    if (between(ni,0,n-1) && between(nj,0,m-1) && JEST_BOX(stan,ni,nj) && !vis[ni][nj]){
      dfs(ni,nj,stan);
    }
  }
}

int czy_grozny(const vector<string> &stan){
  REP(i,n) REP(j,m) vis[i][j] = 0;
  int byl = 0;
  REP(i,n) REP(j,m) if (JEST_BOX(stan,i,j) && !vis[i][j]){
    if (byl) return 1;
    byl = 1;
    dfs(i,j,stan);
  }
  return 0;
}

void ruszaj(const vector<string> &stan,int dist){
  int grozny = czy_grozny(stan);
  REP(i,n) REP(j,m) if (JEST_BOX(stan,i,j)){
    REP(ruch,4){
      int ni = i-dx[ruch];
      int nj = j-dy[ruch];
      if (between(ni,0,n-1) && between(nj,0,m-1) && (stan[ni][nj] == '.' || stan[ni][nj] == 'x')){
        ni = i+dx[ruch];
        nj = j+dy[ruch];
        if (between(ni,0,n-1) && between(nj,0,m-1) && (stan[ni][nj] == '.' || stan[ni][nj] == 'x')){
          vector<string> nstan = stan;
          if (stan[i][j] == 'o') nstan[i][j] = '.';
          else nstan[i][j] = 'x';
          
          if (stan[ni][nj] == '.') nstan[ni][nj] = 'o';
          else nstan[ni][nj] = 'w';

          if (!grozny || !czy_grozny(nstan)){
            if (mapa.count(nstan) == 0){
              mapa[nstan] = dist+1;
              kolejka.PB(nstan);
            }
          }
        }
      }
    }
  }
}

int main(){
  int testy;
  scanf("%d",&testy);
  REP(numer,testy){
    printf("Case #%d: ", numer+1);
    scanf("%d %d",&n,&m);
    vector<string> stan;
    char txt[100];
    REP(i,n){
      scanf("%s",txt);
      stan.PB(txt);
    }
    mapa.clear();
    kolejka.clear();
    mapa[stan] = 0;
    kolejka.PB(stan);

    int res = -1;
    REP(foo,SIZE(kolejka)){
      stan = kolejka[foo];
      int dist = mapa[stan];
      if (koncowy(stan)){
        res = dist;
        break;
      }
//      printf("stan dist=%d grozny=%d\n",dist,czy_grozny(stan));
 //     REP(i,n) printf("%s\n",stan[i].c_str());
      ruszaj(stan,dist);
    }
    printf("%d\n",res);
  }
  return 0;
}
