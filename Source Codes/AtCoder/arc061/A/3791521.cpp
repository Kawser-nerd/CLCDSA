#include <iostream>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))

#define DIVUP(x, y) (((x) + ((y) - 1)) / (y))
#define DIVOFF(x, y) (((x) + ((y) / 2)) / (y))
#define REMAINDER(x, y) ((x) % (y))

#define SLEN 10
char S[SLEN+1];
int slen{};
bool P[SLEN];

int main() {
  scanf("%s", S);
  for (; slen < SLEN && S[slen]; ++slen);

  long total{};
  for (int i{0}; i < (1 << (MIN(slen, SLEN)-1)); ++i) {
    long temp = S[0] & 0xF;
    for (int j{0}; j < MIN(slen, SLEN)-1; ++j) {
      if (i & (1 << j)) {
        total += temp;
        temp = 0;
      }
      temp *= 10;
      temp += S[j+1] &0xF;
    }
    total += temp;
  }

  printf("%ld\n", total);
  return 0;
}