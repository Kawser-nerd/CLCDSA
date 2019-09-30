#include <algorithm>
#include <bitset>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

// c++11
#include <array>
#include <tuple>
#include <unordered_map>
#include <unordered_set>

#define mp make_pair
#define mt make_tuple
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;

const int INF = 1 << 29;
const double EPS = 1e-9;
const ll MOD = 1000000007;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
const int MAX_N = 2010;
const ll LL_INF = 1LL << 50;
ll dp[MAX_N][MAX_N][2];
ll N,Z,W;
vector<ll> A;
ll res;
void init(){
  for (int i = 0; i < MAX_N; i++){
    for (int j = 0; j < MAX_N; j++){
      for (int k = 0; k < 2; k++){
        dp[i][j][k] = -1;
      }
    }
  }
}

ll memo(int pos, int idx, bool turn){
  if (pos >= N - 1){
    return abs(A[N - 1] - A[idx]);
  }

  ll &res = dp[pos][idx][turn];
  if (res >= 0){
    return res;
  }

  if (turn){//X
    res = 0;
    for (int i = pos; i < N - 1; i++){
      res = max(res, memo(i + 1, i, !turn));
    }
    res = max(res, abs(A[N - 1] - A[idx]));
  }else{//Y
    res = LL_INF;
    for (int i = pos; i < N - 1; i++){
      res = min(res, memo(i + 1, i, !turn));
    }
    res = min(res, abs(A[N - 1] - A[idx]));
  }
  // cerr << pos << " " << idx << " " << turn << " " << res << endl;
  return res;
}
int main() {
  init();
  cin >> N >> Z >> W;
  A.resize(N);
  for (auto &val : A){
    cin >> val;
  }
  A.push_back(W);
  res = 0;
  res = max(res, memo(0, N, true));
  cout << res << endl;
  return 0;
}