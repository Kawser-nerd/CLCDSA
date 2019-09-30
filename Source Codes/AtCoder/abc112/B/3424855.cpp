#include <iostream>
using namespace std;
#define rep(i, n) for(int i=0;i<(n);i++)

int N, T;

int c[102], t[102];

int mc = 1003;

int main() {
  
  cin>>N>>T;
  rep(i, N)cin>>c[i]>>t[i];
  
  rep(i, N) {
    if(t[i]<=T) {
      if(c[i]<mc)mc = c[i];
    }
  }
  
  if(mc>1000)cout<<"TLE"<<endl;
  else cout<<mc<<endl;
  
  return 0;
}