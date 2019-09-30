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
  ll N;
  cin>>N;
  ll ans=0;
  FORi(N){
    ll tmp;
    cin>>tmp;
    while(tmp%2==0){
      tmp/=2;
      ans++;
    }
  }
  cout<<ans<<endl;
  return 0;
}