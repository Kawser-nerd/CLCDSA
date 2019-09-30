#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n, k; cin >> n >> k;
  vector<long> hs(n);
  for (int i = 0; i < n; ++i) {
    cin >> hs[i];
  }

  sort(hs.begin(), hs.end());

  long min = 1000000000;
  for (int i = k - 1; i < n; ++i) {
    long sub = hs[i] - hs[i - k + 1];
    if (sub < min) min = sub;
  }

  cout << min << endl;

  return 0;
}