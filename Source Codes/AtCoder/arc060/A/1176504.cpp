#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
struct edge { int u, v; ll w; };
 
ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
long ans[51][51][50 * 50 + 1];

int main() {
  int N, A;
  cin >> N >> A;
  vector<int> x(N);
  for (int i = 0; i < N; i++)
    cin >> x[i];

  fill(ans[0][0], ans[51][0], 0);
  ans[0][0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      for (int k = 0; k < N * 50 + 1; k++) {
        ans[i + 1][j + 1][k + x[i]] += ans[i][j][k];
        ans[i + 1][j][k] += ans[i][j][k];
      }
    }
  }

  long result = 0;
  for (int i = 1; i <= N; i++) {
    result += ans[N][i][i * A];
  }
  cout << result << endl;
  return 0;
}