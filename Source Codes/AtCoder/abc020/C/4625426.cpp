// Last Change: 03/18/2019 23:26:40.
#include <algorithm>
#include <array>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;
using ll = long long;

namespace NS {
void LoopUntilZeroInpput() {
  int hogegegege = 0;
  while (cin >> hogegegege && hogegegege != 0) {
  }
}
} // namespace NS

const ll INF = INT64_MAX;

ll H, W, T;
vector<vector<char>> area;
vector<vector<ll>> areaTime;

pair<ll, ll> start;
pair<ll, ll> goal;

void AreaTimeInit() {
  static bool already = false;
  if (!already) {
    areaTime.resize(H);
    already = true;
  }
  for (int i = 0; i < H; ++i) {
    vector<ll> tmp(W, INF);
    areaTime[i] = tmp;
  }
  areaTime[start.first][start.second] = 0;
}

// i,j????
bool Update(ll i, ll j, ll curTime, const ll x) {
  //??????
  if (i < 0 or i >= H) {
    return false;
  }
  if (j < 0 or j >= W) {
    return false;
  }

  if (area[i][j] == '.') {
    curTime += 1;
  } else if (area[i][j] == '#') {
    curTime += x;
  }

  if (areaTime[i][j] > curTime) {
    areaTime[i][j] = curTime;
    return true;
  } else {
    return false;
  }
}

ll wfs(const ll x) {
  AreaTimeInit();

  queue<pair<ll, ll>> q;
  q.push(start);

  //???
  while (!q.empty()) {
    pair<ll, ll> tmp;
    tmp = q.front();
    q.pop();

    bool result;
    pair<ll, ll> next;

    // up
    result =
        Update(tmp.first - 1, tmp.second, areaTime[tmp.first][tmp.second], x);
    if (result) {
      next.first = tmp.first - 1;
      next.second = tmp.second;
      q.push(next);
    }

    // down
    result =
        Update(tmp.first + 1, tmp.second, areaTime[tmp.first][tmp.second], x);
    if (result) {
      next.first = tmp.first + 1;
      next.second = tmp.second;
      q.push(next);
    }

    // right
    result =
        Update(tmp.first, tmp.second + 1, areaTime[tmp.first][tmp.second], x);
    if (result) {
      next.first = tmp.first;
      next.second = tmp.second + 1;
      q.push(next);
    }

    // left
    result =
        Update(tmp.first, tmp.second - 1, areaTime[tmp.first][tmp.second], x);
    if (result) {
      next.first = tmp.first;
      next.second = tmp.second - 1;
      q.push(next);
    }
  }

  return areaTime[goal.first][goal.second];
}

int main() {
  cin >> H >> W >> T;
  area.reserve(H);
  for (int i = 0; i < H; ++i) {
    vector<char> tmp(W);
    for (int j = 0; j < W; ++j) {
      cin >> tmp[j];
      if (tmp[j] == 'S') {
        start.first = i;
        start.second = j;
        tmp[j] = '.';
      } else if (tmp[j] == 'G') {
        goal.first = i;
        goal.second = j;
        tmp[j] = '.';
      }
    }
    area.push_back(tmp);
  }

  //????
  ll left, right, center, tmp;
  left = 1;
  right = T + 1;
  while (left < right) {
    center = left + (right - left) / 2;
    tmp = wfs(center);
    if (tmp > T) {
      right = center;
    } else {
      left = center + 1;
    }
  }

  /*  for (int i = center; i < right; ++i) {
      if (wfs(i) <= T) {
        center = i;
      } else {
        break;
      }
    }*/

  cout << right - 1 << endl;

  //NS::LoopUntilZeroInpput();
}