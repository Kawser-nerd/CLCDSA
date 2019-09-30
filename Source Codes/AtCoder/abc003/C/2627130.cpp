#include <iostream>
#include <iterator>
#include <set>
#include <iomanip>

using namespace std;

int main() {
  int N, K;
  multiset<int> sorted_rates;

  cin >> N >> K;

  for (int i = 0; i < N; ++i) {
    int tmp;
    cin >> tmp;
    sorted_rates.insert(tmp);
  }

  long double C = 0;
  auto it_begin = end(sorted_rates);
  advance(it_begin, -K);
  for (auto it = it_begin; it != end(sorted_rates); ++it) {
    C = (C + *it) / 2.0;
  }

  cout << fixed << setprecision(7) << C << endl;
}