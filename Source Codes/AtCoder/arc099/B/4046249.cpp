#include<iostream>
using namespace std;

using ll = unsigned long long;

ll S(ll n){
  ll res = 0;
  while(n>0){
    res += n%10;
    n = n/10;
  }
  return res;
}

bool cmp(ll x,ll y){
  return x*S(y)<=y*S(x);
}

bool check(ll n){
  for(ll m=n+1;m<10000000;m++){
    if(!cmp(n,m)){
      return false;
    }
  }
  return true;
}

int main(){
  ll k;
  cin>>k;

  ll n = 0;
  ll d = 1;
  for(ll i=0;i<k;i++){
    ll x = n+d;
    ll y = n+10*d;
    if(cmp(x,y)){
      cout<<x<<endl;
      n = x;
    }else{
      cout<<y<<endl;
      d *= 10;
      n = y;
    }
  }
}