#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;
  int over_3200 = 0;
  int flags = 0;
  int ans_min = 0;
  for (int i = 0; i < N; i++) {
    int rate;
    cin >> rate;
    if (rate >= 3200) {
      over_3200++;
    }
    else {
      int phase = rate / 400;
      int color_bit = 1 << phase;
      if (!(color_bit & flags)) {
        ans_min++;
        flags += color_bit;
      }
    }
  }
  int ans_max = ans_min;
  for (int i = 0; i < over_3200; i++) {
    ans_max++;
  }
  if (ans_min == 0) {
    ans_min++;
  }
  cout << ans_min << ' ' << ans_max << endl;
}