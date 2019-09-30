// Last Change: 03/25/2019 23:12:41.
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

int main() {
  int N;
  string S;
  cin >> N >> S;

  int ans = 0;
  for (int i = 1; i < N; ++i) {
    vector<char> X;
    string Y;
    for (int j = 0; j < i; ++j) {
      X.push_back(S[j]);
    }
    sort(X.begin(), X.end());
    Y = S.substr(i, N - i);

    char lastChar = 'a'; //??
    int tmpAns = 0;
    for (int j = 0; j < i; ++j) {
      if (j == 0 or lastChar != X[j]) {
        lastChar = X[j];
        for (int k = 0; k < N - i; ++k) {
          if (X[j] == Y[k]) {
            ++tmpAns;
            break;
          }
        }
        ans = max(ans, tmpAns);
      }
    }
  }

  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}