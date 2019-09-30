#include <iostream>
#include <map>
using namespace std;

using ll = long long;

#define for_(i,a,b) for(int i = (a);i < (b);i++)
#define rfor_(i,a,b) for(int i = (b)-1;i >= (a);i--)
#define rep(i,n) for_(i,0,(n))
#define rrep(i,n) rfor_(i,0,(n))

int N, M, T, X;

map<ll, int> d;

ll c;

int main(){
  cin.tie(0);
  
  cin>>N>>M;
  
  rep(i, N) {
  	cin>>X;
  	T = (T+X)%M;
  	if(T==0)c++;
  	d[T]++;
  }
  
  for (auto i : d) {
        ll it = i.second;
        c += it * (it - 1) / 2;
  }
  
  cout<<c<<endl;
  
  return 0;
}