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
  string S;
  ll K;
  cin>>S>>K;
  ll _1=0;
  FORi(S.size()){
    if(S[i]!='1'){
      break;
    }
    _1++;
  }
  if(_1>=K){
    cout<<1<<endl;
  }else{
    cout<<S[_1]<<endl;
  }
  return 0;
}