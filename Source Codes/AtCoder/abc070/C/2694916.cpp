#include <iostream>
#include <tuple>
#include <vector>
#include <numeric>

#define ll uint64_t
using namespace std;
ll gcd(ll a, ll b){
  if(b == 0) return a;
  return gcd(b,a%b);
}

ll lcm(ll a, ll b){
  if(a < b) return lcm(b,a);
  if(a%b == 0) return a;
  ll g = gcd(a, b);
  return a / g * b;
}

int main() {
  int n; cin >> n;
  ll arr[n] ; 
  for(int i=0; i < n; i++) cin >> arr[i];
  ll ans = arr[0];
  for(int i=0; i<n; i++){
     ans = lcm(ans, arr[i]);
  }
  cout << ans << endl;
}