#include <string>
#include <iostream>
#include <vector>
#include <iomanip>
#define range(i, r) for(int i=0;i<r;i++)
using namespace std;
int main(int argc, char const *argv[]) {
  double T, X;
  std::cin >> T >> X;
  std::cout << fixed << '\n';
  std::cout << setprecision(10) <<(double)T/X << '\n';
  return 0;
}