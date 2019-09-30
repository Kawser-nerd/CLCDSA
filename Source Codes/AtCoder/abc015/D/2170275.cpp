#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

vector<vector<vector<long>>> memo;
int W, N, K;
vector<int> w;
vector<int> v;

// memo[n??][?????] = ?????
long dp(int n, int k, int m) { // ??m??????
  if (m == 0 || n == N) return 0; // ??????????
  if (memo[n][k][m] != -1) return memo[n][k][m];
  if (w[n] > k)  return dp(n+1, k, m);
  return memo[n][k][m] = max(dp(n+1, k, m), dp(n+1, k-w[n], m-1) + v[n]);
}


int main(){
  cin >> W >> N >> K;
  w = vector<int>(N);
  v = vector<int>(N);
  memo = vector<vector<vector<long>>>(N+1, vector<vector<long>>(W+1, vector<long>(K+1, -1)));
  for (int i=0; i<N; i++) cin >> w[i] >> v[i];

  cout << dp(0, W, K) << endl;
}