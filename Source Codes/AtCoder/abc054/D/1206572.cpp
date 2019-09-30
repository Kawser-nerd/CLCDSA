#include <algorithm>
#include <bitset>
#include <boost/dynamic_bitset.hpp>
#include <cfloat>
#include <cmath>
#include <ctime>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeindex>
#include <typeinfo>
#include <vector>

#define DEBUG(x) cout << #x << ": " << x << endl
#define INFILE() freopen("input.txt", "r", stdin)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using i_i = pair<int, int>;
using ll_i = pair<ll, int>;
using i_ll = pair<int, ll>;
using d_i = pair<double, int>;
using ll_ll = pair<ll, ll>;
using d_d = pair<double, double>;

static constexpr ll LL_MOD = 1000000009;
static constexpr int I_MOD = 1000000007;
static constexpr double EPS = numeric_limits<double>::epsilon();
static constexpr double PI = 3.14159265358979323846264338327950288;

template <class T> static void scan(vector<T> &v);
static void scan(vector<string> &v, bool isWord = true);
static boost::dynamic_bitset<> scan(char trueValue = 'o');

int dp[41][401][401];

int main(int argc, char *argv[]) {
  // INFILE();
  int n, ma, mb;
  cin >> n >> ma >> mb;

  vector<vector<int>> goods(n);
  for (auto &g : goods) {
    g.resize(3);
    scan(g);
  }

  fill((int *)dp, (int *)dp[41], 99999);
  dp[0][0][0] = 0;

  for (int k = 0; k < n; k++) {
    for (int i = 0; i < 401; i++) {
      for (int j = 0; j < 401; j++) {
        if (dp[k][i][j] == 99999) {
          continue;
        }

        int val = dp[k][i][j];
        if (dp[k + 1][i + goods[k][0]][j + goods[k][1]] > val + goods[k][2]) {
          dp[k + 1][i + goods[k][0]][j + goods[k][1]] = val + goods[k][2];
        }

        if (dp[k + 1][i][j] > val) {
          dp[k + 1][i][j] = val;
        }
      }
    }
  }

  vector<int> ans;
  for (int i = 1; i < 401; i++) {
    for (int j = 1; j < 401; j++) {
      int val = dp[n][i][j];

      if (ma * j == mb * i && val > 0 && val < 99999) {
        ans.push_back(val);
      }
    }
  }

  if (ans.empty()) {
    cout << "-1\n";
    return 0;
  }

  sort(begin(ans), end(ans));
  cout << ans[0] << "\n";
  return 0;
}

template <class T> static void scan(vector<T> &v) {
  map<type_index, const char *const> m = {{typeid(int), "%d"},
                                          {typeid(ll), "%lld"},
                                          {typeid(double), "%lf"},
                                          {typeid(char), "%c"}};

  auto tFormat = m[typeid(T)];

  for (T &n : v) {
    scanf(tFormat, &n);
  }
}

static void scan(vector<string> &v, bool isWord) {
  if (isWord) {
    for (auto &n : v) {
      cin >> n;
    }
    return;
  }

  int i = 0, size = v.size();
  string s;
  getline(cin, s);

  if (s.size() != 0) {
    i++;
    v[0] = s;
  }

  for (; i < size; ++i) {
    getline(cin, v[i]);
  }
}

static boost::dynamic_bitset<> scan(char trueValue) {
  string s;
  getline(cin, s);

  if (s.size() == 0) {
    getline(cin, s);
  }

  for_each(begin(s), end(s),
           [trueValue](char &c) { c = (c == trueValue) ? '1' : '0'; });
  return boost::dynamic_bitset<>(string(rbegin(s), rend(s)));
}