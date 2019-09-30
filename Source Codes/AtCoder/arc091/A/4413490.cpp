#include <iostream>
#define rep(i, n) for (lli i = 0; i < (n); i++)
#define rrep(i, n) for (lli i = (n)-1; i >= 0; i--)
using namespace std;
using lli = long long int;

int main() {
  lli n, m;
  cin >> n >> m;
  if (n < m)
    swap(n, m);
  if (n == 1 && m == 1) {
    cout << 1 << endl;
  } else if (m == 1) {
    cout << n - 2 << endl;
  } else if (m == 2) {
    cout << 0 << endl;
  } else {
    cout << (n - 2) * (m - 2) << endl;
  }
}