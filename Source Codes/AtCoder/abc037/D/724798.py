import subprocess as sp
import sys
code = r'''
#include <algorithm>
#include <cstdio>
using namespace std;
const int M = 1000000007;
int h, w;
int a[1000][1000], cache[1000][1000];
unsigned f(int x, int y) {
  static int dx[] = {1, 0, -1, 0};
  static int dy[] = {0, 1, 0, -1};
  int &c = cache[y][x];
  if (c < 0) {
    c = 1;
    for (int d = 0; d < 4; ++d) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (0 <= nx and nx < w and 0 <= ny and ny < h and a[ny][nx] > a[y][x]) {
        c = (c + f(nx, ny)) % M;
      }
    }
  }
  return c;
}
int main() {
  int total = 0;
  scanf("%d%d", &h, &w);
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      scanf("%d", &a[y][x]);
    }
  }
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      cache[y][x] = -1;
    }
  }
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      total = (total + f(x, y)) % M;
    }
  }
  printf("%d\n", total);
  return 0;
}
'''
filename = 'sense_of_guilt.cpp'
with open(filename, 'w') as f:
    print(code, file=f)
sp.Popen(['g++', '-std=c++11', '-O2', filename]).communicate()
sp.Popen(['./a.out'], stdin=sys.stdin, stdout=sys.stdout).communicate()