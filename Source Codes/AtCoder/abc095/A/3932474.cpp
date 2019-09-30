#include <iostream>

char buf[80];

int main() {
  std::cin >> buf;
  int ans = 700;
  for (int i = 0; i < 3; i++) {
    if (buf[i] == 'o') {
      ans += 100;
    }
  }

  std::cout << ans << std::endl;
}