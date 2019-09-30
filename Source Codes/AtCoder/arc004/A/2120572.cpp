#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<pair<double, double>> p(N);
  double x, y;
  for (int i = 0; i < N; i++) {
    cin >> x >> y;
    p[i] = make_pair(x, y);
  }

  vector<double> lens;
  for(int i=0; i<N; i++) {
    for (int k=0; k<N; k++) {
      if (i == k) continue;
      lens.push_back(sqrt(pow(p[i].first - p[k].first, 2) + pow(p[i].second - p[k].second, 2)));
    }
  }
  sort(lens.begin(), lens.end(), greater<double>());
  cout << lens[0] << endl;
}