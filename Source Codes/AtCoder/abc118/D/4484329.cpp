#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> ms(m);
  std::vector<int> trans = {-1, 2, 5, 5, 4, 5, 6, 3, 7, 6};
  std::vector<int> nums(9, 0); // 2, 3, 4, 5, 6, 7
  for (int i = 0; i < m; i++) {
    std::cin >> ms[i];
    nums[trans[ms[i]]] = std::max(ms[i], nums[trans[ms[i]]]);
  }
  sort(ms.begin(), ms.end(), std::greater<int>());
  std::vector<int> table(n + 1, -1);
  table[0] = 0;
  for (int i = 1; i <= n; i++) {
    int tmp = -1;
    for (int j = 1; j < 9; j++) {
      if (nums[j] == 0)
        continue;
      if (i - j >= 0) {
        tmp = std::max(tmp, table[i - j] + 1);
      }
    }
    table[i] = tmp;
  }
  std::string ans = "";
  int cur = n;
  for (int i = 0; i < table[n]; i++) {
    for (auto m : ms) {
      if (cur - trans[m] >= 0 && table[cur - trans[m]] == table[cur] - 1) {
        cur -= trans[m];
        ans += std::to_string(m);
        break;
      }
    }
  }
  std::cout << ans << std::endl;
}