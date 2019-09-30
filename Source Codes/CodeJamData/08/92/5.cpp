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

int w,h,x[2],y[2];
bool b[110][110];
void go(int tx,int ty){
  if(tx<0||tx>=w||ty<0||ty>=h)return;
  if(b[tx][ty])return;
  b[tx][ty]=1;
  FOR(i,2)go(tx+x[i],ty+y[i]);     
}
main(){
  int C;cin>>C;
  for(int c=1;c<=C;c++){
    cin>>w>>h;
    FOR(i,2)cin>>x[i]>>y[i];
    int xs,ys;
    cin>>xs>>ys;
    memset(b,0,sizeof(b));
    go(xs,ys);
    int ans=0;
    FOR(i,w)FOR(j,h)ans+=b[i][j];
    cout<<"Case #"<<c<<": "<<ans<<endl;
  }
}
