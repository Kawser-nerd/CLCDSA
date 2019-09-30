#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;

int main(){
  int N,M;
  int inf=1e7;
  cin>>N>>M;
  int d[N][N],a[M],b[M],c[M];
  REP(i,N)REP(j,N)d[i][j]=(i==j?0:inf);
  REP(i,M){
    cin>>a[i]>>b[i]>>c[i];
    a[i]--;b[i]--;
    d[a[i]][b[i]]=c[i];d[b[i]][a[i]]=c[i];
  }
  REP(k,N)REP(i,N)REP(j,N)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
  int ans=M;
  REP(m,M){
    REP(i,N)REP(j,N){
      if(d[i][j]==d[i][a[m]]+c[m]+d[b[m]][j]){
        ans--;
        i=N-1;
        j=N-1;
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}