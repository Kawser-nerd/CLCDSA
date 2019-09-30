#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<cstring>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

int n,a[50],b[50],d[1<<10][10];
typedef pair<int,int> p2;
vector<p2> q;
void add(int x,int y,int _d){
  if(d[x][y]<1000000)return;
  d[x][y]=_d;
  q.push_back(p2(x,y));
}
void solve(){
  scanf("%d",&n);
  for(int i=0;i<n-1;i++)scanf("%d %d",&a[i],&b[i]),--a[i],--b[i];
  memset(d,60,sizeof(d));
  q.clear();
  add(1,0,0);
  FOR(i,q.size()){
    int x=q[i].first,y=q[i].second;
    if(y==n-1){
      cout<<d[x][y]<<endl;
      return;
    }
    int y2=x&1<<y?a[y]:b[y],x2=x^1<<y2;
    add(x2,y2,d[x][y]+1);
  }
  cout<<"Infinity"<<endl;
}

main(){
  int C;cin>>C;
  for(int c=1;c<=C;c++){
    cout<<"Case #"<<c<<": ";
    solve();
    cout<<flush;
  }
}
