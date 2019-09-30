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

ll gcd(ll x, ll y){
  return y ? gcd(y, x % y) : x;
}

ll lcm(ll x, ll y){
  return x / gcd(x, y) * y;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  ll n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;

  ll l = lcm(n, m);
  if(s.length() > t.length()){
    ll tmpi = n;
    n = m;
    m = tmpi;
    string tmps = s;
    s = t;
    t = tmps;
  }

  bool able = true;
  for(ll i = 0; i < l; i += l / n){
    if(i % (l / m) == 0){
      if(t[i / (l / m)] != s[i / (l / n)]){
        able = false;
        break;
      }
    }
  }

  if(able) cout << l << endl;
  else cout << -1 << endl;

  return 0;
}