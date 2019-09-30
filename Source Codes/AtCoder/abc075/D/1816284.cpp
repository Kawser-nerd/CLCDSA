#include <iostream>
using namespace std;

typedef long long ll;
const int N_MAX = 50;
ll X[N_MAX];
ll Y[N_MAX];

int count_point(ll x1, ll y1, ll x2, ll y2, int n) {
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (x1 <= X[i] && x2 >= X[i] &&
	y1 <= Y[i] && y2 >= Y[i]) {
      count++;
    }
  }
  return count;
}

ll solve(int N, int K) {
  ll ans = LLONG_MAX;
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      ll x1 = min(X[i], X[j]);
      ll x2 = max(X[i], X[j]);

      for (int k = 0; k < N; k++) {
	for (int l = k+1; l < N; l++) {
	  ll y1 = min(Y[k], Y[l]);
	  ll y2 = max(Y[k], Y[l]);

	  int c = count_point(x1, y1, x2, y2, N);
	  if (c >= K) {
	    ans = min(ans, (x2-x1)*(y2-y1));
	  }
	}
      }
    }
  }
  return ans;
}

int main() {
  int N, K;
  cin >> N >> K;
  for (int i = 0; i < N; i++) {
    cin >> X[i] >> Y[i];
  }
  cout << solve(N, K) << endl;
}