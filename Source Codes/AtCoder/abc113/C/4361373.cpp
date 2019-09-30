#include <iostream>
#include <iomanip>
using namespace std;

struct D {
  int i;
  int p;
  int y;
  int c;
};

constexpr int MAX_M = 100000;
D d[MAX_M];

int main() {
  int N, M;
  cin >> N >> M;
  for (int i{}; i < M; ++i) {
    d[i].i = i + 1;
    cin >> d[i].p >> d[i].y;
  }
  sort(d, d + M, [](D l, D r) {
    if (l.p == r.p)
      return l.y < r.y;
    return l.p < r.p;
  });

  int p{};
  int counter{};
  for (int i{}; i < M; ++i) {
    if (p != d[i].p) {
      p = d[i].p;
      counter = 0;
    }
    d[i].c = ++counter;
  }
  sort(d, d + M, [](D l, D r) {
    return l.i < r.i;
  });

  cout << setfill('0');
  for (int i{}; i < M; ++i) {
    cout << setw(6) << d[i].p << setw(6) << d[i].c << endl;
  }

  return 0;
}