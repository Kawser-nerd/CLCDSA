#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
#include <cstring>

using namespace std;

function<int (int, int)> comparer[] = {
  [](int a, int b) { return max(a, b); },
  [](int a, int b) { return min(a, b); }
};
constexpr int zero[] = { -1, INT_MAX / 2 };

int dp[2001][2];

int score(vector<int> const& as, int i, int cmp) {
  auto& best = dp[i][cmp];
  if (best >= 0) return best;
  auto const& better = comparer[cmp];
  int const len = as.size();
  best = zero[cmp];
  for (int j = i; j < len - 1; j++)
    best = better(best, score(as, j + 1, 1 - cmp));
  best = better(best, as[i - 1]);
  return best;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, z;
  cin >> n >> z;
  for (int i = 0; i <= 2000; i++)
    dp[i][0] = dp[i][1] = -1;
  vector<int> a(n + 1);
  for (auto& v : a)
    cin >> v;
  auto const last = a.back();
  for (auto& v : a)
    v = abs(v - last);
  cout << score(a, 1, 0) << endl;
}