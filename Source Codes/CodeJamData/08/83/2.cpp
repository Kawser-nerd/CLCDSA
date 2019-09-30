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

typedef long long int64;

int64 power(int64 x,int64 k,int64 p) {
  int r=1;
  while (k) {
    if (k&1)
      r=((int64)r*x)%p;
    k>>=1;
    x=((int64)x*x)%p;
  }
  return r;
}

int64 alfa,beta;

int64 gcd(int64 a,int64 b) {
  if (!b) {
    alfa=1;
    beta=0;
    return a;
  }
  int64 d=gcd(b,a%b),z=beta;
  //alfa*b+(a-a/b*b)*beta=beta*a+(alfa-a/b*beta)*b
  beta=alfa-a/b*beta;
  alfa=z;
  return d;
}

int64 inverse(int64 a,int64 n) {
  int64 d=gcd(a,n);
  assert(d==1);
  return (n+alfa%n)%n;
}

#define MOD 1000000009
int64 choose(int n,int k){
  if(k<0||k>n)return 0;
  int64 ans=1;
  FOR(i,k)ans=ans*(n-i)%MOD;
  for(int i=2;i<=k;i++)ans=ans*inverse(i,MOD)%MOD;
  assert(ans>=0);
  return ans;
}
int N,K;
#define MAX 610
vi s[MAX];
int mem[MAX][MAX];
int64 fact[510];
int go(int vertex,int dist2,int parent=-1){
  assert(dist2<MAX);
  if(mem[vertex][dist2]>-1)return mem[vertex][dist2];
  int children_cnt=0;  
  int64 ans;
  FOR(i,s[vertex].size())if(s[vertex][i]!=parent)children_cnt++;
  ans=choose(K-dist2-(parent!=-1),children_cnt)*fact[children_cnt]%MOD;
  assert(ans>=0);
  FOR(i,s[vertex].size())if(s[vertex][i]!=parent){
    int vertex2=s[vertex][i];
    ans=ans*(int64)go(vertex2,children_cnt-1+(parent!=-1),vertex)%MOD;
    assert(ans>=0);
  }
  return mem[vertex][dist2]=ans;
}
main(){
  int C;cin>>C;
  fact[0]=1;
  FOR(i,MAX-1)fact[i+1]=fact[i]*(i+1)%MOD;
  for(int c=1;c<=C;c++){
    cin>>N>>K;
    FOR(i,N)s[i].clear();
    FOR(i,N-1){
      int x,y;cin>>x>>y;x--;y--;
//int x=0,y=i+1;
      s[x].push_back(y);
      s[y].push_back(x);
    }
    memset(mem,-1,sizeof(mem));
    cout<<"Case #"<<c<<": "<<go(0,0)<<endl;
  }
}
