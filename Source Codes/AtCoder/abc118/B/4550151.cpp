#include <iostream>
#include <vector>
using namespace std;
int main() {
  int N = 0;
  int M = 0;
  std::cin >> N >> M;
  std::string str;  //???15?????????????
  std::vector<int> j_row(M, 0);
  std::vector<std::vector<int>> v(N, j_row);
  int K[40];

  std::vector<int> a_row(40, 0);
  std::vector<std::vector<int>> A(40, j_row);

  for (int i = 0; i < N; i++) {
    cin >> K[i];
    for (int j = 0; j < K[i]; ++j) {
      cin >> A[i][j];
    }
  }
/*
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < A[i].size(); j++) {
      std::cout << A[i][j] << " ";
    }
    std::cout << std::endl;
  }
  */

  int counter_2 = 0;
  for (int m = 0; m < M; m++) {
    int counter = 0;
    for (int i = 0; i < N; i++) {
      auto itr = std::find(A[i].begin(), A[i].end(), m+1);
      //  ?????5??????????
      if (itr != A[i].end()) {
        counter += 1;
      }
    }

    if (counter == N) {
      // std::cout << m << std::endl;
      counter_2 += 1;
    }
  }

  std::cout << counter_2 << std::endl;
  return 0;
}