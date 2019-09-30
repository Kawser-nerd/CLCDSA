#include <algorithm>
#include <cstdio>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using std::cin;
using std::cout;
using std::endl;

int main(void) {
  cout << std::fixed << std::setprecision(10);
  cin.tie(0);
  std::ios::sync_with_stdio(false);

  int a, b, q;
  cin >> a >> b >> q;
  std::vector<int64_t> s, t;
  for (int i = 0; i < a; i++) {
    int64_t m1;
    cin >> m1;
    s.push_back(m1);
  }
  for (int i = 0; i < b; i++) {
    int64_t m1;
    cin >> m1;
    t.push_back(m1);
  }
  std::sort(s.begin(), s.end());
  std::sort(t.begin(), t.end());
  for (int i = 0; i < q; i++) {
    int64_t query;
    cin >> query;

    auto isr = std::lower_bound(s.begin(), s.end(), query);
    auto isl = s.end();
    if (isr != s.begin()) {
      isl = isr;
      isl--;
    }
    auto itr = std::lower_bound(t.begin(), t.end(), query);
    auto itl = t.end();
    if (itr != t.begin()) {
      itl = itr;
      itl--;
    }
    // cout << *isl << "\t" << *isr << "\t" << *itl << "\t" << *itr << endl;
    int64_t result = INT64_MAX;
    if (isl != s.end() && itl != t.end()) {
      int64_t temp = query - std::min(*isl, *itl);
      result       = std::min(result, temp);
    }
    if (isr != s.end() && itr != t.end()) {
      int64_t temp = std::max(*isr, *itr) - query;

      result = std::min(result, temp);
    }
    if (isl != s.end() && itr != t.end()) {
      int64_t temp1 = query - *isl + *itr - *isl;
      int64_t temp2 = *itr - query + *itr - *isl;

      result = std::min({result, temp1, temp2});
    }
    if (isr != s.end() && itl != t.end()) {
      int64_t temp1 = *isr - query + *isr - *itl;
      int64_t temp2 = query - *itl + *isr - *itl;

      result = std::min({result, temp1, temp2});
    }
    cout << result << endl;
  }

  return 0;
}