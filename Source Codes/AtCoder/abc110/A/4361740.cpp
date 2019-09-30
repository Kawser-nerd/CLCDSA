#include<iostream>
using namespace std;

int main() {
  int d[3];

  for (int i{}; i < 3; ++i) {
    cin >> d[i];
  }
  sort(d, d+3);
  int ans = d[2] * 10 + d[1] + d[0];

  cout << ans << endl;
  return 0;
}