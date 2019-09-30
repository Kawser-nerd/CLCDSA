#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  for (int i = 1; i < 10; i++) {
    int k = i * 100 + i * 10 + i;
    if (k >= N) {
      cout << k << endl;
      break;
    }
  }
  return 0;
}