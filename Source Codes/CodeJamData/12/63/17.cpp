/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<(b);i++)

using namespace std;

#define MAXN 111
int X[MAXN], Y[MAXN];
char C[MAXN];
bool CC[MAXN];
int N;
#define M 500

int main(int argc, char *argv[]){
  int T; 
  scanf("%d",&T);
  REP(t,T){
    scanf("%d",&N);
    REP(i,N) scanf("%d%d %c",X+i,Y+i,C+i);
    REP(i,N) CC[i] = (C[i] == '#');
    int ansx = 1000, ansy = 1000;
    for(int x = M; x >= -M; x--){
      for(int y = M; y >= -M; y--){
        bool ok = true;
        REP(i,N){
          int dist = max(abs(x - X[i]), abs(y - Y[i]));
          if(dist % 2 != CC[i]){ ok = false; break; }
        }
        if(ok && abs(x) + abs(y) < abs(ansx) + abs(ansy)){ ansx = x; ansy = y; }
      }
    }
    printf("Case #%d: ",t+1);
    if(ansx == 1000) printf("Too damaged\n");
    else printf("%d %d\n",ansx,ansy);
  }
  return 0;
}
