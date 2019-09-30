#include<iostream>
using namespace std;
#define ll long long 
int main(){
  int n;
  ll a=1,b=1;
  ll s=1,t=1;
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>s>>t;
    ll h =max((a+s-1)/s,(b+t-1)/t);
    a=s*h;
    b=t*h;
  }
  cout<<(a+b)<<endl;
}