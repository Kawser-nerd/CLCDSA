#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  std::vector<int> C_i_row(3, 0);
  std::vector<std::vector<int>> C_num_vec(3, C_i_row);
  int answer = 0;
  for (int i = 0; i < C_num_vec.size(); i++) {
    for (int j = 0; j < C_num_vec[i].size(); j++) {
      int a = 0;
      std::cin >> a;
      C_num_vec[i][j] = a;
    }
  }

  //std::cout << C_num_vec[1][0] << std::endl;
  for (int a_1 = 0; a_1 <= 100; a_1++) {
    for (int b_1 = 0; b_1 <= 100; b_1++) {
      if (C_num_vec[0][0] == a_1 + b_1) {
        for (int a_2 = 0; a_2 <= 100; a_2++) {
          if (C_num_vec[1][0] == a_2 + b_1) {
            for (int a_3 = 0; a_3 <= 100; a_3++) {
              if (C_num_vec[2][0] == a_3 + b_1) {
                for (int b_2 = 0; b_2 <= 100; b_2++) {
                  if (C_num_vec[0][1] == a_1 + b_2 &&
                      C_num_vec[1][1] == a_2 + b_2 &&
                      C_num_vec[2][1] == a_3 + b_2) {
                    for (int b_3 = 0; b_3 <= 100; b_3++) {
                      if (C_num_vec[0][2] == a_1 + b_3 &&
                          C_num_vec[1][2] == a_2 + b_3 &&
                          C_num_vec[2][2] == a_3 + b_3)

                      {
                        std::cout << "Yes" << std::endl;
                        return 0;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  std::cout << "No" << std::endl;
  return 0;
}