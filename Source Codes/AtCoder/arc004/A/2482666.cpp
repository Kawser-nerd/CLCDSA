#include <iostream>
#include <vector>
#include <utility>
#include <cmath>

using namespace std;

double len(pair<int, int> a, pair<int, int> b) {
  int dx = a.first - b.first;
  int dy = a.second - b.second;
  return sqrt(dx * dx + dy * dy);
}

int main(void) {
  int N;
  cin >> N;
  vector<pair<int,int> > p(N);

  for(auto &x : p) {
    cin >> x.first >> x.second;
  }

  double max = 0;
  for(int i = 0; i < N - 1; i++) {
    for(int j = i + 1; j < N; j++) {
      double nowlen = len(p[i], p[j]);
      max = max <= nowlen ? nowlen : max;
    }
  }

  cout << max << endl;

    return 0;
}