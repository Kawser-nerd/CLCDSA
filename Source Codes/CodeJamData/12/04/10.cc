#include <algorithm>
#include <iostream>
using namespace std;

int X, Y, D;
char g[31][31];

main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    cin >> Y >> X >> D;
    for (int y = 0; y < Y; y++) cin >> g[y];
    int sx, sy;
    for (int y = 0; y < Y; y++)
    for (int x = 0; x < X; x++)
      if (g[y][x] == 'X') {
        sx = x; sy = y;
      }
    int ret = 0;
    for (int gy = sy-D; gy <= sy+D; gy++)
    for (int gx = sx-D; gx <= sx+D; gx++) {
      if ((gy-sy)*(gy-sy) + (gx-sx)*(gx-sx) > D*D) continue;
      if (gx == sx && gy == sy) continue;

      int fact = 2 * max(abs(gy-sy), 1) * max(abs(gx-sx), 1);
      int x = sx * fact + fact/2, startx = x;
      int y = sy * fact + fact/2, starty = y;
      int dy = gy-sy, dx = gx-sx;
      int nsteps = fact;
//cout << "Trying " << gx << ',' << gy << " " << dx << ',' << dy << endl;
      for (int i = 0; i < nsteps; i++) {
        if (i && x == startx && y == starty) goto fail;
//int odx = dx, ody = dy;
        y += dy; x += dx;
        if (y % fact == 0 && x % fact == 0) {
          // Hit a corner
          int curx = x/fact, cury = y/fact;
          char cur1 = g[cury - (dy > 0)][curx - (dx > 0)];
          char cur2 = g[cury - (dy > 0)][curx - (dx < 0)];
          char cur3 = g[cury - (dy < 0)][curx - (dx < 0)];
          char cur4 = g[cury - (dy < 0)][curx - (dx > 0)];
          if (cur1 == '#') {
            cerr << "ERROR!" << endl;
          }
          if (cur3 == '#' && cur2 == '#' && cur4 == '#') {
            dx = -dx; dy = -dy;
          } else if (cur3 == '#' && cur4 == '#') {
            dy = -dy;
          } else if (cur3 == '#' && cur2 == '#') {
            dx = -dx;
          } else if (cur3 == '#') {
            goto fail;
          }
        } else if (y % fact == 0) {
          // Hit a horizontal edge
          int curx = x/fact, cury = y/fact;
          char cur1 = g[cury - (dy > 0)][curx];
          char cur2 = g[cury - (dy < 0)][curx];
          if (cur1 == '#') {
            cerr << "ERROR!" << endl;
          }
          if (cur2 == '#') dy = -dy;
        } else if (x % fact == 0) {
          // Hit a vertical edge
          int curx = x/fact, cury = y/fact;
          char cur1 = g[cury][curx - (dx > 0)];
          char cur2 = g[cury][curx - (dx < 0)];
          if (cur1 == '#') {
            cerr << "ERROR!" << endl;
          }
          if (cur2 == '#') dx = -dx;
        }
//if (odx != dx || ody != dy) cout << "Going to " << gx << "," << gy << ": bounced off at " << x/(double)fact << ',' << y/(double)fact << ' ' << dx << ' ' << dy << endl;
      }
      if (x != startx || y != starty) goto fail;
//cout << "Saw replica at " << gx << ',' << gy << endl;
      ret++;
fail:;
    }
    cout << "Case #" << prob++ << ": " << ret << endl;
  }
}
