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
  string S;
  cin>>S;
  ll AGCT=0;
  ll num=0;
  FORi(S.size()){
    if(S[i]=='A'||S[i]=='G'||S[i]=='C'||S[i]=='T'){
      AGCT++;
      if(num<AGCT)num=AGCT;
    }else{
      AGCT=0;
    }
  }
  cout<<num<<endl;
  return 0;
}