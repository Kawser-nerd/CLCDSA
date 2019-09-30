#include <iostream>
using namespace std;

int main() {
  int N, Y;
  cin >> N >> Y;

  for (int x{}; x <= N; ++x) {
    for (int y{}; y <= N-x; ++y) {
      int z = N - x - y;
      if (x * 10000 + y * 5000 + z * 1000 == Y) {
        cout << x << " " << y << " " << z << endl;
        return 0;
      }
    }
  }

  cout << "-1 -1 -1" << endl;
  return 0;
}