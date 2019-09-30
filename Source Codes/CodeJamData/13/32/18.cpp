#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <stdint.h>
#include <map>
#include <queue>

typedef int64_t ll;

using namespace std;

typedef pair < ll, ll > pos;

ll dx[] = {1, -1, 0, 0};
ll dy[] = {0, 0, 1, -1};
string directions[] = {"E", "W", "N", "S"};

string solve() {
  ll x, y;
  cin >> x >> y;

  map < pos, ll > distances;
  map < pos, pos > came_from;
  map < pos, string > path;
  queue < pos > q;

  q.push(pos(0, 0));
  distances[pos(0, 0)] = 0;


  while(distances.find(pos(x, y)) == distances.end()) {
    assert(!q.empty());
    pos cur = q.front(); q.pop();

    ll dv = distances[cur] + 1;

    for(int k = 0; k < 4; k++) {
      ll nx = cur.first + dv * dx[k], ny = cur.second + dv * dy[k];

      if(distances.find(pos(nx, ny)) == distances.end()) {
        distances[pos(nx, ny)] = dv;
        came_from[pos(nx, ny)] = cur;
        path[pos(nx, ny)] = directions[k];
        q.push(pos(nx, ny));
      }
    }
  }

  string res;
  pos ptr = pos(x, y);

  while(ptr != pos(0, 0)) {
    res += path[ptr];
    ptr = came_from[ptr];
  }

  reverse(res.begin(), res.end());
  return res;
}

int main() {
  int tests;
  cin >> tests;

  for(int i = 1; i <= tests; i++) {
    cout << "Case #" << i << ": " << solve() << endl;
  }

  return 0;
}