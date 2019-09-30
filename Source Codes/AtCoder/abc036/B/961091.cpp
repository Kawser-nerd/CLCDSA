#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>

int main() {
  int N;
  std::cin >> N;

  std::vector<std::string> a(N, "");
  std::vector<std::string> res(N, "");

  for (int i = 0; i < N; i++) {
    std::string tmp;
    std::cin >> tmp;

    a[i] = tmp;
    res[i] = tmp;
  }

  std::cout << " " << std::endl;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      res[j][N-i-1] = a[i][j];
    }
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      std::cout << res[i][j];
    }
    std::cout << "\n";
  }
  
  return 0;
}