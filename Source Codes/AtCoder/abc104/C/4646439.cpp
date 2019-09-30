#include <iostream>
#include <cmath>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  int d, g;
  cin >> d >> g;
  int p[d], c[d];
  for (int i=0; i<d; i++) {
    int pi, ci;
    cin >> pi >> ci;
    p[i] = pi;
    c[i] = ci;
  }
  int ans = INF;
  for (int i=0; i<(1<<d); i++) {
    int tmp_score = 0;
    int num_problem = 0;
    int max_unsolved = 0;
    for (int j=0; j<d; j++) {
      if ((i>> j) & 1) {
        tmp_score += 100 * (j+1) * p[j] + c[j];
        num_problem += p[j];
      } else {
        max_unsolved = j;
      }
    }
    if (tmp_score >= g) {
      ans = min(ans, num_problem);
      continue;
    }
    int s = 100 * (max_unsolved + 1);
    int need = (g - tmp_score - 1) / s + 1;
    if (need >= p[max_unsolved]) {
      continue;
    }
    ans = min(ans, num_problem + need);
  }
  cout << ans;

}