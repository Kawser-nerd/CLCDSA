#include <iostream>
#include <algorithm>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <complex>
#include <valarray>
#include <unordered_map>
#include <array>
#include <fstream>
#include <cassert>
#include <cmath>
#include <functional>
#include <iomanip>
#include <random>
#include <numeric>

#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define fi first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
const int INFINT = 1 << 30;                          // 1.07x10^ 9
const int INFINT_LIM = (1LL << 31) - 1;              // 2.15x10^ 9
const ll INFLL = 1LL << 60;                          // 1.15x10^18
const ll INFLL_LIM = (1LL << 62) - 1 + (1LL << 62);  // 9.22x10^18
const double EPS = 1e-10;
const int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};

const int MAX_N = 52;
int N;
string str1, str2;

int main() {
  cin >> N >> str1 >> str2;
  vector<int> pattern;

  for (int i = 0; i < N; ++i) {
    if (str1[i] == str2[i]) pattern.push_back(1);
    else {
      pattern.push_back(2);
      ++i;
    }
  }

  ll ans;
  if (pattern[0] == 1) ans = 3;
  else ans = 6;

  for (int i = 1; i < pattern.size(); ++i) {
    if (pattern[i-1] == 1 && pattern[i] == 1) (ans *= 2) %= MOD;
    else if (pattern[i-1] == 1 && pattern[i] == 2) (ans *= 2) %= MOD;
    else if (pattern[i-1] == 2 && pattern[i] == 2) (ans *= 3) %= MOD;
  }

  cout << ans << endl;

  return 0;
}