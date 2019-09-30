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
  ll N;
  cin>>N;
  vector<ll> a,b;
  bool flag =true;
  FORi(N/2){
     if(flag){
       a.push_back(i+1);
       a.push_back((N/2)*2-i);
     }
  }
  if(N%2==1){
    a.push_back(N);
    a.push_back(0);
  }
  stringstream sout;
  ll count = 0;
  FORi(a.size()/2-1){
    count+=2;
    sout<<a[i*2]<<" "<<a[(i+1)*2]<<endl;
    sout<<a[i*2+1]<<" "<<a[(i+1)*2]<<endl;
    if(a[(i+1)*2+1]!=0){
      count+=2;
      sout<<a[i*2]<<" "<<a[(i+1)*2+1]<<endl;
      sout<<a[i*2+1]<<" "<<a[(i+1)*2+1]<<endl;
    }
  }
  if(a.size()>=6){
    count+=2;
    sout<<a[0]<<" "<<a[a.size()-2]<<endl;
    sout<<a[1]<<" "<<a[a.size()-2]<<endl;
    if(a[a.size()-1]!=0){
      count+=2;
      sout<<a[0]<<" "<<a[a.size()-1]<<endl;
      sout<<a[1]<<" "<<a[a.size()-1]<<endl;
    }
  }
  cout<<count<<endl;
  cout<<sout.str();
  return 0;
}