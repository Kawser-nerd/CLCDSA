#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N, K;
  while (cin >> N >> K) {

    vector<int> v;
    v.resize(N);
    for (int i = 0; i < N; ++i) cin >> v[i];
    int res = 0;
    int right = 0;
    while (true) {
      if (res == 0) right += K;
      else right += K-1;
      ++res;

      if (right >= N) break;
    }
    cout << res << endl;
  }
}