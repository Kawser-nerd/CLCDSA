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
  string N;
  cin>>N;
  if(N=="A"){
    cout<<"T";
  }else if(N== "T"){
    cout<<"A";
  }else if(N=="G"){
    cout<<"C";
  }else{
    cout<<"G";
  }
  cout<<endl;
  return 0;
}