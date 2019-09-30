#include <iostream>
using namespace std;

int n;
int x[110], y[110], v[110];

int absv(int x) { return x > 0 ? x : -x; }

int getv(int i, int j, int x1, int x2) {
  int mv = max(absv(i-x1), absv(j-x2));
  return mv % 2;
}

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    cin >> n;
    for (int i = 0; i < n; i++) {
      char cc; cin >> x[i] >> y[i] >> cc;
      // x[i] = i; y[i] = i; char cc = '.';
      v[i] = cc == '.' ? 0 : 1;
    }

    int bi = 1000000, bj = 1000000;
    for (int i = 400; i >= -400; i--)
      for (int j = 400; j >= -400; j--) {
        bool ok = true;
        for (int k = 0; k < n; k++)
          if (getv(i, j, x[k], y[k]) != v[k]) {
            ok = false;
            break;
          }

        if (ok && absv(i) + absv(j) < absv(bi) + absv(bj)) { bi = i; bj = j; }
      }

    cout << "Case #" << c << ": ";
    if (bi == 1000000) cout << "Too damaged" << endl;
    else cout << bi << " " << bj << endl;
  }
  return 0;
}
