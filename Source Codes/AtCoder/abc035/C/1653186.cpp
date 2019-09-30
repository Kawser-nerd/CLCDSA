#include <iostream>
#include <vector>

int main() {
  std::cin.sync_with_stdio(false);

  int N, Q;
  std::cin >> N >> Q;

  std::vector<int> imos(N+1, 0);  

  for (int i = 0; i < Q; i++) {
    int li, ri;
    std::cin >> li >> ri;
    li -= 1;
    ri -= 1;
    imos[li] += 1;
    imos[ri + 1] -= 1;
  }
 
  int accum = 0;
  for (int i = 0; i < N; i++) {
    accum += imos[i];
    int flip = accum & 1;
    std::cout << flip;
  }
  std::cout << std::endl; 
  return 0;
}