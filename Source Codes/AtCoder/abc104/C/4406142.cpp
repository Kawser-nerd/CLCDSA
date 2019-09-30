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
  ll D,G;
  cin>>D>>G;
  vector<ll> P(D),C(D);
  FORi(D){
    cin>>P[i]>>C[i];
  }
  ll minnum=LLONG_MAX;
  FORi(pow(2,D)){
    bitset<100> bit(i);
    ll curp=0;
    ll curnum=0;
    for(int ii=0;ii<D;++ii){
      if(bit[ii]){
        curp+=C[ii];
        curp+=(ii+1)*P[ii]*100;
        curnum+=P[ii];
      }
    }
    if(curp>=G){
      minnum=min(minnum,curnum);
      continue;
    }
    ll addnum = D-1;
    while(bit[addnum])addnum--;
    for(ll ii=0;ii<P[addnum]-1;++ii){
      curp+=(addnum+1)*100;
      curnum++;
      if(curp>=G){
        minnum=min(minnum,curnum);
        break; 
      }
    }
  }
  cout<<minnum<<endl;
  return 0;
}