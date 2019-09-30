#include <iostream>
#include <vector>
using namespace std;
#define print(var) cout << fixed << var << endl
int main() {
  int N, K;
  double rate = 0;
  cin >> N >> K;
  vector<int> R(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> R[i];
  }
  sort(R.begin(), R.end(), greater<int>());
  for (int i = 0; i < K; i++) {
    rate += R[K - i - 1];
    rate /= 2;
  }
  print(rate);
}