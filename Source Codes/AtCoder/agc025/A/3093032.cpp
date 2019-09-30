#include <iostream>
#include <string>
using namespace std;

using ll = long long;

#define for_(i, a, b) for(int i = (a);i < (b);++i)
#define rfor_(i, a, b) for(int i = (b)-1;i >= (a);--i)
#define rep(i, n) for_(i, 0, n)
#define rrep(i, n) rfor_(i, 0, n)

string N;
int t;

int main() {
  cin.tie(0);cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  cin>>N;
  rep(i, N.length())t += N[i] - '0';
  
  cout<<(t==1?10:t)<<endl;
  
  return 0;
}