#include <iostream>
#include <algorithm>
using namespace std;

using ll = long long;

#define for_(i, a, b) for(int i = (a);i < (b);++i)
#define rfor_(i, a, b) for(int i = (b)-1;i >= (a);--i)
#define rep(i, n) for_(i, 0, n)
#define rrep(i, n) rfor_(i, 0, n)

int N;

ll S[200005];

ll c, t;

int main() {
  cin.tie(0);cout.tie(0);
  ios_base::sync_with_stdio(false);
  
  cin>>N;
  rep(i, N) {
    ll A;
    cin>>A;
    S[i+1] = A + S[i];
  }
  
  sort(S, S+N+1);
  
  rep(i, N) {
  	if(S[i+1]==S[i])c++;
  	else {
  		t += (c+1)*c/2;
  		c = 0;
  	}
  }
  t += (c+1)*c/2;
  
  cout<<t<<endl;
  
  return 0;
}