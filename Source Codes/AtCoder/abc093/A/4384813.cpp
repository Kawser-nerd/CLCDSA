#include <iostream>
#include <string>
#include <algorithm>

int main() {
  std::string S;
  std::cin >> S;
  std::sort(S.begin(), S.end());
  if (S == "abc") {
    std::cout << "Yes\n";
  } else {
    std::cout << "No\n";
  }
}