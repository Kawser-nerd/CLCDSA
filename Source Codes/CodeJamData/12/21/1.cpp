#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  int T; cin >> T;
  for (int ti = 1; ti <= T; ti++) {
    int N; cin >> N;
    int s[1011], sum = 0;
    for (int i = 0; i < N; i++) cin >> s[i], sum += s[i];
    printf("Case #%d:", ti);
    for (int i = 0; i < N; i++) {
      double low = 0, high = 1;
      for (int j = 0; j < 100; j++) {
        double mid = (low + high) / 2;
        double me = s[i] + mid * sum;
        double rem = 1 - mid;
        for (int k = 0; k < N && rem > 0; k++) {
          if (k != i && s[k] < me) {
            rem -= (me - s[k]) / sum;
          }
        }
        if (rem > 0) {
          low = mid;
        } else {
          high = mid;
        }
      }
      printf(" %.6lf", low * 100);
    }
    printf("\n");
  }
}
