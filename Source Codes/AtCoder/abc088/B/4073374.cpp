#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, tmp;
  vector<int> v;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end(), greater<int>());

  int alice = 0;
  int bob = 0;
  for (int i = 0; i < (int)v.size(); i++) {
    if (i % 2 == 0) {
      alice += v[i];
    } else {
      bob += v[i];
    }
  }

  cout << alice - bob << endl;
  return 0;
}