#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
using namespace std;

typedef long long ll;

ll f(ll x){
  ll sum = 0;
  while(x){
    sum += x % 10;
    x /= 10;
  }
  return sum;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n;
  cin >> n;

  set< ll > ans;
  for(ll k = 0; n - k >= 0 && k <= 200; k++){
    ll x = n - k;
    if(f(x) == k){
      ans.insert(x);
    }
  }

  string s;
  s += to_string(ans.size()) + "\n";
  for(ll a: ans){
    s += to_string(a) + "\n";
  }

  cout << s;

  return 0;
}