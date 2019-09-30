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
  int N,Ma,Mb;
  cin>>N>>Ma>>Mb;
  int a[N],b[N],c[N];
  int sumA=1;
  int sumB=1;
  REP(i,N){
    cin>>a[i]>>b[i]>>c[i];
    sumA+=a[i];sumB+=b[i];
  }
  int dp[sumA][sumB];
  REP(ia,sumA)REP(ib,sumB)dp[ia][ib]=9999;
  dp[0][0]=0;
  REP(i,N){
    for(int ia=sumA-1;ia>=a[i];ia--)for(int ib=sumB;ib>=b[i];ib--){
      dp[ia][ib]=min(dp[ia][ib],dp[ia-a[i]][ib-b[i]]+c[i]);
    }
  }
  int ans=9999;
  FOR(ia,1,sumA)FOR(ib,1,sumB){
    if(ia*Mb==ib*Ma)ans=min(ans,dp[ia][ib]);
  }
  // REP(ia,sumA){
  //   REP(ib,sumB)cerr<<dp[ia][ib]<<" ";
  //   cerr<<endl;
  // }
  if(ans==9999)ans=-1;
  cout<<ans<<endl;

  return 0;
}