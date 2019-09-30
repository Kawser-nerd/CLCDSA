#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int> > data(N);

  for (int i = 0; i < N; i++) {
    int K;
    cin >> K;
    data[i].reserve(K);

    for (int j = 0; j < K; j++) {
      int f;
      cin >> f;
      data[i].push_back(f);
    }
    // sort(data[i].begin(), data[i].end());
  }

  int result = 0;
  for (int i = 1; i <= M; i++) {
    bool ok = true;
    for (auto &d : data) {
      bool found = false;
      for (auto &n : d) {
        if (n == i) {
          found = true;
          break;
        }
      }
      if (!found) {
        ok = false;
        break;
      }
    }
    if (ok) {
      result++;
    }
  }

  cout << result << endl;

}