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
#define PROBLEM_ID "A"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int n;
    cin >> n;
    vector<int> d(n), l(n);
    int D;
    for (int i = 0; i < n; ++i) {
      cin >> d[i] >> l[i];
    }
    cin >> D;
    vector<int> min_prev(n, n);
    bool result = false;
    int right = 2 * d[0];
    for (int i = 1; i < n; ++i) {
      if (d[i] <= right) {
        min_prev[i] = 0;
      } else {
        break;
      }
    }
    if (D <= right) {
      result = true;
    }
    if (!result) {
      for (int i = 1; i < n; ++i) {
        if (min_prev[i] == n) {
          continue;
        }
        int swing = d[i] - d[min_prev[i]] <= l[i] ? d[i] - d[min_prev[i]] : l[i];
        for (int j = i + 1; j < n; ++j) {
          if (d[j] <= d[i] + swing) {
            min_prev[j] = min(min_prev[j], i);
          } else {
            break;
          }
        }
        if (D <= d[i] + swing) {
          result = true;
          break;
        }
      }
    }
    cout << "Case #" << test_index + 1 << ": ";
    cerr << "Case #" << test_index + 1 << ": ";
    if (result) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
