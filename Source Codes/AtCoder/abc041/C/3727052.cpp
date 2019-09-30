// Last Change:             12/06/2018 18:47:39.
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

int main() {
  ll students[100000];
  int N;
  cin >> N;
  ll input;
  for (int i = 0; i < N; i++) {
    cin >> input;
    students[i] = input * 100000 + i;
  }
  sort(students, students + N);
  ll ans;
  for (int i = N - 1; i >= 0; i--) {
    ans = (students[i] % 100000) + 1;
    cout << ans << '\n';
  }
  cout << flush;
}