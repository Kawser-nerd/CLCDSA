#include <iostream>
using namespace std;

using ll = long long;

#define for_(i,a,b) for(int i = (a);i < (b);i++)
#define rfor_(i,a,b) for(int i = (b)-1;i >= (a);i--)
#define rep(i,n) for_(i,0,(n))
#define rrep(i,n) rfor_(i,0,(n))

int N, K;

int main(){
	cin.tie(0);
  
  cin>>N>>K;
  
  cout<<(N%K?1:0)<<endl;
  
	return 0;
}