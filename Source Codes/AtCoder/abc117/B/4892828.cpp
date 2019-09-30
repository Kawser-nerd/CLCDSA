#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;
int main(int argc, char const *argv[]) {
  int N;
  std::cin >> N;
  std::vector<int> L(N);
  for(int i=0;i<N;i++) std::cin >> L[i];
  sort(L.begin(), L.end());
  (L[N - 1] >= accumulate(L.begin(), L.end() - 1, 0)) ? std::cout << "No" << '\n':std::cout << "Yes" << '\n';;
  return 0;
}