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

lint pr=1000*1000*1000+7;
int main(){
  int N;
  cin>>N;
  vector<int> c[100000];
  REP(i,N-1){
    int a,b;
    cin>>a>>b;
    c[a-1].push_back(b-1);
    c[b-1].push_back(a-1);
  }
  queue<int> q;
  stack<int> s;
  bool v[N];
  REP(i,N)v[i]=false;
  v[0]=true;
  q.push(0);
  lint w[N],b[N];
  REP(i,N){
    w[i]=0;
    b[i]=0;
  }
  while(!q.empty()){
    int p=q.front();
    q.pop();
    if(p!=0 and c[p].size()==1){
      b[p]=1;
      w[p]=1;
      continue;
    }
    s.push(p);
    for(auto i:c[p]){
      if(v[i])continue;
      q.push(i);
      v[i]=true;
    }
  }
  while(!s.empty()){
    // cerr<<s.top()<<endl;
    int p=s.top();
    s.pop();
    b[p]=1;
    w[p]=1;
    for(auto i:c[p]){
      if(b[i]<1)continue;
      b[p]*=w[i];
      w[p]*=w[i]+b[i];
      b[p]%=pr;
      w[p]%=pr;
    }
  }
  cout<<((b[0]+w[0])%pr)<<endl;
  // REP(i,N)cerr<<b[i]<<" "<<w[i]<<endl;
  return 0;
}