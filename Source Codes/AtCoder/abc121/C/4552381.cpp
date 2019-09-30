#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

const int INF = 1e9;

int main() {
  ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<tuple<long, long>> v;
  for (int i=0; i<n; i++) {
    long a, b;
    cin >> a >> b;
    v.push_back(make_tuple(a, b));
  }
  sort(v.begin(), v.end());
  int n_drink = 0;
  long long money = 0;
  for (vector<tuple<long, long>>::iterator it=v.begin(); it!=v.end(); ++it) {
    long long a = get<0>(*it);
    long long b = get<1>(*it);
    if (n_drink + b >= m) {
      money += a * (m - n_drink);
      break;
    }
    money += a * b;
    n_drink += b;
  }
  cout << money;
}