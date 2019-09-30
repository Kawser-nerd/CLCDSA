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
#define PROBLEM_ID "B"

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<int, int> pii;

bool Intersect(int x1, int y1, int r1, int x2, int y2, int r2) {
  if (x1 + r1 <= x2 - r2 || x1 - r1 >= x2 + r2 || y1 + r1 <= y2 - r2 || y1 - r1 >= y2 + r2) {
    return false;
  }
  return true;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int n, W, L;
    cin >> n >> W >> L;
    vector<pii> r(n);
    for (int i = 0; i < n; ++i) {
      cin >> r[i].first;
      r[i].second = i;
    }
    sort(r.rbegin(), r.rend());
    vector<int> x(n, -1);
    vector<int> y(n, -1);
    vector<pii> corners;
    x[r[0].second] = 0;
    y[r[0].second] = 0;
    int R = r[0].first;
    corners.push_back(MP(x[r[0].second] + R, y[r[0].second] - R));
    corners.push_back(MP(x[r[0].second] - R, y[r[0].second] + R));
    corners.push_back(MP(x[r[0].second] + R, y[r[0].second] + R));
    for (int i = 1; i < n; ++i) {
      int R = r[i].first;
      for (int j = 0; j < corners.size(); ++j) {
        if (corners[j].first + R > W || corners[j].second + R > L) {
          continue;
        }
        x[r[i].second] = max(corners[j].first + R, 0);
        y[r[i].second] = max(corners[j].second + R, 0);
        bool good = true;
        for (int k = 0; k < i; ++k) {
          if (Intersect(x[r[k].second], y[r[k].second], r[k].first, x[r[i].second], y[r[i].second], R)) {
            good = false;
            break;
          }
        }
        if (good) {
          break;
        }
      }
      if (x[r[i].second] == -1 || y[r[i].second] == -1) {
        cerr << "Couldn't place" << endl;
        abort();
      } 
      corners.push_back(MP(x[r[i].second] + R, y[r[i].second] - R));
      corners.push_back(MP(x[r[i].second] - R, y[r[i].second] + R));
      corners.push_back(MP(x[r[i].second] + R, y[r[i].second] + R));
    }
    cout << "Case #" << test_index + 1 << ":";
    cerr << "Case #" << test_index + 1 << ":";
    for (int i = 0; i < n; ++i) {
      cout << " " << x[i] << " " << y[i];
      cerr << " " << x[i] << " " << y[i];
    }
    cout << endl;
    cerr << endl;
  }
  return 0;
}
