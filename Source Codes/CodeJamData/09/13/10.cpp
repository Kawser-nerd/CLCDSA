#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

typedef long long int LL;

LL choose[41][41] = {0};

int main() {
  choose[0][0] = 1;
  for (int n = 1; n <= 40; ++n) {
    choose[n][0] = choose[n][n] = 1;
    for (int k = 1; k < n; ++k)
      choose[n][k] = choose[n-1][k] + choose[n-1][k-1];
    }
  int T; cin >> T;
  for (int cc = 1; cc <= T; ++cc) {
    int C, N; cin >> C >> N;
    double expect[41];
    expect[C] = 0;
    for (int x = C-1; x >= 0; --x) {
      expect[x] = 0;
      int a = max(N-x, 0), b = min(N, C-x);
      double den = choose[C][N];
      if (!a) {
        den -= choose[x][N];
        expect[x] += choose[x][N]/den;
        ++a;
        }
      for (int i = a; i <= b; ++i) {
        double m = choose[x][N-i];
        m /= den;
        m *= choose[C-x][i];
        expect[x] += m*(expect[x+i] + 1);
        }
      }
    cout << "Case #" << cc << ": " << fixed << setprecision(7) << expect[0] << '\n';
    }
  }