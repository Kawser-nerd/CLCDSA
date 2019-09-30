#include <iostream>
#include <vector>
#include <set>

int main() {
  unsigned N;
  std::cin >> N;
  std::vector<std::pair<long long, long long>> lr(N);
  for (unsigned i = 0; i < N; ++i) {
    std::cin >> lr[i].first >> lr[i].second;
  }
  std::multiset<long long> left;
  std::multiset<long long> right;
  long long left_add = 0;
  long long right_add = 0;
  long long min = 0;
  left.insert(lr[0].first);
  right.insert(lr[0].first);
  for (unsigned i = 1; i < N; ++i) {
    right_add += lr[i - 1].second - lr[i - 1].first;
    left_add -= lr[i].second - lr[i].first;
    if (*left.rbegin() + left_add > lr[i].first) {
      min += *left.rbegin() + left_add - lr[i].first;
      right.insert(*left.rbegin() + left_add - right_add);
      auto x = left.end();
      --x;
      left.erase(x);
      left.insert(lr[i].first - left_add);
      left.insert(lr[i].first - left_add);
    } else if (*right.begin() + right_add < lr[i].first) {
      min += lr[i].first - (*right.begin() + right_add);
      left.insert(*right.begin() + right_add - left_add);
      right.erase(right.begin());
      right.insert(lr[i].first - right_add);
      right.insert(lr[i].first - right_add);
    } else {
      left.insert(lr[i].first - left_add);
      right.insert(lr[i].first - right_add);
    }
  }
  std::cout << min;
  return 0;
}