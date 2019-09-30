#include <iostream>
using namespace std;

using ll = long long;

#define for_(i, a, b) for(int i = (a);i < (b);++i)
#define rfor_(i, a, b) for(int i = (b)-1;i >= (a);--i)
#define rep(i, n) for_(i, 0, n)
#define rrep(i, n) rfor_(i, 0, n)

int N;
int p, a, l, t;

int main() {
  cin.tie(0);cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  cin>>N;
  cin>>p;
  l = 1;
  rep(i, N-1) {
  	cin>>a;
  	if(p==a)l++;
  	else {
  		t += l/2;
  		l = 1;
  		p = a;
  	}
  }
  t += l/2;
  
  cout<<t<<endl;
  
  return 0;
}