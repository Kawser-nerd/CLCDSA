#include <iostream>
#include <cmath>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  int n, m, c;
  cin >> n >> m >> c;

  int b[m];
  for (int j=0; j<m; j++) {
    cin >> b[j];
  }
  int cnt = 0;
  for (int i=0; i<n; i++) {
    int tmp = 0;
    for (int j=0; j<m; j++) {
      int aj;
      cin >> aj;
      tmp += b[j] * aj;
    }
    if (tmp + c > 0) {
       ++cnt;
    }
  }
  cout << cnt;

}