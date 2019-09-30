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
  int N,K;
  cin>>N>>K;
  int x[N],y[N];
  REP(i,N)cin>>x[i]>>y[i];
  map<pair<int,int>,int> rec;
  REP(i,N)REP(j,N){
    int temp=0;
    REP(k,N){
      if(x[k]<=x[i] and y[k]<=y[j])temp++;
    }
    rec[make_pair(x[i],y[j])]=temp;
  }
  sort(x,x+N);
  sort(y,y+N);
  lint ans=9e18;
  REP(i,N)REP(ii,i)REP(j,N)REP(jj,j){
    int num=rec[make_pair(x[i],y[j])];
    if(ii==0 and jj==0)num=num;
    else if(ii==0)num-=rec[make_pair(x[i],y[jj-1])];
    else if(jj==0)num-=rec[make_pair(x[ii-1],y[j])];
    else num-=rec[make_pair(x[ii-1],y[j])]+rec[make_pair(x[i],y[jj-1])]-rec[make_pair(x[ii-1],y[jj-1])];
    if(num==K)ans=min(ans,lint(x[i]-x[ii])*(lint)(y[j]-y[jj]));
  }
  cout<<ans<<endl;
  return 0;
}