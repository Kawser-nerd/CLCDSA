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

const int N = 210;
int val[N][N];
VI kraw[N];
int skojx[N],skojy[N],vis[N];
int k;

int dfs(int x){
  vis[x] = 1;
  FOREACH(it,kraw[x]) if (skojy[*it] == -1 || !vis[skojy[*it]] && dfs(skojy[*it])){
    skojx[x] = *it;
    skojy[*it] = x;
    return 1;
  }
  return 0;
}

int mniejszy(int a,int b){
  REP(i,k) if (val[a][i] >= val[b][i]) return 0;
  return 1;
}

int main(){
  int testy;
  scanf("%d",&testy);
  REP(numer,testy){
    printf("Case #%d: ", numer+1);
    int n;
    scanf("%d %d",&n,&k);
    REP(i,n) REP(j,k) scanf("%d",val[i]+j);
    REP(i,n) kraw[i].clear();
    REP(i,n) REP(j,n) if (mniejszy(i,j)) kraw[i].PB(j);

    REP(i,n) skojx[i] = skojy[i] = -1;
    int change = 1;
    int res = n;
    while (change) {
      change = 0;
      REP(i,n) vis[i]=0;
      REP(i,n) if (skojx[i]==-1 && vis[i]==0 && dfs(i)){
        res--;
        change = 1;
      }
    }
    printf("%d\n",res);
  }
  return 0;
}
