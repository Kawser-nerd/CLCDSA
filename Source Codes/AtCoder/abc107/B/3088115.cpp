#include <iostream>
using namespace std;

using ll = long long;

#define for_(i, a, b) for(int i = (a);i < (b);++i)
#define rfor_(i, a, b) for(int i = (b)-1;i >= (a);--i)
#define rep(i, n) for_(i, 0, n)
#define rrep(i, n) rfor_(i, 0, n)

int H, W;

char a[102][102];

bool t[102], y[102];

int main() {
  cin.tie(0);cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  cin>>H>>W;
  
  rep(i, H)rep(j, W) {
    cin>>a[i][j];
    if(a[i][j]=='#')t[i] = y[j] = true;
  }
  
  rep(i, H) {
  	if(!t[i])continue;
  	rep(j, W) {
      if(!y[j])continue;
      cout<<a[i][j];
    }
    cout<<endl;
  }
  
  return 0;
}