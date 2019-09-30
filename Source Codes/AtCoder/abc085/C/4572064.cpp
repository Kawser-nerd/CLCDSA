#include <iostream>
#include <string>
#include <vector>
using namespace std;

int get_Max_size(int money, int base) {
  int count = 0;
  int tmp_money = money;
  for (;;) {
    if (tmp_money - base > 0) {
      tmp_money -= base;
      count += 1;
    } else {
      break;
    }
  }
  return count;
}

int main() {
  int N = 0;
  int Y = 0;
  std::cin >> N;
  std::cin >> Y;
  if (Y / 1000 == N) {
    std::cout << "0"
              << " "
              << "0"
              << " " << N << std::endl;
    return 0;
  } else if (Y / 5000 == N) {
    std::cout << "0"
              << " " << N << " "
              << "0" << std::endl;
    return 0;
  } else if (Y / 10000 == N) {
    std::cout << N << " "
              << "0"
              << " "
              << "0" << std::endl;
    return 0;
  }

  int x = 0;
  int y = 0;
  int z = 0;

  int x_counter = 0;
  int y_counter = 0;
  int z_counter = 0;

  int max_10000 = get_Max_size(Y, 10000);

  for (int i = 0; i < max_10000 + 1; i++) {
    int tmp_Y = Y - 10000 * i;
    x_counter = i;
    int max_5000 = get_Max_size(tmp_Y, 5000);
    for (int j = 0; j < max_5000 + 1; j++) {
      y_counter = j;
      z_counter = (tmp_Y - 5000 * j) / 1000;

      if (x_counter + y_counter + z_counter == N) {
        std::cout << x_counter << " " << y_counter << " " << z_counter
                  << std::endl;
        return 0;
      }
    }
  }

  std::cout << "-1"
            << " "
            << "-1"
            << " "
            << "-1" << std::endl;

  return 0;
}