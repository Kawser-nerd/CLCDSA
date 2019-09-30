#include <iostream>
#include <string>

int main() {
  std::string S;
  size_t K;
  std::cin >> S >> K;

  for (size_t i = 0; i < K; ++i)
    if (S[i] != '1')
      return (std::cout << S[i] << std::endl), 0;

  std::cout << '1' << std::endl;
}