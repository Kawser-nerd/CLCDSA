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
#define MAX_N 100000
#define MOD 1000000007
using namespace std;

typedef unsigned long long ll;

ll power(ll a, ll b){
  ll result = 1;
  ll base = a;
  for(int i = 0; i < 64; i++){
    if((b & (1l << i))){
      result = (result * base) % MOD;
    }
    base = (base * base) % MOD;
  }
  return result;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++){
    cin >> a[i];
  }

  if(a[0] != 0){
    cout << 0 << endl;
    return 0;
  }

  vector< int > d[MAX_N];
  int max_d = 0;
  for(int i = 0; i < n; i++){
    d[a[i]].push_back(i);
    max_d = max(max_d, a[i]);
  }

  if(d[0].size() > 1){
    cout << 0 << endl;
    return 0;
  }

  ll s[n];
  fill(s, s + n, 0);
  s[0] = 1;
  int t = 0;
  for(int k = 1; k <= max_d; k++){
    ll l = d[k].size();
    if(l == 0 && d[k - 1].size() == 0){
      cout << 0 << endl;
      return 0;
    }
    ll m = d[t].size();
    s[k] = s[k - 1];
    ll tmp = power(2, l * (l - 1) / 2);
    s[k] = (s[k] * tmp) % MOD;
    tmp = power(power(2, m) - 1, l);
    s[k] = (s[k] * tmp) % MOD;
    t = k;
  }

  cout << s[max_d] << endl;

  return 0;
}