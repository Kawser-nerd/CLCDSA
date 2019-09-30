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

const int MAXN = 256;

int getInsertions(int x, int y, int M) {
  if (M == 0) {
    if (x == y) {
      return 0;
    }
    return -1;
  }
  int insertions;
  if (y > x) {
    insertions = (y - x + M - 1) / M;
  } else {
    insertions = (x - y + M - 1) / M;
  }
  return insertions;
}

int main() {
  freopen(PROBLEM_ID".in", "r", stdin);
  freopen(PROBLEM_ID".out", "w", stdout);
  int test_count;
  cin >> test_count;
  for (int test_index = 0; test_index < test_count; ++test_index) {
    int D, I, n, M;
    cin >> D >> I >> M >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    vector< vector<int> > minCost(n + 1, vector<int>(MAXN, numeric_limits<int>::max()));
    vector<int> minCostA(MAXN, numeric_limits<int>::max());
    for (int x = 0; x < MAXN; ++x) {
      minCostA[x] = min(D, abs(a[0] - x));
    }
    for (int x = 0; x < MAXN; ++x) {
      for (int y = 0; y < MAXN; ++y) {
        int insertions = getInsertions(x, y, M);
        if (insertions >= 0) {
          minCost[1][y] = min(minCost[1][y], minCostA[x] + insertions * I);
        }
      }
    }
    for (int k = 2; k <= n; ++k) {
      vector<int> minCostA(MAXN, numeric_limits<int>::max());
      for (int x = 0; x < MAXN; ++x) {
        for (int y = 0; y < MAXN; ++y) {
          if (abs(x - y) <= M) {
            minCostA[y] = min(minCostA[y], minCost[k - 1][x] + abs(a[k - 1] - y));
          }
        }
      }
      for (int y = 0; y < MAXN; ++y) {
        minCostA[y] = min(minCostA[y], minCost[k - 1][y] + D);
      }
      for (int x = 0; x < MAXN; ++x) {
        for (int y = 0; y < MAXN; ++y) {
          int insertions =  getInsertions(x, y, M);
          if (insertions >= 0) {
            minCost[k][y] = min(minCost[k][y], minCostA[x] + insertions * I);
          }
        }
      }
    }
    int answer = numeric_limits<int>::max();
    for (int x = 0; x < MAXN; ++x) {
      answer = min(answer, minCost[n][x]);
    }
    cout << "Case #" << test_index + 1 << ": " << answer << endl;
    cerr << "Test " << test_index + 1 << endl;
  }
  return 0;
}
