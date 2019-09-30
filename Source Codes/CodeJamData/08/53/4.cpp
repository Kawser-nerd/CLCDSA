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

int M,N,t[110][1<<10];
string m[100];
bool ok_row(int nr,int take){
  FOR(i,N-1)if(take&1<<i && take&1<<i+1)return false;
  FOR(i,N)if(take&1<<i && m[nr][i]!='.')return false;
  return true;
}
int cnt(int x){int ans=0;while(x)ans+=x&1,x>>=1;return ans;}
main(){
  int C;cin>>C;
  for(int c=1;c<=C;c++){
    cin>>M>>N;
    FOR(i,M)cin>>m[i];
    memset(t,-1,sizeof(t));
    FOR(take,1<<N)if(ok_row(0,take))t[0][take]=cnt(take);
    for(int i=1;i<M;i++)FOR(take,1<<N)if(ok_row(i,take))FOR(take2,1<<N)
      if(!((take>>1)&take2)&&!(take&(take2>>1))&&t[i-1][take2]>-1)
        t[i][take]>?=t[i-1][take2]+cnt(take);
    cout<<"Case #"<<c<<": "<<*max_element(t[M-1],t[M-1]+(1<<N))<<endl;
  }
}
