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
  int N,M;
  cin>>N>>M;
  lint S[8][N];
  REP(i,N){
    lint x,y,z;
    cin>>x>>y>>z;
    S[0][i]=x+y+z;
    S[1][i]=x+y-z;
    S[2][i]=x-y+z;
    S[3][i]=x-y-z;
    S[4][i]=-x+y+z;
    S[5][i]=-x+y-z;
    S[6][i]=-x-y+z;
    S[7][i]=-x-y-z;
  }
  REP(i,8)sort(S[i],S[i]+N,greater<lint>());
  // REP(i,8){
  //   REP(j,N)cerr<<S[i][j]<<endl;
  //   cerr<<endl;
  // }
  lint ans=0;
  REP(i,8){
    lint temp=0;
    REP(j,M)temp+=S[i][j];
    ans=max(ans,temp);
  }
  cout<<ans<<endl;
  return 0;
}