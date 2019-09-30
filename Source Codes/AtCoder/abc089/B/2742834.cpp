#include <iostream>
#include <set>

int main() {
  int N;
  std::cin >> N;

  std::set<char> s;

  for (int i = 0; i < N; i++) {
    char S;
    std::cin >> S;
    s.insert(S);
  }

  std::cout << (s.size() < 4 ? "Three" : "Four") << std::endl;
}