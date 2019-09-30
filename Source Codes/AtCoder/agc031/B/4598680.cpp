#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <tuple>
#include <queue>
#include <bitset>
#include <unordered_map>
#include <tuple>
#include <utility>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <sys/time.h>

using namespace std;

long long MOD = 1000000007;

void solve(long long N, vector<long long> C){
  vector<long long> C_;
  C_.push_back(C[0]);
  for (int i = 1; i < C.size(); i++) {
    if (C[i] != C[i-1]) {
      C_.push_back(C[i]);
    }
  }
  vector<long long> dp(C_.size(), 0);
  vector<long long> A(200000, 0);
  dp[0] = 1;
  A[C_[0]] = 1;
  for (int i = 1; i < C_.size(); i++) {
    dp[i] = dp[i-1];
    dp[i] += A[C_[i]];
    dp[i] %= MOD;
    A[C_[i]] += dp[i-1];
    A[C_[i]] %= MOD;
  }
  std::cout << dp[C_.size()-1] << std::endl;
}

int main(){
  long long N;
  scanf("%lld",&N);
  vector<long long> C(N);
  for(int i = 0 ; i < N ; i++){
    scanf("%lld",&C[i]);
  }
  solve(N, C);
  return 0;
}