#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int A = 0;
  int B = 0;
  std::cin >> A >> B;
  int Wa = A + B;
  int Sa = A - B;
  int Seki = A * B;

  int Max = log(0);
  if (Max < Wa) {
    Max = Wa;
  }
  if (Max < Sa) {
    Max = Sa;
  }
  if (Max < Seki) {
    Max = Seki;
  }

  std::cout << Max << std::endl;
  return 0;
}