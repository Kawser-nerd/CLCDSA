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
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

int64 tx[100000],ty[100000];
int64 calc(int64 n){
//FOR(i,n)cout<<tx[i]<<" "<<ty[i]<<endl;
  int64 cnt[3][3]={};
  FOR(i,n)cnt[tx[i]%3][ty[i]%3]++;
  int64 ans=0;
  typedef pair<int64,int64> p2;
  FOR(x0,3)FOR(y0,3)
  FOR(x1,3)FOR(y1,3)
  FOR(x2,3)FOR(y2,3)if((x0+x1+x2)%3==0&&(y1+y2+y0)%3==0&&p2(x0,y0)<=p2(x1,y1)&&p2(x1,y1)<=p2(x2,y2)){
    vector<p2> t;
    t.push_back(p2(x0*3+y0,cnt[x0][y0]));
    t.push_back(p2(x1*3+y1,cnt[x1][y1]));
    t.push_back(p2(x2*3+y2,cnt[x2][y2]));
    sort(t.begin(),t.end());
    int64 i=0;
    int64 c=1;
    while(i<t.size()){
      int64 s=0;
      while(i+s<t.size()&&t[i].first==t[i+s].first)s++;
      if(s==1)c*=t[i].second;
      else if(s==2)c*=t[i].second*(t[i].second-1)/2;
      else c*=t[i].second*(t[i].second-1)*(t[i].second-2)/6;
//      cout<<c<<" ";
      i+=s;      
    }
//    cout<<c<<endl;
    ans+=c;
  }
  return ans;
}
main(){
  int N;
  cin>>N;
  for(int c=1;c<=N;c++){
    int64 n,A,B,C,D,x0,y0,M,x,y;
    cin>>n>>A>>B>>C>>D>>x0>>y0>>M;
    x=x0;y=y0;
    FOR(i,n){
      tx[i]=x;ty[i]=y;
      x=(A*x+B)%M;
      y=(C*y+D)%M;
    }
    cout<<"Case #"<<c<<": "<<calc(n)<<endl;
  }
}
