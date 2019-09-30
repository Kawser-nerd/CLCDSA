#include <iostream>

using namespace std;

int main(void) {

  int num = 0;
  int N;
  int A;
  int B;

  cin >> N >> A >> B;

  while (true) {
    if (A + 1 != B) {
      A = A + 1;
      ++num;
    } else {
      if (A == 1) {
        cout << "Borys" << endl;
        return 0;
      } else {
        A = A - 1;
        ++num;
      }
    }

    if (B - 1 != A) {
      B = B - 1;
      ++num;
    } else {
      if (B == N) {
        cout << "Alice" << endl;
        return 0;
      } else {
        B = B + 1;
        ++num;
      }
    }

    if (num > 1000) {
      cout << "Draw" << endl;
      return 0;
    }
    
  }
}