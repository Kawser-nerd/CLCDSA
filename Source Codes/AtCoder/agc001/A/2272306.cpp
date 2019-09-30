#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, n) for (long(i) = 0; (i) < (n); (i)++)
#define sort(s) sort(s.begin(), s.end(), greater<int>())
using namespace std;
int main() {
  int n, count = 0;
  cin >> n;
  vector<int> a(2 * n);
  REP(i, 2 * n) cin >> a[i];
  sort(a);
  REP(i, 2 * n) {
    if (i % 2 == 1)
      count += a[i];
  }
  cout << count << endl;
  return 0;
}