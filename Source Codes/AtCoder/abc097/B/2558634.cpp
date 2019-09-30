#include <iostream>
using namespace std;

int main() {
  int X;
  cin >> X;

  int answer = 1;

  for (int b = 2; b <= X; b++) {
    int bp = b * b;

    for (int i = 0; bp <= X; bp *= b) {
      answer = max(answer, bp);
    }
  }

  cout << answer << endl;
}