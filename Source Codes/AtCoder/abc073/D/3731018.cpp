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

int N,M,R;
int inf=1e8;
int r[10];
int d[200][200];
int ans;
bool v[10];
vector<int> route;

void dfs(int depth){
  if(depth>=R){
    int temp=0;
    FOR(i,1,R){
      temp+=d[r[route[i]]][r[route[i-1]]];
    }
    // cerr<<temp<<endl;
    ans=min(ans,temp);
    // for(auto i:route)cerr<<i<<" ";
    // cerr<<endl;
  }else{
    REP(i,R){
      if(v[i])continue;
      route.push_back(i);
      v[i]=true;
      dfs(depth+1);
      route.pop_back();
      v[i]=false;
    }
  }
}


int main(){
  cin>>N>>M>>R;
  REP(i,R){
    cin>>r[i];
    r[i]--;
  }
  REP(i,N)REP(j,N)d[i][j]=(i==j?0:inf);
  REP(i,M){
    int a,b,t;
    cin>>a>>b>>t;
    a--;b--;
    d[a][b]=t;d[b][a]=t;
  }
  REP(k,N)REP(i,N)REP(j,N)d[i][j]=min(d[i][j],d[i][k]+d[k][j]);


  ans=inf;
  REP(i,R)v[i]=false;
  dfs(0);
  cout<<ans<<endl;

  return 0;
}