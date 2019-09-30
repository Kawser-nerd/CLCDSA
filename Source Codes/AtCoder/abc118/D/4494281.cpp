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

  int b[10] = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};

  int n, m;
  cin >> n >> m;
  int a[m];
  for(int i = 0; i < m; i++){
    cin >> a[i];
  }

  sort(a, a + m);

  int dp[m + 1][n + 1];
  for(int i = 0; i <= m; i++){
    fill(dp[i], dp[i] + n + 1, -1);
  }

  dp[0][0] = 0;
  for(int i = 1; i <= m; i++){
    for(int j = 0; j <= n; j++){
      int tmp = -1;
      for(int k = 0; j - k * b[a[i - 1]] >= 0; k++){
        if(dp[i - 1][j - k * b[a[i - 1]]] >= 0)
          tmp = max(tmp, dp[i - 1][j - k * b[a[i - 1]]] + k);
      }
      if(tmp >= 0) dp[i][j] = tmp;
    }
  }

  string ans;
  int r = n;
  for(int i = m - 1; r >= 0 && i >= 0; i--){
    int k = r / b[a[i]];
    while(k >= 0){
      if(dp[i + 1][r] == dp[i][r - b[a[i]] * k] + k) break;
      --k;
    }
    r -= b[a[i]] * k;
    for(int j = 0; j < k; j++){
      ans += to_string(a[i]);
    }
  }

  cout << ans << endl;

  return 0;
}