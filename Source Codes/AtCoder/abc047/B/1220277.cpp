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
#include <numeric>
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
#define REP(i, a, b) for (int i = (a); i < (b); i++)
#define REPC(i, a) REP(i, 0, a)
#define RREP(i, a, b) for (int i = (a); i >= (b); i--)
#define RREPC(i, a) RREP(i, a, 0)
#define ALL(s) begin(s), end(s)
#define RALL(s) rbegin(s), rend(s)

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

int main(int argc, char *argv[]) {
  // INFILE();
  int w, h, n;
  cin >> w >> h >> n;

  int x0 = 0, y0 = 0, x1 = w, y1 = h;

  vector<vector<int>> v(n);
  for (auto &row : v) {
    row.resize(3);
    scan(row);
  }

  for (const auto &row : v) {
    switch (row[2]) {
    case 1:
			if (row[0] > x0) {
				x0 = row[0];
			}
      break;
    case 2:
			if (row[0] < x1) {
				x1 = row[0];
			}
      break;
    case 3:
			if (row[1] > y0) {
				y0 = row[1];
			}
      break;
    case 4:
			if (row[1] < y1) {
				y1 = row[1];
			}
      break;
    }
  }

	cout << ((x1 - x0 < 0) ? 0 : x1 - x0) * ((y1 - y0 < 0) ? 0 : y1 - y0) << endl;
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