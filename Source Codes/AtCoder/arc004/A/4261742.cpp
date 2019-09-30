#include <iostream>
#include <cmath>
using namespace std;

using P = pair<double, double>;

P p[100];

int main() {
  int N;
  cin >> N;
  for (int i{}; i < N; ++i) {
    double x, y;
    cin >> x >> y;
    p[i] = P(x, y);
  }

  double longer{};
  for (int i{}; i < N - 1; ++i) {
    for (int j{i + 1}; j < N; ++j) {
      double l = sqrt(pow(p[i].first - p[j].first, 2) +
          pow(p[i].second - p[j].second, 2));
      if (longer < l) {
        longer = l;
      }
    }
  }

  cout << longer << endl;
  return 0;
}