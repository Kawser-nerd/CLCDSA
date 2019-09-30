// Last Change: 02/21/2019 20:28:27.
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

namespace NS {
void LoopUntilZeroInpput() {
  int hogegegege = 0;
  while (cin >> hogegegege && hogegegege != 0) {
  }
}
} // namespace NS

class Cal {
private:
  int N, K;
  string ans = "Nothing";
  vector<vector<int>> T;

private:
  void Input() {
    cin >> N >> K;
    T.reserve(N);
    for (int i = 0; i < N; ++i) {
      vector<int> ipt(K);
      for (int j = 0; j < K; ++j) {
        cin >> ipt[j];
      }
      T.push_back(ipt);
    }
  }
  void Rep(int depth, int prevNum) {
    if (depth == N) {
      if (prevNum == 0) {
        ans = "Found";
      }
      return;
    }
    int nextDepth = depth + 1;
    for (int i = 0; i < K; ++i) {
      Rep(nextDepth, prevNum ^ T[depth][i]);
    }
  }
  void Output() {
    cout << ans << endl;
  }

public:
  Cal() {
    Input();
    Rep(0, 0);
    Output();
  }
};

int main() {
  unique_ptr<Cal> hoge(new Cal());

  //NS::LoopUntilZeroInpput();
}