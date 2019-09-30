#include <iostream>

int main(int argc, char const *argv[]) {
  int N;
  std::cin >> N;
  char s[50][50];
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      std::cin >> s[i][j];
    }
  }
  for (size_t i = 0; i < N; i++) {
    for (size_t j = 0; j < N; j++) {
      std::cout << s[N-1-j][i];
    }
    std::cout << std::endl;
  }
  return 0;
}