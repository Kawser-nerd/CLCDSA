#include <iostream>
#include <math.h>
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
  int N,Q;
  cin>>N;
  int D[N][N];
  int sum[N][N];
  REP(i,N)REP(j,N)cin>>D[i][j];
  sum[0][0]=D[0][0];
  FOR(i,1,N)sum[i][0]=sum[i-1][0]+D[i][0];
  FOR(i,1,N)sum[0][i]=sum[0][i-1]+D[0][i];
  FOR(i,1,N)FOR(j,1,N)sum[i][j]=D[i][j]+sum[i][j-1]+sum[i-1][j]-sum[i-1][j-1];
  cin>>Q;
  int P[Q];
  REP(i,Q)cin>>P[i];

  REP(q,Q){
    int ans=0;
    REP(i,N)REP(j,N)FOR(k,i,N){
      int l=min(N-1,j-1+P[q]/(k-i+1));
      // cout<<(k-i+1)<<" "<<(l-j+1)<<endl;
      if((k-i+1)*(l-j+1)==0)continue;
      int temp;
      if(i==0 and j==0)temp=sum[k][l];
      else if(i==0)temp=sum[k][l]-sum[k][j-1];
      else if(j==0)temp=sum[k][l]-sum[i-1][l];
      else temp=sum[k][l]-sum[k][j-1]-sum[i-1][l]+sum[i-1][j-1];
      ans=max(ans,temp);
    }
    cout<<ans<<endl;
  }
  return 0;
}