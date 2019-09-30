#include <iostream>

using namespace std;

int main() {
  int D, N;
  cin >> D >> N;

  int count = 0;

  long long  num = 1;
  while(true) {
    // ?? 100 ????? ???
    int div_count = 0;
    long long div_num = num;

    while(true) {
      if (div_count >= 3) break;

      long long amari = div_num % 100;
      if (amari == 0) {
        div_count++;
        div_num /= 100;
      } else {
        break;
      }
    }

    if (div_count == D) ++count;

    if (count == N) {
      cout << num << endl;
      return 0;
    }

    num++;
  }
}