#include <iostream>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))

int main() {
  int A, B, C, X, Y; cin >> A >> B >> C >> X >> Y;
  int yen;
  if (A + B > C * 2) {
    int num = MIN(X, Y); X -= num; Y -= num;
    yen = C * num * 2;
  } else {
    yen = 0;
  }
  yen += MIN(A, C * 2) * X;
  yen += MIN(B, C * 2) * Y;
  cout << yen << "\n";
  return 0;
}