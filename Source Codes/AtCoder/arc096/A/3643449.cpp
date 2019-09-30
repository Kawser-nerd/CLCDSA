#include <iostream>
using namespace std;

int main() {
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  int yen;
  if (A + B > C * 2) {
    int num = min(X, Y); X -= num; Y -= num;
    yen = C * num * 2;
  } else {
    yen = 0;
  }
  yen += min(A, C * 2) * X;
  yen += min(B, C * 2) * Y;
  cout << yen << "\n";
  return 0;
}