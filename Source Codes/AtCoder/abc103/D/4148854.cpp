/**
 * @brief AtCoder Beginner Contest 103<br>
 * D - Islands War
 *
 * ??????????
 * @see https://atcoder.jp/contests/abc103/tasks/abc103_d
 */
#include <iostream>
#include <queue>
using namespace std;

using P = pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;
  auto c = [](P l, P r) {
    return l.first > r.first;
  };
  priority_queue<P, vector<P>, decltype(c)> que(c);
  for (int i{}; i < M; ++i) {
    int a, b;
    cin >> a >> b;
    que.push(P(a, b));
  }
  int ans{1};
  P bp(1, N);
  while (!que.empty()) {
    P p = que.top();
    que.pop();
    P a(max(bp.first, p.first), min(bp.second, p.second));
    if (a.first < a.second) {
      bp = a;
    } else {
      ++ans;
      bp = p;
    }
  }

  cout << ans << endl;
  return 0;
}