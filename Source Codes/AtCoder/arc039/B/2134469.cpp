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
#define MOD (1000000007)
using namespace std;

typedef long long ll;

ll power(ll a, ll b){
  ll result = 1;
  ll base = a;
  for(int i = 0; i < 64; i++){
    if(((1l << i) & b) != 0){
      result = (result * base) % MOD;
    }
    base = (base * base) % MOD;
  }
  return result;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n, k;
  cin >> n >> k;

  ll f[k + n + 1];
  f[0] = 1;
  for(int i = 1; i <= n + k; i++){
    f[i] = (f[i - 1] * i) % MOD;
  }

  ll ans;
  if(k < n){
    ans = (f[k + n - 1] * power(f[k], MOD - 2)) % MOD;
    ans = (ans * power(f[n - 1], MOD - 2)) % MOD;
  }
  else{
    int r = k % n;
    ans = (f[n] * power(f[r], MOD - 2)) % MOD;
    ans = (ans * power(f[n - r], MOD - 2)) % MOD;
  }

  cout << ans << endl;

  return 0;
}