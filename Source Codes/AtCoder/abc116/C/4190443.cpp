#include <iostream>
using namespace std;

int main () {
  int n;
  cin >> n;
  int h[n];
  for (int i = 0; i < n; i++) {
    cin >> h[i];
  }
  long long ans = 0;
  for (int num = 0; num <= 100; num++) {
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (h[i] == 0) {
        ok = false;
      }
      else {
        if (ok == false) {
          ans++;
          ok = true;
        }
        h[i]--;
      }
    }
  }
  cout << ans << endl;
}