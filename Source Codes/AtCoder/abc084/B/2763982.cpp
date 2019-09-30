#include <iostream>
#include <string>

int main() {
  int A, B;
  std::string S;
  std::cin >> A >> B >> S;

  auto f = [](int A, int B, std::string S) {
    for (int i = 0; i < A; i++) {
      if (S[i] < '0' || S[i] > '9') {
        return false;
      }
    }

    if (S[A] != '-') {
      return false;
    }

    for (int i = 0; i < B; i++) {
      if (S[A+i+1] < '0' || S[A+i+1] > '9') {
        return false;
      }
    }

    return true;
  };

  std::cout << (f(A, B, S) ? "Yes" : "No") << std::endl;
}