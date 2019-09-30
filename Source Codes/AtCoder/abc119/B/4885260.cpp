#include <string>
#include <vector>
#include <iostream>

#define range(i, l, r) for(int i=l;i<r;i++)
using namespace std;
int main(int argc, char const *argv[]) {
  int N;
  std::cin >> N;
  double tempx, summ = 0;
  string tempu;
  range(i, 0, N){
    std::cin >> tempx >> tempu;
    (tempu == "JPY")?summ += tempx:summ+= tempx * 380000.0;
  }
  std::cout << summ << '\n';
  return 0;
}