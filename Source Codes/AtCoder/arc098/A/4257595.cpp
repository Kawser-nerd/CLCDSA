#include <iostream>
#include <string>
#include <algorithm>

int main() {
  size_t N;
  std::string S;
  std::cin >> N >> S;

  size_t left = 0;
  size_t right = std::count(S.begin()+1, S.end(), 'E');
  size_t res = right;
  for (size_t i = 1; i < N; ++i) {
    if (S[i] == 'E') --right;
    if (S[i-1] == 'W') ++left;
    res = std::min(res, left+right);
  }
  std::cout << res << std::endl;
}