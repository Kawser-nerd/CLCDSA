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
  gcd(a,n);
  return (n+alfa%n)%n;
}

#define MAX (100010000*2/3)
int f[MAX];
#define MOD 10007
int64 count(int64 x){
  int ans=0;
  while(x)ans+=x/=MOD;
  return ans;
}
int64 H,W,R;
int calc(int64 x,int64 y){
  if(x<0||y<0||(x+y)%3)return 0;
  int cnt=(x+y)/3,a=2*cnt-x;
//  cout<<x<<" "<<y<<" "<<cnt<<" "<<a<<endl;
  if(a<0||a>cnt)return 0;
  if(count(cnt)-count(a)-count(cnt-a)>0)return 0;
//  cout<<x<<" "<<y<<":"<<(int64)f[cnt]*inverse(f[a],MOD)%MOD*inverse(f[cnt-a],MOD)%MOD<<endl;
assert(cnt<MAX);
  return ((int64)f[cnt])*inverse(f[a],MOD)%MOD*inverse(f[cnt-a],MOD)%MOD;
}
main(){
  f[0]=1;
  for(int i=1;i<MAX;i++){
    int j=i;
    while(j%MOD==0)j/=MOD;
    f[i]=(int64)f[i-1]*j%MOD;
  }
  int C;cin>>C;
  for(int c=1;c<=C;c++){
    cin>>H>>W>>R;
    typedef pair<int,int> p2;
    p2 t[R];
    FOR(i,R)cin>>t[i].first>>t[i].second;
    sort(t,t+R);
    int ans=calc(H-1,W-1);
    FOR(take,1<<R)if(take){
      int cur=1,first=0,mult=-1;
      while(!(take&1<<first))first++;
      cur=(int64)cur*calc(t[first].first-1,t[first].second-1)%MOD;
      for(int i=first+1;i<R;i++)if(take&1<<i){
        cur=(int64)cur*calc(t[i].first-t[first].first,t[i].second-t[first].second)%MOD;
        first=i;
        mult=-mult;
      }
      cur=(int64)cur*calc(H-t[first].first,W-t[first].second)%MOD;      
//      cout<<cur<<" "<<take<<endl;
      ans=((ans+cur*mult)%MOD+MOD)%MOD;
    }
    cout<<"Case #"<<c<<": "<<ans<<endl;
  }
}
