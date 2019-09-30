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

  int h, w, k;
  cin >> h >> w >> k;

  if(w == 1){
    cout << 1 << endl;
    return 0;
  }

  ll fib[w];
  fib[0] = 1;
  fib[1] = 2;
  for(int i = 2; i < w; i++){
    fib[i] = (fib[i - 1] + fib[i - 2]) % MOD;
  }

  ll dp[h + 1][w];
  fill(dp[0], dp[0] + w, 0);
  dp[0][0] = 1;
  for(int i = 1; i <= h; i++){
    for(int j = 0; j < w; j++){
      ll tmp = (dp[i - 1][j]);
      if(j - 1 >= 0) tmp = (tmp * fib[j - 1]) % MOD;
      if(w - j - 2 >= 0) tmp = (tmp * fib[w - j - 2]) % MOD;
      dp[i][j] = tmp;
      if(j > 0){
        tmp = (dp[i - 1][j - 1]);
        if(j - 2 >= 0) tmp = (tmp * fib[j - 2]) % MOD;
        if(w - j - 2 >= 0) tmp = (tmp * fib[w - j - 2]) % MOD;
        dp[i][j] = (dp[i][j] + tmp) % MOD;
      }
      if(j + 1 < w){
        tmp = (dp[i - 1][j + 1]);
        if(w - j - 3 >= 0) tmp = (tmp * (fib[w - j - 3])) % MOD;
        if(j - 1 >= 0) tmp = (tmp * fib[j - 1]) % MOD;
        dp[i][j] = (dp[i][j] + tmp) % MOD;
      }
    }
  }

  cout << dp[h][k - 1] << endl;

  return 0;
}