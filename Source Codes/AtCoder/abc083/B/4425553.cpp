#include <iostream>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  int total{};
  for (int i{1}; i <= N; ++i) {
    int sum{};
    for (int j{i}; j > 0; j /= 10) {
      sum += j % 10;
    }
    if (A <= sum && sum <= B)
      total += i;
  }
  cout << total << endl;
  return 0;
}