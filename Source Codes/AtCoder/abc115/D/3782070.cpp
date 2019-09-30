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

  int n;
  ll x;
  cin >> n >> x;

  ll b[n + 1], p[n + 1];
  b[0] = 0; p[0] = 1;
  for(int i = 1; i <= n; i++){
    b[i] = 2l * b[i - 1] + 2;
    p[i] = 2l * p[i - 1] + 1;
  }

  ll ans = 0;
  for(int i = n; i >= 0; i--){
    ll d = b[i - 1] + p[i - 1];
    if(x >= b[i] + p[i]){
      ans += p[i];
      break;
    }
    else if(x >= 2l * d + 2){
      ans += 1 + 2l * p[i - 1];
      x -= 2l * d + 2;
    }
    else if(x >= d + 2){
      ans += p[i - 1] + 1;
      x -= d + 2;
    }
    else if(x >= d + 1){
      ans += p[i - 1];
      x -= d + 1;
    }
    else{
      --x;
    }
  }

  cout << ans << endl;

  return 0;
}