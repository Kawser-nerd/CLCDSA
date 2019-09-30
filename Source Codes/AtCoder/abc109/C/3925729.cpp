#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
  if (b > a)
    return gcd(b, a);
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}

int main() {
  int N, X;
  cin >> N >> X;

  int tmp;
  vector<int> dif(N);
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    dif[i] = abs(tmp - X);
  }

  int ans = dif[0];
  for (int i = 1; i < dif.size(); i++) {
    ans = gcd(ans, dif[i]);
  }

  cout << ans << endl;
  return 0;
}