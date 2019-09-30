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

int n,m;
string s[60];
int mem[20][20][1<<16];
int calc(int x,int y,int blue) {
  if (x==n)return 0;
  if (y==m)return calc(x+1,0,blue);
  if (mem[x][y][blue]>-1)return mem[x][y][blue];
  int ans=0;
  if (s[x][y]=='.')ans=calc(x,y+1,blue/2);
  else {
    ans=4-(x && blue&1)*2-(y && blue&(1<<m-1))*2+calc(x,y+1,blue/2+(1<<m-1));
    if (s[x][y]=='?')ans=max(ans,calc(x,y+1,blue/2));
  }
    //cout<<x<<" "<<y<<":"<<blue<<" "<<ans<<endl;
  return mem[x][y][blue]=ans;
}
main(){
  int C;cin>>C;
  for(int c=1;c<=C;c++){
    cin>>n>>m;
    FOR(i,n)cin>>s[i];
    memset(mem,-1,sizeof(mem));
//    FOR(i,n)FOR(j,m)mem[i][j].clear();
    cout<<"Case #"<<c<<": "<<calc(0,0,0)<<endl;
  }
}
