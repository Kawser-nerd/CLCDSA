#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<int> num(3);
  for (int i = 0; i < 3; ++i) {
    std::cin >> num[i];
  }
  std::sort(num.begin(), num.end());
  std::vector<int> ans(2, 0);
  for (int i = 0; i < 2; ++i) {
    int a, b, c;
    if (num[2] % 2 == i) {
      ans[i] += 1;
      c = num[2] - 1;
    } else {
      c = num[2];
    }
    if (num[1] % 2 == i) {
      if (c > num[1]) {
        ans[i] += 2;
        b = num[1] + 1;
      } else {
        ans[i] += 1;
        b = num[1] - 1;
      }
    } else {
      b = num[1];
    }
    ans[i] += (c - b) / 2;
    if (num[0] % 2 == i) {
      if (c > num[0]) {
        ans[i] += 2;
        a = num[0] + 1;
      } else {
        ans[i] += 1;
        a = num[0] - 1;
      }
    } else {
      a = num[0];
    }
    ans[i] += (c - a) / 2;
  }
  std::cout <<  std::min(ans[0], ans[1]) << std::endl;
  return 0;
}