#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define ll long long int 

int main(){
  int n ,x;
  ll ans = 0L;
  cin >> n >> x;
  vector< ll > a(n);
  for(int i = 0; i < n; ++i){
    cin >> a[i];
    ans += a[i];
  }
  vector< ll > b(a);
  for(int k = 0; k < n; ++k){
    //cout << "-----???" << k << "???????---------" << endl;
    ll sum_born_cost = 0;
    for(int i = 0; i < n; ++i){
      int c = i - k;
      if(c < 0) c += n;
      //cout << " when (k,i) = " << "(" << k << "," << i << ")" << endl;
      //cout << " c = " << c << endl;
      b[i]  = min( b[i], a[c]);
      sum_born_cost += b[i];
      //cout << "b[" << i << "] = " << b[i] << endl;
    }
    ll temp = k * x + sum_born_cost; 
    ans  = min(ans, temp);
    //cout << "sum_born_cost = " << sum_born_cost << endl;
    //cout << "temp = " << temp << endl;
    //cout << "ans  = " << ans  << endl;
    //cout << endl;
  }
  cout << ans << endl;
  return 0;
}