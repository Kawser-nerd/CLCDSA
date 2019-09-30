#include <iostream>
#include <set>
#include <algorithm>

int main(int argc, char const *argv[]) {
  int N,A;
  std::cin >> N;
  std::set<int> plices;

  for(int i = 0; i < N; i++){
    std::cin >> A;
    plices.insert(A);
  }

  auto max_itr = std::max_element(plices.begin(), plices.end());
  plices.erase(max_itr, ++max_itr);
  std::cout << *std::max_element(plices.begin(), plices.end()) << '\n';

  return 0;
}