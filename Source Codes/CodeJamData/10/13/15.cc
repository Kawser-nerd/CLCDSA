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

const int MAXN = 1000001;
vector<pii> bounds;

/*vector< vector<int> > win;


int getwin(int a, int b) {
  if (win[a][b] != -1) {
    return win[a][b];
  }
  if (a < b) {
    swap(a, b);
  }
  if (a >= 2 * b) {
    return 1;
  }
  return 1 - getwin(b, a - b);
}*/

bool CanWin(int a, int b) {
  if (a < b) {
    swap(a, b);
  }
  if (a >= 2 * b) {
    return true;
  }
  if (a == b) {
    return false;
  }
  pii range = bounds[b];
  if (range.first == -1 || range.second == -1) {
    cerr << "can't compute" << endl;
    abort();
  }
  return range.first <= a - b && a - b <= range.second;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  /*win.assign(MAXN, vi(MAXN, -1));
  win[1][1] = 0;
  for (int i = 2; i < MAXN; ++i) {
    win[1][i] = win[i][1] = 1;
  }
  for (int i = 1; i < MAXN; ++i) {
    for (int j = 1; j < MAXN; ++j) {
      if (getwin(i, j) == 0) {
        cerr << i << ' ' << j << endl;
      }
    }
  }*/
  bounds.assign(MAXN, make_pair(-1, -1));
  bounds[1].first = bounds[1].second = 1;
  for (int a = 2; a < MAXN; ++a) {
    int low = a / 2;
    int up = a;
    while (low < up - 1) {
      int middle = (low + up) / 2;
      if (CanWin(a, middle)) {
        low = middle;
      } else {
        up = middle;
      }
    }
    bounds[a].first = up;
    low = a;
    up = 2 * a;
    while (low < up - 1) {
      int middle = (low + up) / 2;
      bool CanWinThis = !CanWin(a, middle - a);
      if (CanWinThis) {
        up = middle;
      } else {
        low = middle;
      }
    }
    bounds[a].second = low;
  }
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int a_from, a_to, b_from, b_to;
    cin >> a_from >> a_to >> b_from >> b_to;
    ll result = ll(a_to - a_from + 1) * (b_to - b_from + 1);
    for (int i = a_from; i <= a_to; ++i) {
      int left = max(bounds[i].first, b_from);
      int right = min(bounds[i].second, b_to);
      if (right >= left) {
        result -= (right - left + 1);
      }
    }
    cout << "Case #" << test_index + 1 << ": " << result << endl;
  }
  return 0;
}
