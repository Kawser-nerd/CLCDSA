// Last Change: 03/07/2019 19:38:17.
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

int N, A, B, C;
vector<int> l;
const int INF = 1000000000;

//?a,b,c?A,B,C????
// pos??????A,B,C????????????????
int dfs(int pos, int a, int b, int c) {
  int ans = INF;
  if (pos == N) {
    if (a > 0 and b > 0 and c > 0) {
      //???a,b,c??????????A,B,C?????????
      ans = abs(a - A) + abs(b - B) + abs(c - C) - 30;
      return ans;
    } else {
      return INF;
    }
  }
  int next = pos + 1;
  int tmp = dfs(next, a, b, c);
  ans = min(ans, tmp);
  tmp = dfs(next, a + l[pos], b, c) + 10;
  ans = min(ans, tmp);
  tmp = dfs(next, a, b + l[pos], c) + 10;
  ans = min(ans, tmp);
  tmp = dfs(next, a, b, c + l[pos]) + 10;
  ans = min(ans, tmp);
  return ans;
}

int main() {
  cin >> N >> A >> B >> C;
  l.resize(N);
  for (int i = 0; i < N; ++i) {
    cin >> l[i];
  }

  int ans = dfs(0, 0, 0, 0);
  cout << ans << endl;

  //NS::LoopUntilZeroInpput();
}