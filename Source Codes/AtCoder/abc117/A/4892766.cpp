#include <string>
#include <iostream>
#include <vector>
#define range(i, r) for(int i=0;i<r;i++)
using namespace std;
int main(int argc, char const *argv[]) {
  double T, X;
  std::cin >> T >> X;
  std::cout << (double)T/X << '\n';
  return 0;
}