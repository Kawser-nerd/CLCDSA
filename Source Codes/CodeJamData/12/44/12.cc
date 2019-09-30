#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

int X, Y;
char g[100][100];
int lucky[100][100];

vector<pair<int, int> > doitv;
void doit(int x, int y) {
  if (g[y][x] == '#') return;
  if (lucky[y][x]) return;
  lucky[y][x] = true;
  doitv.push_back(make_pair(x, y));
  doit(x-1, y);
  doit(x+1, y);
  doit(x, y-1);
}

main() {
  int T, prob=1;
  for (cin >> T; T--;) {
    cin >> Y >> X;
    for (int y = 0; y < Y; y++) cin >> g[y];
    cout << "Case #" << prob++ << ":" << endl;
    for (char ch = '0'; ch <= '9'; ch++)
    for (int cy = 0; cy < Y; cy++)
    for (int cx = 0; cx < X; cx++) if (g[cy][cx] == ch) {
      doitv.clear();
      memset(lucky, 0, sizeof(lucky));
      doit(cx, cy);
      cout << ch << ": " << doitv.size() << ' ';

      priority_queue<pair<int, vector<pair<int, int> > > > q;
      set<vector<pair<int, int> > > seen;
      sort(doitv.begin(), doitv.end());
      doitv.erase(unique(doitv.begin(), doitv.end()), doitv.end());
      q.push(make_pair(-(int)doitv.size(), doitv));
      bool found = false;
      while (!q.empty()) {
        vector<pair<int, int> > v = q.top().second;
        q.pop();
        if (seen.count(v)) continue;
        seen.insert(v);
//for (int i = 0; i < v.size(); i++) cout << ' ' << v[i].first << ',' << v[i].second;
//cout << endl;
        if (v.size() == 1 && g[v[0].second][v[0].first] == ch) {
          found = true;
          break;
        }
        for (int dx = -1; dx <= 1; dx++)
        for (int dy = -1; dy <= 1; dy++)
        if (abs(dx)+abs(dy) == 1 && dy != -1) {
          vector<pair<int, int> > v2;
          bool fail = false;
          for (int i = 0; !fail && i < v.size(); i++) {
            if (g[v[i].second+dy][v[i].first+dx] == '#') {
              v2.push_back(make_pair(v[i].first, v[i].second));
            } else if (!lucky[v[i].second+dy][v[i].first+dx]) {
                fail = true;
            } else {
              v2.push_back(make_pair(v[i].first+dx, v[i].second+dy));
            }
          }
          if (!fail) {
            sort(v2.begin(), v2.end());
            v2.erase(unique(v2.begin(), v2.end()), v2.end());
            q.push(make_pair(-(int)v2.size(), v2));
          }
        }
      }

      if (found) cout << "Lucky" << endl; else cout << "Unlucky" << endl;
    }
  }
}
