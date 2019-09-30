#include <iostream>
using namespace std;

using ll = long long;

#define for_(i, a, b) for(int i = (a);i < (b);++i)
#define rfor_(i, a, b) for(int i = (b)-1;i >= (a);--i)
#define rep(i, n) for_(i, 0, n)
#define rrep(i, n) rfor_(i, 0, n)

int R;

int main() {
  cin.tie(0);cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  cin>>R;
  
  if(R<1200)cout<<"ABC"<<endl;
  else if(R<2800)cout<<"ARC"<<endl;
  else cout<<"AGC"<<endl;

  return 0;
}