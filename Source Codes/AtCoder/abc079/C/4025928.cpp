/**
 * AtCoder Beginner Contest 079
 * C - Train Ticket
 *
 * bit???????
 */
#include <iostream>
using namespace std;

#define LEN 4

int main() {
  char ABCD[LEN + 1];
  scanf("%s", &ABCD[0]);

  int sum;
  for (size_t i{}; i < (1 << (LEN - 1)); ++i) {
    sum = ABCD[0] & 0xF;
    for (size_t j{}; j < LEN - 1; ++j) {
      if (i & (1 << j)) {
        sum += ABCD[j + 1] & 0xF;
      } else {
        sum -= ABCD[j + 1] & 0xF;
      }
    }
    if (sum == 7) {
      printf("%c", ABCD[0]);
      for (int j{}; j < (LEN - 1); ++j) {
        printf("%c%c", (i & (1 << j)) ? '+' : '-', ABCD[j + 1]);
      }
      printf("=7\n");
      return 0;
    }
  }

  return 1; // no case
}