// Last Change:                12/13/2018 23:34:35.
#include <algorithm>
#include <array>
#include <cmath>
#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>
using namespace std;
using ll = long long;

void LoopUntilZeroInpput() {
  int hogegegege = 0;
  while (cin >> hogegegege && hogegegege != 0) {
  }
}

int N;
ll a[50];

ll Cal(ll ans) {
  bool finish = true;
  for (int i = 0; i < N; i++) {
    if (a[i] >= N) {
      finish = false;
    }
  }
  if (finish) {
    return ans;
  }

  ll sum = 0;
  for (int i = 0; i < N; i++) {
    ll hoge = a[i] / N;
    a[i] -= hoge * N;
    sum += hoge;
    a[i] -= hoge;
  }
  for (int i = 0; i < N; i++) {
    a[i] += sum;
  }
  ans += sum;
  ans = Cal(ans);
  return ans;
}

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  sort(a, a + N);
  ll ans = Cal(0);
  cout << ans << endl;
}