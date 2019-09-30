#include <iostream>
#include <algorithm>
#include <set>

int main() {
  int A, B, K;
  std::cin >> A >> B >> K;

  std::set<int> res;
  for (int i = A; i <= std::min(A+K-1, B); ++i)
    res.insert(i);
  for (int i = std::max(B-K+1, A); i <= B; ++i)
    res.insert(i);

  for (auto x: res)
    std::cout << x << std::endl;
}