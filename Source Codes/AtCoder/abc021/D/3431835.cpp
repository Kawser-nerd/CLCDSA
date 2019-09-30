#include <iostream>
#include <math.h>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <algorithm>
#include <iomanip>
#include <string.h>

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define ALL(a)  (a).begin(),(a).end()

typedef long long lint;

using namespace std;
lint p=1e9+7;

lint pow_mod(lint a,lint b,lint p){
  if(b==0)return 1;
  if(b%2==0){
    lint d=pow_mod(a,b/2,p);
    return (d*d)%p;
  }else{
    return (a*pow_mod(a,b-1,p))%p;
  }
}

//x / a mod p=x * inv_mod(a,p) 
lint inv_mod(lint a,lint p){
  return pow_mod(a,p-2,p);//(a^(p-2))mod p
}

int main(){
  lint n,k;
  cin>>n>>k;
  lint ans=1;
  REP(i,k){
    ans*=i+n;
    ans%=p;
  }
  lint d=1;
  REP(i,k){
    d*=i+1;
    d%=p;
  }
  ans*=inv_mod(d,p);
  ans%=p;
  cout<<ans<<endl;
  return 0;
}