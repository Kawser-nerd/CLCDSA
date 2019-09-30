#include<iostream>
#define m(a) min(X,max(0,a))
using namespace std;

int r[200000],X,K,Q,T,A,s,l,k,t,x,d,f=-1;
int main()
{
  cin>>X>>K;
  for(;l<K;)cin>>r[l++];

  l = X;
  
  for(cin >> Q; Q--;cout << m(min(l, max(s, A + x)) + f * (T-t)) << endl) 
    for(cin >> T >> A; k<K&T>=r[k]; f *= -1)
      x += d=f*(r[k]-t),
      s=m(s+d),
      l=m(l+d),
      t = r[k++];
  

  return 0;
}