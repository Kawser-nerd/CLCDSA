#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>

using namespace std;

struct point {
  point() : x(0), y(0) {}
  point(int x, int y) : x(x), y(y) {}

  point& operator+=(const point& p) {
    x += p.x;
    y += p.y;
  }
  point& operator-=(const point& p) {
    x -= p.x;
    y -= p.y;
  }
  point operator+(const point& p) {
    return point(x + p.x, y + p.y);
  }
  point operator-(const point& p) {
    return point(x - p.x, y - p.y);
  }

  int x, y;
};

point A[510][510];
int B[510][510];
int CC[510][510];

int main() {
  int T; cin >> T;
  for(int t = 1; t <= T; t++) {
    int R, C, D; cin >> R >> C >> D;
    memset(A, 0, sizeof(A));
    memset(B, 0, sizeof(B));
    for(int i = 0; i < R; i++) {
      string S; cin >> S;
      for(int j = 0; j < C; j++) {
        A[i + 1][j + 1] = point(i * (S[j] - '0'), j * (S[j] - '0'));
        CC[i][j] = B[i + 1][j + 1] = S[j] - '0';
      }
    }
    for(int i = 1; i <= R; i++) {
      for(int j = 1; j <= C; j++) {
        A[i][j] += A[i - 1][j] + A[i][j - 1] - A[i - 1][j - 1];
        B[i][j] += B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
      }
    }
    int result = 0;
    for(int K = 3; K <= R && K <= C; K++) {
      bool ok = false;
      for(int i = 0; !ok && i + K <= R; i++) {
        for(int j = 0; j + K <= C; j++) {
          point cm = A[i + K][j + K] - A[i][j + K] - A[i + K][j] + A[i][j];
          int ms = B[i + K][j + K] - B[i][j + K] - B[i + K][j] + B[i][j];
          for(int di = 0; di < K; di += K - 1) {
            for(int dj = 0; dj < K; dj += K - 1) {
              int m = CC[i + di][j + dj];
              ms -= m;
              cm -= point(m * (i + di), m * (j + dj));
            }
          }
          cm.x *= 2; cm.y *= 2;
          cm -= point((2 * i + K - 1) * ms, (2 * j + K - 1) * ms);
          if(cm.x == 0 && cm.y == 0) {
            ok = true;
            result = K;
          }
        }
      }
    }
    if(!result) {
      printf("Case #%d: IMPOSSIBLE\n", t);
    } else {
      printf("Case #%d: %d\n", t, result);
    }
  }
}
