#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> vec;
  for (int i = 0; i < N; i++) {
    int tmp = 0;
    cin >> tmp;
    vec.push_back(tmp);
  }
  sort(vec.rbegin(), vec.rend());

  int longest = vec[0];
  int sum = 0;
  for (int i = 1; i < N; i++) {
    sum += vec[i];
  }

  if (longest < sum) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}