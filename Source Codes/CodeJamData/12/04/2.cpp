#include <cassert>
#include <cmath>
#include <cstdio>
#include <map>
#include <set>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define eps 1e-9

char a[55][55];

int is_int (double x) {
  return fabs (x - floor (x + 0.5)) < eps;
}

int main(void) {
  int tn, nt;
  scanf("%d", &nt);
  for (tn=1; tn<=nt; tn++) {
    printf ("Case #%d: ", tn);
    fprintf (stderr, "Case #%d: \n", tn);

    int h, w, d;
    scanf("%d %d %d\n", &h, &w, &d);
    for (int i = 0; i < h; i++) {
      gets(a[i]);
    }

    int sx = -1, sy = -1;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        if (a[i][j] == 'X') {
          sx = i;
          sy = j;
        }
      }
    }
    w -= 2;
    h -= 2;
    sx -= 1;
    sy -= 1;

    w *= 2;
    h *= 2;
    sx = 2 * sx + 1;
    sy = 2 * sy + 1;

    assert (0 < sx && sx < h);
    assert (0 < sy && sy < w);

    set <pair <int, int> > ans;

    for (int i = -105; i <= 105; i++) {
      for (int j = -105; j <= 105; j++) {
        int nx = i;
        int ny = j;
        nx -= sx;
        ny -= sy;
        if (nx == 0 && ny == 0) {
          continue;
        }
        if (nx * nx + ny * ny > 4 * d * d) {
          continue;
        }
        int D = __gcd(abs(nx), abs(ny));
        assert (D);

        nx /= D;
        ny /= D;

        ans.insert (make_pair(nx, ny));
      }
    }

    w /= 2;
    h /= 2;

    int res = 0;
    for (set <pair <int, int> >::iterator p = ans.begin(); p != ans.end(); p++) {
      int dx = p->first;
      int dy = p->second;
      double mul = sqrt (dx * dx + dy * dy);
//      fprintf (stderr, "!!!%d %d\n", dx, dy);

      double x = sx * 0.5;
      double y = sy * 0.5;
      double dist = d + eps;

      while (dist > 0) {
        double tx = 1e6, ty = 1e6;
//        fprintf (stderr, "%.10lf %.10lf %d %d\n", x, y, dx, dy);
        if (dx < 0) {
          if (is_int(x)) {
            tx = 1.0 / -dx;
          } else {
            tx = (x - floor(x)) / -dx;
          }
        }
        if (dx > 0) {
          if (is_int (x)) {
            tx = 1.0 / dx;
          } else {
            tx = (floor(x) + 1 - x) / dx;
          }
        }
        if (dy < 0) {
          if (is_int (y)) {
            ty = 1.0 / -dy;
          } else {
            ty = (y - floor(y)) / -dy;
          }
        }
        if (dy > 0) {
          if (is_int (y)) {
            ty = 1.0 / dy;
          } else {
            ty = (floor(y) + 1 - y) / dy;
          }
        }

        double t = min (tx, ty);
        assert (t > eps);

        double nx = x + t * dx, ny = y + t * dy;
        t *= mul;

        if (fabs(x + nx - sx) < eps && fabs(y + ny - sy) < eps && dist - 0.5 * t >= 0) {
          res++;
          break;
        }

        dist -= t;
//        fprintf (stderr, "%lf %lf %lf %lf\n", tx, ty, t, dist);
        if (dist < 0) {
          break;
        }

        x = nx;
        y = ny;
        if (is_int (x))
          x = floor (x + 0.5);
        if (is_int (y))
          y = floor (y + 0.5);

        if (is_int(x) && is_int(y)) {

          int X = (int)floor (x + 0.5);
          int Y = (int)floor (y + 0.5);

          assert (0 <= X && X <= h);
          assert (0 <= Y && Y <= w);

          int cnt = (a[X][Y] == '#') + (a[X + 1][Y] == '#') + (a[X][Y + 1] == '#') + (a[X + 1][Y + 1] == '#');
          assert (cnt < 4);

          if (cnt == 1) {
            if (a[X + (dx > 0)][Y + (dy > 0)] == '#') {
              break;
            }
          }
          if (cnt == 3) {
            if (dist >= d * 0.5) {
              res++;
            }
            break;
          }
          if (cnt == 2) {
            if (a[X + (dx > 0)][Y + (dy > 0)] == '#') {
              if (a[X + 1 - (dx > 0)][Y + (dy > 0)] != '#') {
                dx = -dx;
              } else {
                dy = -dy;
              }
            }
          }
        } else {
          int X = (int)floor (x + 0.5);
          int Y = (int)floor (y + 0.5);

          int X0 = (int)floor (x);
          int Y0 = (int)floor (y);

          if (is_int(x)) {
            if (a[X + (dx > 0)][Y0 + 1] == '#') {
              dx = -dx;
            }
          }

          if (is_int(y)) {
            if (a[X0 + 1][Y + (dy > 0)] == '#') {
              dy = -dy;
            }
          }
        }
      }

//      fprintf (stderr, "res = %d\n\n", res);
    }

    printf ("%d\n", res);

  }

  return 0;
}
