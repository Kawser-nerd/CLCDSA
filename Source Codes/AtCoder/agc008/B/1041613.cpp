#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<long> a;
int N, K;

long solve() {
  long answer = 0;
  for(long aa: a) answer += aa > 0 ? aa : 0;
  long z_sum = 0, sum = 0;
  long ret = 0;
  for(int i = 0; i < K; i++) {
    z_sum += max(0L, a[i]);
    sum += a[i];
  }
  for(int i = 0; i <= N - K; i++) {
    ret = max(ret, answer - z_sum);
    ret = max(ret, answer - z_sum + sum);
    if(i == N - K) break;
    z_sum -= max(0L, a[i]);
    z_sum += max(0L, a[i + K]);
    sum -= a[i];
    sum += a[i + K];
  }
  return ret;
}

int main() {
  cin >> N >> K;
  a = vector<long>(N);
  for(auto &aa: a) cin >> aa;
  long ans = solve();
  cout << ans << endl;
  return 0;
}