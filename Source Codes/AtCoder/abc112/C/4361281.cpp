#include <iostream>
using namespace std;

#define MIN(x, y) ((x) < (y) ? (x) : (y))
#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define DIFF(x, y) ((x) > (y) ? ((x) - (y)) : ((y) - (x)))

#define MOD(x, y) ((x) % (y))
// ceil() for integer dividing
#define DIVCEIL(x, y) (((x) + ((y) - 1)) / (y))
// floor() for integer dividing
#define DIVFLOOR(x, y) (((x) + ((y) / 2)) / (y))
// round() for integer dividing
#define DIVROUND(x, y) ((x) - MOD(x, y) >= MOD(x, y) ? DIVCEIL(x, y) : DIVFLOOR(x, y))

struct D {
  int x;
  int y;
  int h;
};

constexpr int MAX_N = 100;
constexpr int MAX_X = 100;
constexpr int MAX_Y = 100;

int main() {
  int N;
  cin >> N;
  D d[N + 1];
  for (int i{}; i < N; ++i) {
    cin >> d[i].x >> d[i].y >> d[i].h;
    if (d[i].h > 0) {
      d[N] = d[i];
    }
  }

  int x, y;
  long long H;
  for (x = 0; x <= MAX_X; ++x) {
    for (y = 0; y <= MAX_Y; ++y) {
      bool result{true};
      H = d[N].h + DIFF(d[N].x, x) + DIFF(d[N].y, y);
      for (int i{0}; i < N; ++i) {
        long long h = MAX(H - DIFF(d[i].x, x) - DIFF(d[i].y, y), 0LL);
        if (h != d[i].h) {
          result = false;
          break;
        }
      }
      if (result) {
        cout << x << ' ' << y << ' ' << H << endl;
        return 0;
      }
    }
  }

  return 0;
}