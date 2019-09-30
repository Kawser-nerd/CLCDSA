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
  int N;
  cin>>N;
  vector<map<int,int> > e(N);
  REP(i,N-1){
    int a,b,c;
    cin>>a>>b>>c;
    a--;b--;
    e[a][b]=c;
    e[b][a]=c;
  }
  int Q,K;
  cin>>Q>>K;
  K--;
  lint v[N];
  REP(i,N)v[i]=-1;
  v[K]=0;
  queue<int> q;
  q.push(K);
  while(!q.empty()){
    for(auto i:e[q.front()]){
      if(v[i.first]>=0)continue;
      v[i.first]=v[q.front()]+i.second;
      q.push(i.first);
    }
    q.pop();
  }
  int x[Q],y[Q];
  REP(i,Q){
    cin>>x[i]>>y[i];
    x[i]--;y[i]--;
  }
  REP(i,Q)cout<<v[x[i]]+v[y[i]]<<endl;
  // REP(i,N)cerr<<v[i]<<endl;
  return 0;
}