#include <iostream>
using namespace std;

int main() {
  int K;
  cin >> K;

  if (K & 1) {
    cout << (K - 1) * (K + 1) / 4 << endl;
  } else {
    cout << K * K / 4 << endl;
  }

  return 0;
}