#include <iostream>
#include <string>
#include <vector>
using namespace std;

int get_unique_long(std::vector<int> &Vec) {
  std::sort(Vec.begin(), Vec.end());
  Vec.erase(std::unique(Vec.begin(), Vec.end()), Vec.end());
  return Vec.size();
}

int main() {
  int N = 0;
  std::cin >> N;
  std::vector<int> D_vec(N, 0);

  for (int i = 0; i < N; i++) {
    int a = 0;
    std::cin >> a;
    D_vec[i] = a;
  }

  std::cout << get_unique_long(D_vec) << std::endl;
  return 0;
}