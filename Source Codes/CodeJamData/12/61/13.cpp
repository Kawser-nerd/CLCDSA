#include<cstdio>
#include<algorithm>
#include<cassert>
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

int n;
struct ghost {
  int x,y,m,d[1001];
} t[110];
typedef pair<int,int> p2;
bool cmp(const p2 &a,const p2 &b){return t[a.first].m+a.second<t[b.first].m+b.second;} 
#define INF 1000000000
void solve(){
  scanf("%d",&n);
  FOR(i,n){
    scanf("%d %d %d",&t[i].x,&t[i].y,&t[i].m);
//    t[i].m/=50;
  }
  assert(n<=100);
  vector<p2> s;
  FOR(i,n+1)FOR(j,1001)s.push_back(p2(i,j));
  t[n].x=0;
  t[n].y=0;
  t[n].m=-INF;
  FOR(i,n+1)FOR(j,1001)t[i].d[j]=-INF;
  t[n].d[0]=0;
  sort(s.begin(),s.end(),cmp);
  t[n].m=0;
  FOR(i,s.size()){
    int cur=s[i].first,delta=s[i].second;
    if(t[cur].d[delta]>-INF)for(int next=0;next<n;next++)if(next!=cur){
      int dist_x=abs(t[cur].x-t[next].x),dist_y=abs(t[cur].y-t[next].y);
      int move=t[cur].m+delta+(dist_x+dist_y-min(dist_x,dist_y))*100;
      int recharge=t[cur].m+delta+(cur!=n?750:0);
      int final=max(max(move,recharge),t[next].m);
      if(final>t[next].m+1000)continue;
      int delta2=final-t[next].m;
      t[next].d[delta2]=max(t[cur].d[delta]+1,t[next].d[delta2]);
    }
  }
  int ans=0;
  FOR(i,n+1)FOR(j,1001)ans=max(ans,t[i].d[j]);
  cout<<ans<<endl;
}

main(){
  int C;cin>>C;
  for(int c=1;c<=C;c++){
    cout<<"Case #"<<c<<": ";
    solve();
    cout<<flush;
  }
}
