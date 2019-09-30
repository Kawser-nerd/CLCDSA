#include<iostream>
#define m(a) min(X,max(0,a))
using namespace std;

int r[200000];
int X,K,Q,T,A,s,l,k,t,x,f=-1;

int main()
{
  cin>>X>>K;
  for(;l<K;)cin>>r[l++];

  l = X;
  
  for(cin >> Q; Q--;) {
    cin >> T >> A;
    for(; k<K&T>=r[k]; ) {
      int d = f * (r[k] - t);
      x += d;
      s=m(s+d);
      l=m(l+d);
      t = r[k];
      k++;
      f *= -1;
    }
    cout << m(min(l, max(s, A + x)) + f * (T-t)) << endl;
  }

  return 0;
}