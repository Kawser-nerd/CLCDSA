#include<cstdio>
#include<algorithm>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
using namespace std;
int n,d;
typedef pair<int,int> p2;
p2 t[1100000];
bool ok(double x){
  double prev=-1e20;
  for(int i=0;i<n;i++)for(int j=0;j<t[i].second;j++){
    prev=max(t[i].first-x,prev+d);
    if(prev>t[i].first+x)return false;
  }
  return true;
}
void solve(){
  scanf("%d %d",&n,&d);
  for(int i=0;i<n;i++)scanf("%d %d",&t[i].first,&t[i].second);
  sort(t,t+n);
  double from=0,to=1e20;
  for(int i=0;i<800;i++){
    double middle=(from+to)/2;
    if(ok(middle))to=middle;else from=middle;
  }
  printf("%.8lf\n",from);
}
main(){
  char in[100],out[100],*pos;
  strcpy(in,__FILE__);
  strcpy(out,__FILE__);
  pos=in;
  while(*pos!='.')pos++;
  strcpy(pos,".in");
  pos=out;
  while(*pos!='.')pos++;
  strcpy(pos,".out");
  freopen(in,"r",stdin);
  freopen(out,"w",stdout);
  int t;
  scanf("%d",&t);
  for(int tt=1;tt<=t;tt++){
    printf("Case #%d: ",tt);
    solve();
    fflush(stdout);
  }
}
