#include <iostream>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

#define MAX_S 200000
char S[MAX_S+1];
int len;

int main() {
  scanf("%s", S);
  for (; S[len]; ++len);

  long total{};
  for (int i{}, cnt{}; i < len; ++i) {
    if (S[i] == 'W') {
      total += cnt;
    } else {
      ++cnt;
    }
  }

  printf("%ld\n", total);
  return 0;
}