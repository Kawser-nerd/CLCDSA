#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
using int64 = int_fast64_t;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  int H, W, T;
  cin >> H >> W >> T;
  vector< string > s(H);
  pair< int, int > b, g; 
  for (int hi=0; hi<H; ++hi) {
    cin >> s[hi];
    for (int wi=0; wi<W; ++wi) {
      if (s[hi][wi] == 'S') b = make_pair(hi, wi);
      else if (s[hi][wi] == 'G') g = make_pair(hi, wi);
    }
  }

  auto check = [=](int64 x) {
    vector< vector< int64 > > d(H, vector< int64 >(W, 1e9+1));
    queue< pair< int, int > > q;    
    d[b.first][b.second] = 0;
    q.push(b);

    while (!q.empty()) {
      int fY, fX;
      tie(fY, fX) = q.front(); q.pop();

      if (fY == g.first && fX == g.second) {
				/*for (int hi=0; hi<H; ++hi) {
					for (int wi=0; wi<W; ++wi)
						cout << d[hi][wi] << " ";
					cout << endl;
					}*/
        return (d[fY][fX] <= T);
      }

      for (int i=0; i<4; ++i) {
        int nY = fY + dy[i];
        int nX = fX + dx[i];
        if (!(0 <= nY && nY < H &&
              0 <= nX && nX < W)) continue;
				int cost = s[nY][nX] == '#' ? x : 1;
				if (d[nY][nX] > d[fY][fX] + cost) {
					if (d[fY][fX] + cost > T) continue;
					d[nY][nX] = d[fY][fX] + cost;
					q.push(make_pair(nY, nX));
				}
      }
    }
    return false;
  };

  int ng = 0, ok = 1e9+1;
  while (ok - ng > 1) {
    int mid = (ok + ng) / 2;
		// cout << (check(mid) ? "ok" : "ng") << endl;
    if (check(mid)) ng = mid;
    else ok = mid;
  }
  int ans = ng;
  cout << ans << endl;
  return 0;
}