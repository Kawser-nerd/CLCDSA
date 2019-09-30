#include <iostream>

int main() {
  int A, B, C, X;
  std::cin >> A >> B >> C >> X;

  int answer = 0;
  
  for (int a = 0; a <= A; a++) {
    for (int b = 0; b <= B; b++) {
      for (int c = 0; c <= C; c++) {
        answer += (X == 500 * a + 100 * b + 50 * c);
      }
    }
  }

  std::cout << answer << std::endl;
}