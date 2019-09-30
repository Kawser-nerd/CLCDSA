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
  ll N,N_;
  cin>>N;
  if(N==0){
    cout<<0<<endl;
    return 0;
  }
  N_=N;
  ll num=1;
  while(N_!=0){
    N_/=4;
    num++;
  }
  N_=N;
  FORi(num){
    N_+=2*pow(4,i);
  }
  bitset<64> bit(N_);
  string S;
  FORi(num){
    ll tm =bit[i*2]+bit[i*2+1]*2;
    if(tm==0){
      S+="01";
    }else if(tm==1){
      S+="11";
    }else if(tm==2){
      S+="00";
    }else{
      S+="10";
    }
  }
  reverse(S.begin(),S.end());
  if(S[0]=='0')S.erase(0,1);
  if(S[0]=='0')S.erase(0,1);
  cout<<S<<endl;
  return 0;
}