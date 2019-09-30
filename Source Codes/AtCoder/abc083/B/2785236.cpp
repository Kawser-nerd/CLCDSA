#include <iostream>

int main() {
  int N, A, B;
  std::cin >> N >> A >> B;

  int answer = 0;

  for (int i = 1; i <= N; i++) {
    int s = 0;

    for (int j = i; j > 0; j /= 10) {
      s += j % 10;
    }

    if (A <= s && s <= B) {
      answer += i;
    }
  }

  std::cout << answer << std::endl;
}