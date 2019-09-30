#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  std::string S, T;
  std::cin >> S >> T;

  std::vector<std::vector<size_t>> si(26), ti(26);
  for (size_t i = 0; i < S.length(); ++i) {
    si[S[i]-'a'].push_back(i);
    ti[T[i]-'a'].push_back(i);
  }

  std::sort(si.begin(), si.end());
  std::sort(ti.begin(), ti.end());
  if (si == ti) {
    std::cout << "Yes" << std::endl;
  } else {
    std::cout << "No" << std::endl;
  }
}