#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<functional>
#include <numeric>
#define FORi(N) for(int i=0;i<N;++i)
using namespace std;
using ll = long long;
ll gcd(ll m,ll n){
  if(n==0)return abs(m);
  return(gcd(n,m%n));
}
int main(){
  ll N,X;
  cin>>N>>X;
  vector<ll> x(N);
  FORi(N){
    cin>>x[i];
    x[i]-=X;
  }
  ll ans=x[0];
  FORi(N){
    ans=gcd(ans,x[i]);
  }
  cout<<ans<<endl;
  return 0;
}