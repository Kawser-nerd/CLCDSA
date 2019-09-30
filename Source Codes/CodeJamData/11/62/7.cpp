// NAGLOWEK

#include <algorithm>
#include <cstdio>
#include <list>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <string>
#include <cstring>
#include <functional>

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

#define pb push_back
#define MP make_pair
#define st first
#define nd second


typedef LL intT;

intT GCD(intT a, intT b) {
	intT tmp;
	while(b!=0) {
		tmp = b;
		b = a%b;
		a = tmp;
	}
	return a;
}

/* gcd = ax - by, x>=0, y>=0 */
intT eGCD(intT a, intT b, intT &x, intT &y) {
    if (b==0) {
        x = intT(1);
        y = intT(0);
        return a;
    }   
    intT d = eGCD(b,a%b,y,x);
    y = a-x*(a/b)-y;
    x = b-x;
    return d;
}

intT inverse(intT a, intT p) { intT x,y; eGCD(a%p+p,p,x,y); return x % p; }

LL gcd(LL a, LL b){
  return b?gcd(b,a%b):a;
}

void scase(int CID){
  int H,W;
  LL M;
  scanf("%d%d%lld",&H,&W,&M);
  LL mapa[H+2][W+2];
  LL water[H+2][W+2];
  REP(i,H+2)REP(j,W+2)mapa[i][j] = 0;
  FOR(i,1,H+1)FOR(j,1,W+1)scanf("%lld",&mapa[i][j]);
  LL days = 0;
  for(;;++days){
    bool flag = 0;
    REP(i,H+2)REP(j,W+2)if(mapa[i][j])flag = true;
    if(!flag)break;

    REP(i,H+2)REP(j,W+2)water[i][j] = mapa[i][j];
    priority_queue<pair<LL,PII> > Q;
    bool visited[H+2][W+2];
    REP(i,H+2)REP(j,W+2)visited[i][j] = false;    
    REP(i,H+2){
      Q.push(MP(-0,PII(i,0)));
      Q.push(MP(-0,PII(i,W+1)));      
      visited[i][0] = visited[i][W+1] = true;
    }
    FOR(j,1,W+1){
      Q.push(MP(-0,PII(0,j)));
      Q.push(MP(-0,PII(H+1,j)));
      visited[0][j] = visited[H+1][j] = true;
    }
    
    while(!Q.empty()){
      int X = Q.top().second.first;
      int Y = Q.top().second.second;
      Q.pop();
      for(int a = -1; a<=1; ++a)
        for(int b = -1; b<=1; ++b){
          int Y1 = Y + b;
          int X1 = X + a;
          if(abs(a+b) != 1 || X1<0 || Y1<0 || X1>H+1 || Y1>W+1)continue;
          if(visited[X1][Y1])continue;
          visited[X1][Y1] = true;
          water[X1][Y1] = max(water[X1][Y1], water[X][Y]);
          Q.push(MP(-water[X1][Y1],PII(X1,Y1)));
        }
    }

    FOR(X,1,H+1)FOR(Y,1,W+1){
      LL maxi = 0;
      for(int a = -1; a<=1; ++a)
        for(int b = -1; b<=1; ++b){
          int Y1 = Y + b;
          int X1 = X + a;
          if(abs(a+b) != 1 || X1<0 || Y1<0 || X1>H+1 || Y1>W+1)continue;
          maxi = max(maxi, water[X][Y] - water[X1][Y1]);
        }    
      mapa[X][Y] -= min(maxi,M);
    }


  }
  printf("Case #%d: %lld\n",CID,days);
}

int main(){
  int z;
  scanf("%d",&z);
  REP(i,z)scase(i+1);
}

