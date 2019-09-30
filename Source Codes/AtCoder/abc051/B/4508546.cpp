#include <iostream>
#include <cmath>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  int k, s;
  cin >> k >> s;
  int cnt = 0;
  for (int x=0; x<=k; x++) {
    for (int y=0; y<=k; y++) {
      int z = s - x - y;
      if (z >= 0 && z <= k) {
        cnt += 1;
      } else if (z < 0) {
        break;
      }
    }
  }
  cout << cnt;

}