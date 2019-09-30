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

string _c[310];
int from[310],to[310],m[310][310][310],c[310];
map<string,int> _name;
int next_name;
int name(string s){if(_name.count(s))return _name[s];return _name[s]=next_name++;}
main(){
  int C,N;cin>>C;
  for(int cc=1;cc<=C;cc++){
    cin>>N;
    FOR(i,N)cin>>_c[i]>>from[i]>>to[i];
//FOR(i,N)c[i]='a'+rand()%26,from[i]=1+rand()%5000,to[i]=from[i]+rand()%1000;
    _name.clear();next_name=0;
    FOR(i,N)c[i]=name(_c[i]);
    FOR(i,N)FOR(j,i)if(to[i]<to[j]){
      swap(c[i],c[j]);
      swap(from[i],from[j]);
      swap(to[i],to[j]); 
    }
#define INF 1000000
    FOR(i,N)FOR(j,N)FOR(k,N)m[i][j][k]=INF;
    FOR(i,N){
      FOR(j,N)FOR(k,j+1){
        if(from[i]==1){m[i][j][k]=m[i][k][j]=1;continue;}
        for(int prev=i-1;i>=0;prev--)if(to[prev]>=from[i]-1){
          if(c[i]==c[prev])m[i][j][k]<?=m[prev][j][k]+1;
          else if(c[j]==c[prev])m[i][j][k]<?=m[prev][i][k]+1;
          else if(c[k]==c[prev])m[i][j][k]<?=m[prev][j][i]+1;
        } else break;
        m[i][k][j]=m[i][j][k];
      }
    }
    int ans=INF;
    FOR(i,N)FOR(j,N)FOR(k,N)if(to[i]==10000)ans<?=m[i][j][k];
    cout<<"Case #"<<cc<<": ";
    if(ans<INF)cout<<ans;else cout<<"IMPOSSIBLE";
    cout<<endl;
  }
}
