#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iostream>
#include <limits>
#include <numeric>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

#define MP make_pair
#define all(v) (v).begin(), (v).end()
#define PROBLEM_ID "C"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

void Solve(const vector<int>& x, int begin, int end, vector<int>& y) {
  if (begin == end) {
    return;
  }
  vector<int> intermediate;
  int cur = begin;
  intermediate.push_back(cur);
  while (cur != end) {
    cur = x[cur];
    intermediate.push_back(cur);
  }
  for (int segment = intermediate.size() - 2; segment >= 0; --segment) {
    int left = intermediate[segment];
    int right = intermediate[segment + 1];
    Solve(x, left + 1, right, y);
    y[left] = 0;
    for (int i = left + 1; i < right; ++i) {
      y[left] = max(y[left], static_cast<int>(ceil(y[right] + (y[i] - y[right]) * double(left - right) / double(i - right) + 1e-5)));
    }
  }
  vector<double> max_dy(intermediate.size() - 1);
  vector<double> dy(intermediate.size() - 1);
  for (int segment = 0; segment + 1 < intermediate.size(); ++segment) {
    dy[segment] = max_dy[segment] = double(y[intermediate[segment]] - y[intermediate[segment + 1]]) / double(intermediate[segment + 1] - intermediate[segment]);
    if (segment > 0) {
      max_dy[segment] = max(max_dy[segment], max_dy[segment - 1]);
    }
  }
  for (int segment = intermediate.size() - 2; segment >= 0; --segment) {
    if (dy[segment] < max_dy[segment] + segment) {
      int need_y = int(ceil(y[intermediate[segment + 1]] + (max_dy[segment] + segment) * (intermediate[segment + 1] - intermediate[segment])));
      int add_y = need_y - y[intermediate[segment]];
      for (int i = begin; i <= intermediate[segment]; ++i) {
        y[i] += add_y;
      }
    }
  }
}

vector<int> Solve(const vector<int>& x) {
  vector<int> y(x.size());
  Solve(x, 0, x.size() - 1, y);
  return y;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int n;
    cin >> n;
    vector<int> x(n - 1);
    for (int i = 0; i < n - 1; ++i) {
      cin >> x[i];
      --x[i];
    }
    x.push_back(n - 1);
    cout << "Case #" << test_index + 1 << ":";
    cerr << "Case #" << test_index + 1 << ":";
    bool result = true;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        if (i < x[j] && x[i] > x[j]) {
          result = false;
          break;
        }
      }
      if (!result) 
        break;
    }
    if (!result) {
      cout << " Impossible" << endl;
      continue;
    }
    vector<int> y = Solve(x);
    for (int i = 0; i + 1 < y.size(); ++i) {
      ll a = y[i] - y[x[i]];
      ll b = x[i] - i;;
      ll c = -a * i - b * y[i];
      for (int j = i + 1; j < x[i]; ++j) {
        if (a * j + b * y[j] + c >= 0) {
          cerr << "Peak " << j << " is higher or on the line from " << i << " to " << x[i] << endl;
          abort();
        }
      }
      for (int j = x[i] + 1; j < y.size(); ++j) {
        if (a * j + b * y[j] + c > 0) {
          cerr << "Peak " << j << " is higher than the line from " << i << " to " << x[i] << endl;
          abort();
        }
      }
    }
    for (int i = 0; i < y.size(); ++i) {
      cout << " " << y[i];
    }
    cout << endl;
  }
  return 0;
}
