#include <iostream>
using namespace std;

int main() {
  int N, D, X;
  cin >> N >> D >> X;
  int ans = N + X;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    ans += (D-1) / a;
  }
  cout << ans << endl;
}