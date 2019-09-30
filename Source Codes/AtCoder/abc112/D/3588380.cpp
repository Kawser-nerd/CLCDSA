#include <iostream>

using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  int r = M / N, res = -1;
  while(true) {
    if (M % r == 0) {
      res = r;
      break;
    }
    r--;
  }

  cout << res << endl;

  return 0;
}