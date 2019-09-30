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
  ll N,K;
  cin>>N>>K;
  vector<vector<ll>> sushi;
  FORi(N){
    vector<ll> tmp(3);
    cin>>tmp[0]>>tmp[1];//???????
    sushi.push_back(tmp);
  }
  sort(sushi.begin(),sushi.end(),[](vector<ll> a,vector<ll> b){
    return a[1]>b[1];
  });
  map<ll,ll> select;//???????
  list<ll> sellist;//???sushi???
  ll oisisum=0;//??????
  ll syurui=0;
  ll manzokumax=0;
  FORi(K){
    ll neta=sushi[i][0];
    oisisum+=sushi[i][1];
    if(select.find(neta)==select.end()){
      sellist.insert(sellist.begin(),i);
      select[neta]=1;
      syurui++;
    }else{
      sellist.push_back(i);
      select[neta]++;
    }
  }
  manzokumax=syurui*syurui+oisisum;
  for(ll i = K;i<N;++i){
    ll neta=sushi[i][0];
    if(select.find(neta)!=select.end())continue;
    ll rmsushi=sellist.back();
    ll rmneta=sushi[rmsushi][0];
    if(select.find(rmneta)->second==1ll)break;
    select[rmneta]--;
    oisisum-=sushi[rmsushi][1];
    sellist.pop_back();
    select[neta]=1;
    sellist.insert(sellist.begin(),i);
    oisisum+=sushi[i][1];
    syurui++;
    
  	manzokumax=max(manzokumax,syurui*syurui+oisisum);
    
  }
  cout<<manzokumax<<endl;
  return 0;
}