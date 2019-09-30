#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define rep(i, n) for (int(i) = 0; (i) < (n); (i)++)

int main() {
  int N;
  cin >> N;
  vector<int> t(N);
  rep(i, N) cin >> t[i];

  sort(t.begin(), t.end(), greater<int>());

  int ret[2]{0, 0};
  rep(i, N) {
    if (ret[0] < ret[1]) {
      ret[0] += t[i];
    } else {
      ret[1] += t[i];
    }
  }

  cout << max(ret[0], ret[1]) << endl;

  return 0;
}