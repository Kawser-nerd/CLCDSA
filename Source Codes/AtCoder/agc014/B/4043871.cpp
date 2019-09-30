#include<iostream>
using namespace std;
#define fr(i,n) for(i=0;i++<n;)

int main(){
  int i,n,m,a;int c[100010]={};
  cin>>n>>m;
  fr(i,n){
    //cout<<c[i]<<endl;
  }
  fr(i,2*m){cin>>a;c[a]++;c[a]%=2;}
  fr(i,n){
    if(c[i]&1){
      cout<<"NO"<<endl;
      return 0;
    }
    //cout<<c[i]<<endl;
  }
  cout<<"YES"<<endl;
}