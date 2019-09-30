#include <stdio.h>
#include <stdlib.h>

enum {N = 100};

int color[N];
int number[N];
int count;

int bnumber[2][N];
int bcount[2];

int main(void) {
  int T, tt;
  scanf("%d", &T);
  for (tt = 1; tt <= T; tt++) {
    int i, time;
    int bi[2];
    int bp[2];

    bcount[0] = bcount[1] = 0;
    scanf("%d", &count);
    for (i = 0; i < count; i++) {
      int c;
      do {
        c = getchar();
      } while (c != 'O' && c != 'B');
      color[i] = (c == 'B');
      scanf("%d", &number[i]);
      bnumber[color[i]][bcount[color[i]]++] = number[i];
    }
    bi[0] = bi[1] = time = 0;
    bp[0] = bp[1] = 1;
    for (i = 0; i < count; i++) {
      int c = color[i];
      int dt = 1 + abs(number[i] - bp[c]);
      bp[c] = bnumber[c][bi[c]];
      bi[c]++;
      if (bi[!c] < bcount[!c]) {
        int dt_o = bnumber[!c][bi[!c]] - bp[!c];
        int dir = (dt_o >= 0 ? 1 : -1);
        if (dir * dt_o > dt) {
          bp[!c] = bp[!c] + dir * dt;
        } else {
          bp[!c] = bnumber[!c][bi[!c]];
        }
      }
      time += dt;
    }
    printf("Case #%d: %d\n", tt, time);
  }
  return 0;
}
