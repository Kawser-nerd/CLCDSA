#include <iostream>
#include <string>

int main() {
  size_t A, B;
  std::cin >> A >> B;

  std::string S;
  std::cin >> S;

  for (size_t i = 0; i < S.length(); ++i)
    if ((S[i] == '-') ^ (i == A))
      return (std::cout << "No" << std::endl), 0;

  std::cout << "Yes" << std::endl;
}