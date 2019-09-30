#include <algorithm>
#include <iostream>
using namespace std;
int main() {
  int A = 0;
  int B = 0;
  std::cin >> A >> B;
  int C = max(A + B, A - B);
  cout << max(C, A * B) << std::endl;
  return 0;
}