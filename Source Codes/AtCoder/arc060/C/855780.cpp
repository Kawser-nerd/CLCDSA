#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100000;
const int T = 19; // log N
int x[N];
int m[N][T]; // ?i??2^j???????????????
int n;
int l;

int solve(int a, int b) {
  for(int i = 0; i < T; i++) {
    if(m[a][i] >= b) {
      if(i == 0) return 1;
      return solve(m[a][i - 1], b) + (1 << (i - 1));
    }
  }
  for(;;);
  return -1;
}


int main() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> x[i];
  }
  cin >> l;
  for(int i = 0; i < n; i++) {
    int index = lower_bound(x, x + n, x[i] + l + 1) - x; // ??????????
    m[i][0] = index - 1;
  }
  for(int t = 0; t < T - 1; t++) {
    for(int i = 0; i < n; i++) {
      m[i][t + 1] = m[m[i][t]][t];
    }
  }
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) {
    int a, b;
    cin >> a >> b;
    cout << solve(min(a, b) - 1, max(a, b) - 1) << endl;
  }
  return 0;
}