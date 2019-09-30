#include <iostream>
using namespace std;

int f[101][11];
int p[101][12];

int main() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) for (int j = 0; j < 10; j++) cin >> f[i][j];
  for (int i = 0; i < n; i++) for (int j = 0; j < 11; j++) cin >> p[i][j];
  int ans = -(1<<30);
  for (int i = 1; i < (1 << 10); i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      int cnt = 0;
      for (int k = 0; k < 10; k++) if ((i >> k & 1) && f[j][k]) cnt++;
      sum += p[j][cnt];
    }
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}