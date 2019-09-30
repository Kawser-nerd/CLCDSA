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

int n,z[1100];
int64 x[1100],y[1100];
int64 ans_x,ans_y;
bool found=false;
inline bool f(int i,int64 cx,int64 cy){
  return max(abs(x[i]-cx),abs(y[i]-cy))%2==z[i];
}
inline void check(int64 cx,int64 cy){
  if(found&&abs(cx)+abs(cy)>abs(ans_x)+abs(ans_y))return;
  bool ok=true;
  FOR(i,n)if(!f(i,cx,cy))return;
  if(!found)ans_x=cx,ans_y=cy,found=true;
  else if(abs(cx)+abs(cy)<abs(ans_x)+abs(ans_y)||abs(cx)+abs(cy)==abs(ans_x)+abs(ans_y)&&(cx>ans_x||cx==ans_x&&cy>ans_y))ans_x=cx,ans_y=cy;
}
void solve(){
  scanf("%d",&n);
  FOR(i,n){
    char c;
    scanf("%lld %lld %c",&x[i],&y[i],&c);
    z[i]=c=='#';
  }
  found=false;
  FOR(i,n)for(int dx=-1;dx<=1;dx++)for(int dy=-1;dy<=1;dy++){
    check(x[i]+dx,y[i]+dy);
  }
  for(int cx=-10;cx<=10;cx++)for(int cy=-10;cy<=10;cy++)check(cx,cy);
  FOR(i,n)for(int cx=-10;cx<=10;cx++)for(int cy=-10;cy<=10;cy++)check(x[i]+cx,y[i]+cy);
  set<int> seen;
  FOR(i,n)for(int d=-4;d<=4;d++){
    if(seen.count(x[i]+y[i]+d))continue;
    seen.insert(x[i]+y[i]+d);
    FOR(i2,n)for(int d2=-4;d2<=4;d2++){
    int64 sum=x[i]+y[i]+d,diff=x[i2]-y[i2]+d2;
    if((sum+diff)%2==0)check((sum+diff)/2,sum-(sum+diff)/2);
//    check(x[i2]+dx2,sum-(x[i2]+dx2));
//    check(sum-(y[i2]+dy2),y[i2]+dy2);
//    check(x[i]+dx,x[i]+dx-diff);
//    check(diff+y[i]+dy,y[i]+dy);
    }
  }
  FOR(i,n)for(int dx=-10;dx<=10;dx++)for(int dy=-10;dy<=10;dy++)for(int cx=-10;cx<=10;cx++){
    int64 sum=x[i]+dx+y[i]+dy;
    check(cx,sum-cx);
    check(sum-cx,cx);
    int64 diff=x[i]+dx-y[i]-dy;
    check(cx,cx-diff);
    check(diff+cx,cx);
  }
  if(found)
  cout<<ans_x<<" "<<ans_y<<endl;
  else cout<<"Too damaged"<<endl;
}

main(){
  int C;cin>>C;
  for(int c=1;c<=C;c++){
    cout<<"Case #"<<c<<": ";
    solve();
    cout<<flush;
  }
}
