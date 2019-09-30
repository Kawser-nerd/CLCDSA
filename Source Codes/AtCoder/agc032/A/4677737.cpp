#include <iostream>
#include <stdio.h>
#include<vector>
#include<climits>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<functional>
#include <numeric>
#include <map>
#define FORi(N) for(int i=0;i<N;++i)
#define FORj(N) for(int j=0;j<N;++j)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
ll gcd(ll m,ll n){
  if(n==0)return abs(m);
  return(gcd(n,m%n));
}
void putYN(bool b){
  if(b){
    cout<<"YES"<<endl;
  }else{
    cout<<"NO"<<endl;
  }
}
vector<ll> dp(vector<ll>& b,ll n){//n?????
  if(b.size()==0)return vector<ll>();
  vector<ll> c ,ret,d;
  for(int i=n-1;i>=0;--i){
    if(b[i]==i+1){
      c=b;
      c.erase(c.begin()+i);
      ret = dp(c,n-1);
      if(ret.size()==1&&ret[0]==-1)break;
      ret.push_back(i+1);
      return ret;
    }
  }
  
   ret = vector<ll>{-1};
  return ret;
}
int main(){
  ll N;
  cin>>N;
  vector<ll> b(N);
  FORi(N){
    cin>>b[i];
  }
  vector<ll> ret = dp(b,N);
  FORi(ret.size()){
    cout<<ret[i]<<endl;
  }
  return 0;
}