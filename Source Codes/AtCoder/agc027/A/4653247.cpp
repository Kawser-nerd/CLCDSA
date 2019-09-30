#include <vector>
#include <algorithm>
#include <map>
#include <iostream>

typedef long long ll;
using namespace std;
int main(){
  ll n,x;
  cin >> n >> x;
  vector<ll> a(n);
  for(ll i = 0; i<n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  auto score = 0;
  for(auto it=a.begin(); it != a.end(); ++it){
    if(x<*it){
      cout << score << endl;
      return 0;
    }else{
      ++score;
      x -= *it;
    }
  }
  if(x!=0){
    --score;
  }
  cout << score << endl;
return 0;
}