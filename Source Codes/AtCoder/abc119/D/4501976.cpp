#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <deque>
#define INF_INT (INT_MAX / 2)
#define INF_LONG (LONG_MAX / 2)
//#define DEBUG true
#define DEBUG false
using namespace std;

const int MAX = 100001;
const int MOD = 1000000007;

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;
typedef pair< ll, int > pli;
typedef pair< int, ll > pil;

int ceil(int x, int y){
  return (x % y == 0) ? x / y : x / y + 1;
}

int gcd(int x, int y){
  return y ? gcd(y, x % y) : x;
}

int lcm(int x, int y){
  return x / gcd(x, y) * y;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a, b, q;
  cin >> a >> b >> q;
  ll s[a], t[b], x[q];
  for(int i = 0; i < a; i++){
    cin >> s[i];
  }
  for(int i = 0; i < b; i++){
    cin >> t[i];
  }
  for(int i = 0; i < q; i++){
    cin >> x[i];
  }

  sort(s, s + a);
  sort(t, t + b);

  string ans;
  for(int i = 0; i < q; i++){
    ll tmp = INF_LONG;
    // ->
    auto j = lower_bound(s, s + a, x[i]);
    auto k = lower_bound(t, t + b, x[i]);
    if(j != s + a && k != t + b){
      tmp = min(tmp, max(*j, *k) - x[i]);
    }
    // <-
    j = upper_bound(s, s + a, x[i]);
    k = upper_bound(t, t + b, x[i]);
    if(j != s && k != t){
      tmp = min(tmp, x[i] - min(*(j - 1), *(k - 1)));
    }
    // -> <-
    j = lower_bound(s, s + a, x[i]);
    k = upper_bound(t, t + b, x[i]);
    if(j != s + a && k != t){
      ll d1 = abs(x[i] - *j);
      ll d2 = abs(x[i] - *(k - 1));
      tmp = min(tmp, 2l * min(d1, d2) + max(d1, d2));
    }
    // <- ->
    j = upper_bound(s, s + a, x[i]);
    k = lower_bound(t, t + b, x[i]);
    if(j != s && k != t + b){
      ll d1 = abs(x[i] - *k);
      ll d2 = abs(x[i] - *(j - 1));
      tmp = min(tmp, 2l * min(d1, d2) + max(d1, d2));
    }
    ans += to_string(tmp) + "\n";
  }

  cout << ans;

  return 0;
}