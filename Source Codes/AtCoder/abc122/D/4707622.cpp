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

const int A = 0, C = 1, G = 2, T = 3;

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  int n;
  cin >> n;

  ll dp[n + 1][4][4][4];
  for(int i = 0; i < n + 1; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
        fill(dp[i][j][k], dp[i][j][k] + 4, 0);
      }
    }
  }
  for(int j = 0; j < 4; j++){
    for(int k = 0; k < 4; k++){
      for(int l = 0; l < 4; l++){
        dp[3][j][k][l] = 1;
      }
    }
  }
  dp[3][C][G][A] = dp[3][C][A][G] = dp[3][G][C][A] = 0;

  for(int i = 3; i + 1 <= n; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
        for(int l = 0; l < 4; l++){
          if(j == G && k == A){
            dp[i + 1][A][G][A] = 
              (dp[i + 1][A][G][A] + dp[i][j][k][l]) % MOD;
            dp[i + 1][G][G][A] = 
              (dp[i + 1][G][G][A] + dp[i][j][k][l]) % MOD;
            dp[i + 1][T][G][A] =
              (dp[i + 1][T][G][A] + dp[i][j][k][l]) % MOD;
          }
          else if(j == A && k == G){
            dp[i + 1][A][A][G] = 
              (dp[i + 1][A][A][G] + dp[i][j][k][l]) % MOD;
            dp[i + 1][G][A][G] = 
              (dp[i + 1][G][A][G] + dp[i][j][k][l]) % MOD;
            dp[i + 1][T][A][G] = 
              (dp[i + 1][T][A][G] + dp[i][j][k][l]) % MOD;
          }
          else if(j == C && k == A){
            dp[i + 1][A][C][A] = 
              (dp[i + 1][A][C][A] + dp[i][j][k][l]) % MOD;
            dp[i + 1][C][C][A] =
              (dp[i + 1][C][C][A] + dp[i][j][k][l]) % MOD;
            dp[i + 1][T][C][A] = 
              (dp[i + 1][T][C][A] + dp[i][j][k][l]) % MOD;
          }
          else if(j == G && l == A){
            dp[i + 1][A][G][k] = 
              (dp[i + 1][A][G][k] + dp[i][j][k][l]) % MOD;
            dp[i + 1][G][G][k] = 
              (dp[i + 1][G][G][k] + dp[i][j][k][l]) % MOD;
            dp[i + 1][T][G][k] = 
              (dp[i + 1][T][G][k] + dp[i][j][k][l]) % MOD;
          }
          else if(k == G && l == A){
            dp[i + 1][A][j][G] = 
              (dp[i + 1][A][j][G] + dp[i][j][k][l]) % MOD;
            dp[i + 1][G][j][G] = 
              (dp[i + 1][G][j][G] + dp[i][j][k][l]) % MOD;
            dp[i + 1][T][j][G] = 
              (dp[i + 1][T][j][G] + dp[i][j][k][l]) % MOD;
          }
          else{
            dp[i + 1][A][j][k] =
              (dp[i + 1][A][j][k] + dp[i][j][k][l]) % MOD;
            dp[i + 1][C][j][k] =
              (dp[i + 1][C][j][k] + dp[i][j][k][l]) % MOD;
            dp[i + 1][G][j][k] =
              (dp[i + 1][G][j][k] + dp[i][j][k][l]) % MOD;
            dp[i + 1][T][j][k] =
              (dp[i + 1][T][j][k] + dp[i][j][k][l]) % MOD;
          }
        }
      }
    }
  }

  ll sum = 0;
  for(int i = 0; i < 4; i++){
    for(int j = 0; j < 4; j++){
      for(int k = 0; k < 4; k++){
        sum = (sum + dp[n][i][j][k]) % MOD;
      }
    }
  }

  cout << sum << endl;

  return 0;
}