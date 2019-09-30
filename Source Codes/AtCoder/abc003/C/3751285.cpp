#include <iostream>
#include <algorithm>
using namespace std;

int main () {
  int n, k;
  cin >> n >> k;  
  double r[n];
  for (int i = 0; i < n; i++) {
    cin >> r[i];  
  }
  sort(r, r + n);
  double ans = 0;
  for (int i = n - k; i < n; i++) {
    ans = (double) (ans + r[i]) * 0.5;  
  }
  cout << fixed << ans << endl;
}