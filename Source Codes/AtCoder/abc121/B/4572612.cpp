#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N = 0;
  int M = 0;
  int C = 0;
  std::cin >> N >> M >> C;
  std::vector<int> B(M, 0);

  for (int i = 0; i < B.size(); i++) {
    int a = 0;
    std::cin >> a;
    B[i] = a;
  }

  std::vector<int> A_i_row(M, 0);
  std::vector<std::vector<int>> A(N, A_i_row);

  int counter = 0;
  for (int i = 0; i < A.size(); i++) {
    int judge = C;
    for (int j = 0; j < A[i].size(); j++) {
      int a = 0;
      std::cin >> a;
      A[i][j] = a;
      
      judge += a * B[j];
      
    }
    
    if (judge > 0) {
      counter += 1;
    }
  }
  std::cout << counter << std::endl;
  return 0;
}