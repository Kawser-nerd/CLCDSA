#include <iostream>
#include <algorithm>
#include <string>

int main() {
  std::string S;
  std::cin >> S;

  for (char c = 'a'; c <= 'z'; ++c)
    if (std::count(S.begin(), S.end(), c) == 0)
      return !printf("%c\n", c);

  puts("None");
}