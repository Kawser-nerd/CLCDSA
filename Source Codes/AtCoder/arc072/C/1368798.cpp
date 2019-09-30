#include <iostream>
#include <vector>

int main() {
  unsigned N, D;
  std::cin >> N >> D;
  std::vector<unsigned> d(N + 1);
  for (unsigned i = 1; i < N + 1; ++i) {
    std::cin >> d[i];
  }
  unsigned Q;
  std::cin >> Q;
  std::vector<unsigned> q(Q);
  for (unsigned i = 0; i < Q; ++i) {
    std::cin >> q[i];
  }
  std::vector<unsigned> unreachable(N + 2);
  unreachable[N + 1] = 1;
  for (unsigned i = N; i > 0; --i) {
    if (unreachable[i + 1] * 2 > d[i]) {
      unreachable[i] = unreachable[i + 1] + d[i];
    } else {
      unreachable[i] = unreachable[i + 1];
    }
  }
  std::vector<bool> ok(N + 1);
  unsigned pos = D;
  for (unsigned i = 1; i <= N; ++i) {
    ok[i] = unreachable[i + 1] <= pos;
    if (pos >= d[i]) { pos -= d[i]; }
    else if (d[i] - pos < pos) { pos = d[i] - pos; }
  }
  for (unsigned i = 0; i < Q; ++i) {
    std::cout << (ok[q[i]] ? "YES" : "NO") << std::endl;
  }
  return 0;
}