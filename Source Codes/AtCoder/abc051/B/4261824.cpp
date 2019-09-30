#include <iostream>
#include <cmath>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define ABS(x, y) ((x) > (y) ? ((x) - (y)) : ((y) - (x)))

#define MOD(x, y) ((x) % (y))
#define DIVCEIL(x, y) (((x) + ((y) - 1)) / (y))
#define DIVFLOOR(x, y) (((x) + ((y) / 2)) / (y))
#define DIVROUND(x, y) ((x) - MOD(x, y) >= MOD(x, y) ? DIVCEIL(x, y) : DIVFLOOR(x, y))

int main() {
  int K, S;
  cin >> K >> S;

  int count{};
  for (int x{}; x <= MIN(K, S); ++x) {
    for (int y{}; y <= MIN(K, S-x); ++y) {
      if (S >= x + y && S - (x + y) <= K) {
        ++count;
      }
    }
  }

  cout << count << endl;
  return 0;
}