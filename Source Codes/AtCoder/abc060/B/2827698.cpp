#include <iostream>

using namespace std;

int main() {
  int A, B, C;

  cin >> A >> B >> C;
  int sum = 0;
  for (int i = 0; i <= B; i++) {
    sum += A;
    int remainder = sum % B;

    if (remainder == C) {
      //cout << i << "," << sum << "," << remainder << "[got]" <<endl;
      cout << "YES" << endl;
      return 0;
    } else {
      //cout << i << "," << sum << "," << remainder << endl;
    }
  }
  cout << "NO" << endl;
}