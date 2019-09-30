#include <iostream>

int H, W;
int a[1010][1010];
int done[1010][1010];
int memo[1010][1010];

int dh[] = {-1, 1, 0, 0};
int dw[] = {0, 0, -1, 1};

int solve(int h, int w) {
  if (done[h][w] == 0) {
    done[h][w] = 1;
    for (int i = 0; i < 4; ++i) {
      int hh = h + dh[i];
      int ww = w + dw[i];
      if (hh >= 0 and hh < H and ww >= 0 and ww < W and a[hh][ww] > a[h][w]) {
        memo[h][w] = (memo[h][w] + solve(hh, ww)) % 1000000007;
      }
    }
  }
  return memo[h][w];
}

int main() {
  scanf("%d %d", &H, &W);
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      scanf("%d", &a[i][j]);
      done[i][j] = 0;
      memo[i][j] = 1;
    }
  }

  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      solve(i, j);
    }
  }

  int ans = 0;
  for (int i = 0; i < H; ++i) {
    for (int j = 0; j < W; ++j) {
      ans = (ans + memo[i][j]) % 1000000007;
    }
  }

  printf("%d\n", ans);
}