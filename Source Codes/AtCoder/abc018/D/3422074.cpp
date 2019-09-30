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
  int N,M,P,Q,R;
  cin>>N>>M>>P>>Q>>R;
  int c[N][M];
  REP(i,N)REP(j,M)c[i][j]=0;
  REP(i,R){
    int x,y,z;
    cin>>x>>y>>z;
    c[x-1][y-1]+=z;
  }
  int ans=0;
  REP(i,1<<N){
    int a[M];
    int p=0;
    REP(m,M)a[m]=0;
    REP(n,N){
      if((i>>n)&1){
        p++;
        REP(m,M){
          a[m]+=c[n][m];
        }
      }
    }
    if(p!=P)continue;
    sort(a,a+M,greater<int>());
    int temp=0;
    REP(j,Q)temp+=a[j];
    ans=max(temp,ans);
  }
  cout<<ans<<endl;
  return 0;
}