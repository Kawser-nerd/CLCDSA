#include <iostream>
#include <set>

int main() {
  int N;
  std::cin >> N;

  std::set<char> s;
  for (int i = 0; i < N; ++i) {
    char S;
    std::cin >> S;
    s.insert(S);
  }
  if (s.size() == 3) {
    std::cout << "Three" << std::endl;
  } else {
    std::cout << "Four" << std::endl;
  }
}