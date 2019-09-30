#include <cstring>
#include <iostream>
using namespace std;

int dx[6] = {1, 0, -1, -1, 0, 1};
int dy[6] = {1, 1, 0, -1, -1, 0};

int S, piece[6011][6011], cook[6011][6011], cookie;

int bridge, ring, edge[6];
int gx, gy;
void doit(int x, int y, int d, int turn) {
  if (x == gx && y == gy && turn > 3) ring = true;
  if (cook[y][x] == cookie) return;
  cook[y][x] = cookie;
  for (int d2 = (d+4)%6, t = 2; t >= -2; d2 = (d2+1)%6, t--) {
    int x2 = x+dx[d2], y2 = y+dy[d2];
    if (piece[y2][x2]) {
      doit(x2, y2, d2, turn+t);
      break;
    }
  }
}

void doit2(int x, int y) {
  if (!piece[y][x] || cook[y][x] == cookie) return;
  cook[y][x] = cookie;
  if (x == 1 && y == 1 ||
      x == 1 && y == S ||
      x == S && y == S+S-1 ||
      x == S+S-1 && y == S+S-1 ||
      x == S+S-1 && y == S ||
      x == S && y == 1) {
    bridge++;
  } else if (x == 1) {
    edge[0] = true;
  } else if (y-x == S-1) {
    edge[1] = true;
  } else if (y == S+S-1) {
    edge[2] = true;
  } else if (x == S+S-1) {
    edge[3] = true;
  } else if (x-y == S-1) {
    edge[4] = true;
  } else if (y == 1) {
    edge[5] = true;
  }
  for (int d = 0; d < 6; d++) doit2(x+dx[d], y+dy[d]);
}

main() {
  int T, M, prob=1;
  for (cin >> T; T--;) {
    cin >> S >> M;
    memset(piece, 0, sizeof(piece));
    cout << "Case #" << prob++ << ": ";
    bool outp = false;
    for (int i = 0; i < M; i++) {
      int x, y;
      cin >> x >> y;
      if (outp) continue;
      piece[y][x] = true;
      bridge = ring = 0;
      memset(edge, 0, sizeof(edge));

      for (int d = 0; d < 6; d++) {
        int d2 = (d+1)%6;
        if (!piece[y+dy[d]][x+dx[d]] &&
            piece[y+dy[d2]][x+dx[d2]]) {
          ++cookie;
          doit(gx = x+dx[d2], gy = y+dy[d2], d2, 0);
        }
      }
      ++cookie;
      doit2(x, y);

      if (bridge >= 2) {
        if (outp) cout << '-';
        outp = true;
        cout << "bridge";
      }
      if (edge[0]+edge[1]+edge[2]+edge[3]+edge[4]+edge[5] >= 3) {
        if (outp) cout << '-';
        outp = true;
        cout << "fork";
      }
      if (ring) {
        if (outp) cout << '-';
        outp = true;
        cout << "ring";
      }
      if (outp) {
        cout << " in move " << i+1 << endl;
      }
    }
    if (!outp) cout << "none" << endl;
  }
}
