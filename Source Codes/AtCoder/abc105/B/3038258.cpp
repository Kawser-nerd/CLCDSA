#include <iostream>
using namespace std;

using ll = long long;

#define for_(i,a,b) for(int i = (a);i < (b);i++)
#define rfor_(i,a,b) for(int i = (b)-1;i >= (a);i--)
#define rep(i,n) for_(i,0,(n))
#define rrep(i,n) rfor_(i,0,(n))

int N;

int main(){
  cin.tie(0);
  
  cin>>N;
  
  while(N>=0) {
    if(N%4==0) {
      cout<<"Yes"<<endl;
      return 0;
    }
    N-=7;
  }
  
  cout<<"No"<<endl;
  
  return 0;
}