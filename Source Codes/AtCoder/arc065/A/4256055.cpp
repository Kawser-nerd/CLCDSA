#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

int main() {
  std::string S;
  std::cin >> S;

  std::vector<std::string> t{"dream", "dreamer", "erase", "eraser"};

  while (!S.empty()) {
    bool updated = false;
    for (const auto& ti: t) {
      if (S.length() < ti.length()) continue;
      if (S.compare(S.length()-ti.length(), ti.length(), ti) != 0) continue;

      for (size_t i = 0; i < ti.length(); ++i) S.pop_back();
      updated = true;
      break;
    }
    if (!updated) break;
  }

  if (S.empty()) {
    std::cout << "YES" << std::endl;
  } else {
    std::cout << "NO" << std::endl;
  }
}