#include <iostream>
#include <vector>
using namespace std;
int main() {
  int A = 0;
  int B = 0;
  int C = 0;
  std::cin >> A >> B >> C;
  std::vector<int> Num(3, 0);
  Num[0] = A;
  Num[1] = B;
  Num[2] = C;
  std::sort(Num.begin(), Num.end());

  std::cout << Num[2] * 10 + Num[1] + Num[0] << std::endl;
}