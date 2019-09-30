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

int cnt(int x){return x*(x+1)/2;}
int p[60*60];
int parent(int x){return p[x]==x?x:p[x]=parent(p[x]);}
main(){
  int C;cin>>C;
  for(int c=1;c<=C;c++){
    int n,m;
    string s[60];
    int d[60][60];
    cin>>n>>m;
    FOR(i,n)cin>>s[i];
    typedef pair<int,int> p2;
    vector<p2> q;
    FOR(i,n)FOR(j,m)d[i][j]=1000000;
    FOR(i,n)FOR(j,m)if(s[i][j]=='T')q.push_back(p2(i,j)),d[i][j]=0;
    FOR(z,q.size()){
      int x=q[z].first,y=q[z].second;
      if(s[x][y]=='.')continue;
//      cout<<x<<" "<<y<<":"<<d[x][y]<<endl;
      if(x&&d[x-1][y]>d[x][y]+1)d[x-1][y]=d[x][y]+1,q.push_back(p2(x-1,y));                
      if(x+1<n&&d[x+1][y]>d[x][y]+1)d[x+1][y]=d[x][y]+1,q.push_back(p2(x+1,y));                
      if(y&&d[x][y-1]>d[x][y]+1)d[x][y-1]=d[x][y]+1,q.push_back(p2(x,y-1));                
      if(y+1<m&&d[x][y+1]>d[x][y]+1)d[x][y+1]=d[x][y]+1,q.push_back(p2(x,y+1));                
    }
/*    FOR(x,n){
             FOR(y,n)cout<<d[x][y]<<" ";
             cout<<endl;
             }*/
    int sum=0,cost=0;
    FOR(x,n)FOR(y,m)if(s[x][y]!='.')sum+=d[x][y];
    int nr[60][60],next_nr=0;
    memset(nr,-1,sizeof(nr));
    FOR(x,n)FOR(y,m)if(s[x][y]=='T')nr[x][y]=next_nr++;
    typedef pair<int,p2> p3;
    vector<p3> t;
    FOR(x,n)FOR(y,m)if(s[x][y]=='T') {
      int cur_nr=nr[x][y];
      FOR(i,n)FOR(j,m)d[i][j]=1000000;
      vector<p2> q;
      q.push_back(p2(x,y));
      d[x][y]=0;
      FOR(z,q.size()){
        int x=q[z].first,y=q[z].second;
        if(s[x][y]=='.')continue;
        if(s[x][y]=='T')t.push_back(p3(cnt(d[x][y])-cnt((d[x][y]-1)/2)-cnt(d[x][y]/2),p2(nr[x][y],cur_nr)));//,cout<<d[x][y]<<endl;
//      cout<<x<<" "<<y<<":"<<d[x][y]<<endl;
        if(x&&d[x-1][y]>d[x][y]+1)d[x-1][y]=d[x][y]+1,q.push_back(p2(x-1,y));                
        if(x+1<n&&d[x+1][y]>d[x][y]+1)d[x+1][y]=d[x][y]+1,q.push_back(p2(x+1,y));                
        if(y&&d[x][y-1]>d[x][y]+1)d[x][y-1]=d[x][y]+1,q.push_back(p2(x,y-1));                
        if(y+1<m&&d[x][y+1]>d[x][y]+1)d[x][y+1]=d[x][y]+1,q.push_back(p2(x,y+1));                
      }                                 
    }
    FOR(i,next_nr)p[i]=i;
    sort(t.begin(),t.end());
    FOR(i,t.size()){
      int z=t[i].first,x=t[i].second.first,y=t[i].second.second;
//      cout<<x<<" "<<y<<":"<<z<<endl;
      x=parent(x);y=parent(y);
      if(x==y)continue;
      p[x]=y;
      cost+=z;
    }
  //  cout<<sum<<" "<<cost<<endl;
    cout<<"Case #"<<c<<": "<<sum+cost<<endl;
  }
}
