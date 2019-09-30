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

#define MAX 1100000
bool p[MAX];
int64 d[MAX];
int parent[MAX],size[MAX];
int find(int x){return parent[x]==x?x:parent[x]=find(parent[x]);}
void join(int x,int y){x=find(x);y=find(y);if(x==y)return;if(size[y]<size[x])parent[x]=y;else {parent[y]=parent[x];size[y]+=size[x]==size[y];}}
main(){
  for(int i=2;i<MAX;i++)p[i]=1;
  for(int i=2;i<MAX;i++)if(p[i])for(int j=2*i;j<MAX;j+=i)p[j]=0;
  int C;
  cin>>C;
  for(int c=1;c<=C;c++){
    int64 A,B,P;
    cin>>A>>B>>P;
    int cnt=B-A+1;
    FOR(i,cnt)d[i]=A+i,parent[i]=i;
    for(int i=2;i<MAX;i++)if(p[i]){
      int64 first=A%i?A+i-A%i:A,cur=first;
      while(cur<=B){
        while(d[cur-A]%i==0)d[cur-A]/=i;
        if(i>=P)join(first-A,cur-A);
        cur+=i;
      }
    }
    typedef pair<int64,int> p2;
    vector<p2> t;
    FOR(i,cnt)if(d[i]>1)t.push_back(p2(d[i],i));
    sort(t.begin(),t.end());
    FOR(i,t.size())if(!i||t[i-1].first!=t[i].first){
      for(int j=i+1;j<t.size()&&t[i].first==t[j].first;j++)
        if(t[i].first>=P)join(t[i].second,t[j].second);
    }      
    int ans=0;
    FOR(i,cnt)ans+=find(i)==i;
    cout<<"Case #"<<c<<": "<<ans<<endl;
  }
}
