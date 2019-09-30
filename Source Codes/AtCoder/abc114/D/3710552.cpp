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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  int d[n + 1];
  fill(d, d + n + 1, 0);

  d[1] = 1;
  for(int i = 2; i <= n; i++){
    int m = i;
    for(int j = 2; j <= m; j++){
      while(m % j == 0){
        ++d[j];
        m /= j;
      }
    }
  }

  int dp[n + 1][76];
  for(int i = 0; i < n + 1; i++){
    fill(dp[i], dp[i] + 76, 0);
  }

  dp[1][1] = 1;
  for(int i = 2; i <= n; i++){
    for(int j = 1; j <= 75; j++){
      for(int k = 0; k <= d[i]; k++){
        if(j % (k + 1) == 0){
          dp[i][j] += dp[i - 1][j / (k + 1)];
        }
      }
    }
  }

  cout << dp[n][75] << endl;

  return 0;
}