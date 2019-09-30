#include <iostream>
using namespace std;

/**
 * @brief 0??x???????????????<br>
 * B??A????????xorial(B) ^ xorial(A-1)?????
 */
template<typename T = int>
T xorial(T x) {
  T result{};
  T start{x - x % 4};
  for (T i{start}; i <= x; ++i) {
    result ^= i;
  }
  return result;
}

int main() {
  long A, B;
  cin >> A >> B;

  cout << (xorial(B) ^ xorial(A - 1)) << endl;
  return 0;
}