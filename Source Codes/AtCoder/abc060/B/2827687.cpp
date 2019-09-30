#include <iostream>

using namespace std;

int main() {
  int A, B, C;

  cin >> A >> B >> C;
  int sum = 0;
  for (int i = 0; i <= 100; i++) {
    sum += A;
    int remainder = sum % B;

    if (remainder == C) {
      cout << "YES" << endl;
      return 0;
      //cout << sum << "," << remainder << "[got]" <<endl;
    } else {
      //cout << sum << "," << remainder << endl;
    }
  }
  cout << "NO" << endl;
}