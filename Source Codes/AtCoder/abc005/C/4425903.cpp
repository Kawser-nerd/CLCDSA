#include <iostream>
#include <queue>
using namespace std;

int main() {
  int T;
  cin >> T;
  int N;
  cin >> N;
  queue<int> A;
  for (int i{}; i < N; ++i) {
    int a;
    cin >> a;
    A.push(a);
  }
  int M;
  cin >> M;
  int B[M];
  for (int i{}; i < M; ++i)
    cin >> B[i];

  bool ans{N >= M};
  if (!ans) {
    goto END;
  }

  for (const auto& b : B) {
    while (!A.empty()) {
      int a = A.front();
      A.pop();
      if (a <= b && b <= a + T) {
        goto NEXT;
      }
    }
    ans = false;
    break;
NEXT:
    ;
  }

END:
  cout << (ans ? "yes" : "no") << endl;
  return 0;
}