// C - ??
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  long long ans = 0;
  long long c;
  vector<int> v(1000000);

  for (int i=0; i<N; i++) {
    cin >> v[i];
  }

  for (int i=0; i<K; i++) {
    ans += v[i];
    c = ans;
  }

  for (int i=1; i<N-K+1; i++) {
    c = c - v[i-1] + v[i-1+K];
    ans += c;
  }

  cout << ans << endl;

  return 0;
}