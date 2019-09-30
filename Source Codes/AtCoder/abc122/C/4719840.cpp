#include <iostream>
#include <sstream>
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
int main(){
  ll N,Q;
  string S;
  cin>>N>>Q>>S;
  vector<ll> l(Q),r(Q);
  FORi(Q){
    cin>>l[i]>>r[i];
  }
  vector<ll> AC;
  FORi(S.size()-1){
    if(S[i]=='A'&&S[i+1]=='C')AC.push_back(i+1);
  }
  auto comp=[](ll a,ll b){return a<b;};
  FORi(Q){
    auto itr1 = lower_bound(AC.begin(),AC.end(),l[i]);
    auto itr2 = lower_bound(AC.begin(),AC.end(),r[i]);
    ll num = distance(itr1,itr2);
  	cout<<num<<endl;
  }
  return 0;
}