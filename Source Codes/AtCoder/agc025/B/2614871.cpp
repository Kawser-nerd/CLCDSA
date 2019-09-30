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
template <class T> using max_priority_queue = priority_queue<T>;
template <class T>
using min_priority_queue = priority_queue<T, std::vector<T>, std::greater<T>>;

const int INF = 1 << 29;
const ll LL_INF = 1LL << 60;
const double EPS = 1e-9;
const ll MOD = 1000000007;

const int dx[] = {1, 0, -1, 0}, dy[] = {0, -1, 0, 1};
int N, A, B;
ll K;
ll result;
//@verified http://codeforces.com/contest/559/submission/33876738
template <typename T> class ModUtil {
public:
  ModUtil(int N, T mod) : N(N), mod(mod), fact(N + 1), inv_fact(N + 1) {
    calc();
  }

  T get_inv(int x) { return modpow(x, mod - 2); }
  T get_fact(int n) { return fact[n]; }
  T get_inv_fact(int n) { return get_inv(fact[n]); }
  T get_P(int n, int k) {
    if (n < k)
      return 0;
    return fact[n] % mod * get_inv_fact(n - k) % mod;
  }
  T get_C(int n, int k) {
    if (n < k)
      return 0;
    return fact[n] * inv_fact[k] % mod * inv_fact[n - k] % mod;
  }
  T modpow(int a, int n) {
    if (n == 0)
      return 1;
    T res = modpow(a, n / 2);
    res *= res;
    res %= mod;
    if (n % 2)
      res *= a;
    return res % mod;
  }

private:
  vector<T> fact;
  vector<T> inv_fact;
  int N;
  T mod;
  // O(N)
  void calc() {
    fact[0] = 1;
    for (int i = 1; i <= N; i++) {
      fact[i] = i * fact[i - 1] % mod;
    }
    inv_fact[0] = 1;
    for (int i = 1; i <= N; i++) {
      inv_fact[i] = modpow(fact[i], mod - 2);
    }
  }
};
int main() {
  cin >> N >> A >> B >> K;
  ll mod = 998244353;
  ModUtil<ll> util(N + 10, mod);

  for (int a = 0; a <= N; a++) {
    ll point = 0;
    point += A * a;
    if (point > K) {
      continue;
    }
    ll res = K - point;
    if (res % B != 0) {
      continue;
    }
    ll b = res / B;
    if (b > N) {
      continue;
    }
    result += util.get_C(N, a) * util.get_C(N, b);
    result %= mod;
  }
  cout << result << endl;
  return 0;
}