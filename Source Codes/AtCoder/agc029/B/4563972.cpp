#include <stdio.h>
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <list>
#include <map>

#define FORi(N) for(ll i=0;i<N;++i)
#define FORj(N) for(ll i=0;i<N;++i)
#define FABi(a,b) for(ll i=a;i<=b;++i)

using namespace std;
using ll = long long;
using ld = long double;
int main(){
  ll N;
  cin>>N;
  list<ll> Avec(N);
  map<ll,ll> Amap;
  ll num = 0;
  FORi(N){
    ll tmp;
    cin>>tmp;
    Avec.push_back(tmp);
    if(Amap.find(tmp)!=Amap.end()){
      Amap[tmp]++;
    }else{
      Amap[tmp]=1;
    }
  }
  Avec.sort(greater<ll>());
  for(auto i = Avec.begin();i!=Avec.end();i++){
    ll c=*i;
    auto it = Amap.find(c);
    if(it==Amap.end())continue;
    it->second-=1;
    if(it->second == 0)Amap.erase(it);
    ll _2n = pow(2,(int)log2(c)+1);
    auto itr = Amap.find(_2n-c);
    if(itr != Amap.end()){
      itr->second-=1;
      if(itr->second == 0)Amap.erase(itr);
      num++;
    }
  }
  cout<<num<<endl;
  return 0;
}