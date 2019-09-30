#include <iostream>
#include <set>
using namespace std;

int main() {
  int T;
  int N;
  cin >> T >> N;

  multiset<int> A;
  for (int i = 0; i < N; ++i) {
    int a;
    cin >> a;
    A.insert(a);
  }

  int M;
  cin >> M;

  for (int i = 0; i < M; ++i) {
    int B;
    cin >> B;

    auto sell_it = A.lower_bound(B - T);
    if (sell_it != A.end() && *sell_it <= B) {
      // ???????
      A.erase(sell_it);
    } else {
      // ?????????
      cout << "no" << endl;
      return 0;
    }
  }

  // ??????????
  cout << "yes" << endl;
}