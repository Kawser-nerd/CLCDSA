#include <bits/stdc++.h>

using namespace std;

inline int mabs(int x) {
  return (x < 0 ? (-x) : x);
}

#define POS "POSSIBLE"
#define IMP "IMPOSSIBLE"

const int dx[8] = {-1, 0, 1, 0, 1, 1, -1, -1};
const int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

const int N = 1010;

char s[N][N];
int h, w;

bool can_remove(int i, int j) {
  if (i <= 0 || j <= 0 || i >= h - 1 || j >= w - 1) {
    return false;
  }
  if (s[i][j] != '#') {
    return false;
  }
  if (s[i - 1][j - 1] != '#' && s[i - 1][j] == '#' && s[i][j - 1] == '#') {
    return false;
  }
  if (s[i - 1][j + 1] != '#' && s[i - 1][j] == '#' && s[i][j + 1] == '#') {
    return false;
  }
  if (s[i + 1][j - 1] != '#' && s[i + 1][j] == '#' && s[i][j - 1] == '#') {
    return false;
  }
  if (s[i + 1][j + 1] != '#' && s[i + 1][j] == '#' && s[i][j + 1] == '#') {
    return false;
  }          
  int cnt = 0;
  int h = 0;
  for (int q = 0; q < 4; q++) {
    int xk = i + dx[q];
    int yk = j + dy[q];
    if (s[xk][yk] == '#') {
      cnt++;
      h ^= q;
    }
  }
  if (cnt == 0 || cnt == 1 || (cnt == 2 && (h & 1))) {
    return true;
  }
  return false;
}

bool was[N][N];
int x[N * N], y[N * N], z[N * N];

int get() {
  int sx = -1, sy = -1;
  int fx = -1, fy = -1;
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      was[i][j] = (s[i][j] == '#');
      if (s[i][j] == 'S') {
        sx = i;
        sy = j;
      }
      if (s[i][j] == 'F') {
        fx = i;
        fy = j;
      }
    }
  }
//  cerr << sx << " " << sy << " start" << endl;
  int b = 0, e = 1;
  x[0] = sx;
  y[0] = sy;
  z[0] = 0;
  was[sx][sy] = true;
  while (b < e) {
    for (int q = 0; q < 4; q++) {
      int xk = x[b] + dx[q];
      int yk = y[b] + dy[q];
      if (!was[xk][yk]) {
        was[xk][yk] = true;
        x[e] = xk;
        y[e] = yk;
        z[e] = z[b] + 1;
        if (xk == fx && yk == fy) {
          return z[e];
        }
        e++;
      }
    }
    b++;
  }
  cerr << "???" << endl;
  assert(false);
  return -1;
}

const int MAX = (int) 1e8;

int id[N][N];
int rx[MAX], ry[MAX];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int d;
    scanf("%d %d %d", &h, &w, &d);
    int sx = -1, sy = -1;
    int fx = -1, fy = -1;
    for (int i = 0; i < h; i++) {
      scanf("%s", s[i]);
      for (int j = 0; j < w; j++) {
        if (s[i][j] == 'S') {
          sx = i;
          sy = j;
        }
        if (s[i][j] == 'F') {
          fx = i;
          fy = j;
        }
      }
    }
    int manh = mabs(sx - fx) + mabs(sy - fy);
    int cur = get();
    if (cur < d || cur % 2 != d % 2 || d < manh) {
      puts(IMP);
      continue;
    }
    puts(POS);
    int cnt = 0;
    for (int i = 1; i < h - 1; i++) {
      for (int j = 1; j < w - 1; j++) {
        id[i][j] = -1;
      }
    }
    for (int i = 1; i < h - 1; i++) {
      for (int j = 1; j < w - 1; j++) {
        if (can_remove(i, j)) {
          rx[cnt] = i;
          ry[cnt] = j;
          id[i][j] = cnt;
          cnt++;
        }
      }
    }
    for (int it = 0; it < cnt; it++) {
      if (cnt >= MAX) {
        assert(false);
      }
      int i = rx[it];
      int j = ry[it];
      if (!can_remove(i, j)) {
        rx[cnt] = i;
        ry[cnt] = j;
        id[i][j] = cnt;
        cnt++;
        continue;
      }
//      cerr << "removing " << i << " " << j << endl;
      s[i][j] = '.';
      for (int q = 0; q < 8; q++) {
        int xk = i + dx[q];
        int yk = j + dy[q];
        if (xk == 0 || yk == 0 || xk == h - 1 || yk == w - 1) {
          continue;
        }
        if (id[xk][yk] == -1 && can_remove(xk, yk)) {
          rx[cnt] = xk;
          ry[cnt] = yk;
          id[xk][yk] = cnt;
          cnt++;
        }
      }
    }
    int final = get();
    assert(final <= d);
    int low = 0, high = cnt;
    while (low < high) {
      int mid = (low + high) >> 1;
      for (int i = 1; i < h - 1; i++) {
        for (int j = 1; j < w - 1; j++) {
          if (id[i][j] == -1) {
            continue;
          }
          if (id[i][j] >= mid) {
            s[i][j] = '#';
          } else {
            s[i][j] = '.';
          }
        }
      }
//      for (int i = 0; i < h; i++) {
//        cerr << s[i] << endl;
//      }
      int dist = get();
//      cerr << "mid = " << mid << ", dist = " << dist << endl;
      if (dist > d) {
        low = mid + 1;
      } else {
        high = mid;
      }
    }
    for (int i = 1; i < h - 1; i++) {
      for (int j = 1; j < w - 1; j++) {
        if (id[i][j] == -1) {
          continue;
        }
        if (id[i][j] >= low) {
          s[i][j] = '#';
        } else {
          s[i][j] = '.';
        }
      }
    }
    assert(get() == d);
    for (int i = 0; i < h - 1; i++) {
      for (int j = 0; j < w - 1; j++) {
        if (s[i][j] == '#' && s[i + 1][j + 1] == '#' && s[i][j + 1] != '#' && s[i + 1][j] != '#') { cerr << "botva" << endl;
          assert(false); }
        if (s[i][j + 1] == '#' && s[i + 1][j] == '#' && s[i][j] != '#' && s[i + 1][j + 1] != '#') { cerr << "botva" << endl;
          assert(false); }
      }
    }
    for (int i = 0; i < h; i++) {
      puts(s[i]);
    }
    fprintf(stderr, "test case %d solved\n", qq);
    fflush(stderr);
  }
  return 0;
}
