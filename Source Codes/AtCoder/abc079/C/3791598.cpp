#include <iostream>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

int main() {
  char ABCD[4+1];
  scanf("%s", ABCD);

  for (int i{}; i < (1 << (4-1)); ++i) {
    int calc = ABCD[0] & 0xF;
    for (int j{}; j < (4-1); ++j) {
      if (i & (1 << j))
        calc += ABCD[j+1] & 0xF;
      else
        calc -= ABCD[j+1] & 0xF;
    }
    if (calc == 7) {
      printf("%c", ABCD[0]);
      for (int j{}; j < (4-1); ++j) {
        printf("%c%c", (i & (1 << j)) ? '+' : '-', ABCD[j+1]);
      }
      printf("=7\n");
      return 0;
    }
  }

  return 0;
}