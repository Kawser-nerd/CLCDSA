#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
#include<bitset>
#include<cmath>
#include<functional>
#include <numeric>
using namespace std;
using ll = long long;
ll gcd(ll m,ll n){
  if(n==0)return abs(m);
  return(gcd(n,m%n));
}
int main(){
  ll N;
  cin>>N;
  vector<ll> X(N),Y(N),H(N);
  for(ll i=0;i<N;++i){
    cin>>X[i]>>Y[i]>>H[i];
  }
  ll ansh,ansx,ansy;
  for(int i=0;i<=100;++i){
    for(int j=0;j<=100;++j){
      ll h;
      for(int k=0;k<N;++k){
        if(H[k]!=0){
          h=H[k]+abs(X[k]-i)+abs(Y[k]-j);
          break;
        }
      }
      bool flag=true;
      for(int k=0;k<N;++k){
        if(max(h-abs(X[k]-i)-abs(Y[k]-j),0ll)!=H[k])flag=false;
      }
      if(flag){
        ansh=h;
        ansx=i;
        ansy=j;
        break;
      }
    }
  }
  cout<<ansx<<" "<<ansy<<" "<<ansh<<endl;
  return 0;
}