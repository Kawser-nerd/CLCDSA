#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 100010;

char color[N];

vector <int> g[N];

map < vector <int>, int > mvect;
map < pair <int, int>, int > mhash;
map < pair <int, int>, bool > mgood;

int get_hash(int v, int pr) {
//  cerr << "get_hash " << v << " " << pr << endl;
  pair <int, int> p = make_pair(v, pr);
  if (mhash.find(p) != mhash.end()) {
    return mhash[p];
  }
  int sz = g[v].size();
  vector <int> hashes;
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (u == pr) {
      continue;
    }
    hashes.push_back(get_hash(u, v));
  }
  sort(hashes.begin(), hashes.end());
  hashes.push_back(color[v]);
  int res;
  if (mvect.find(hashes) != mvect.end()) {
    res = mvect[hashes];
  } else {
    res = mvect.size();
    mvect[hashes] = res;
  }
  mhash[p] = res;
  return res;
}

bool is_good(int v, int pr) {
//  cerr << "is_good " << v << " " << pr << endl;
  pair <int, int> p = make_pair(v, pr);
  if (mgood.find(p) != mgood.end()) {
    return mgood[p];
  }
  int sz = g[v].size();
  vector < pair <int, int> > hashes;
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    if (u == pr) {
      continue;
    }
    hashes.push_back(make_pair(get_hash(u, v), u));
  }
  sort(hashes.begin(), hashes.end());
  bool res = true;
  int cnt = hashes.size();
  if (cnt % 2 == 0) {
    for (int i = 0; i < cnt; i += 2) {
      if (hashes[i].first != hashes[i + 1].first) {
        res = false;
        break;
      }
    }
  } else {
    int i = 0;
    while (i < cnt) {
      if (i + 1 < cnt && hashes[i].first == hashes[i + 1].first) {
        i += 2;
        continue;
      }
      for (int j = i + 1; j < cnt; j += 2) {
        if (hashes[j].first != hashes[j + 1].first) {
          res = false;
          break;
        }
      }
      if (res) {
        res = is_good(hashes[i].second, v);
      }
      break;
    }
  }
  mgood[p] = res;
  return res;
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    fflush(stdout);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      color[i] = getchar();
      while (color[i] < 'A' || color[i] > 'Z') {
        color[i] = getchar();
      }
      g[i].clear();
    }
    for (int i = 0; i < n - 1; i++) {
      int foo, bar;
      scanf("%d %d", &foo, &bar);
      foo--; bar--;
      g[foo].push_back(bar);
      g[bar].push_back(foo);
    }
    mvect.clear();
    mhash.clear();
    mgood.clear();
    bool ok = false;
    for (int i = 0; i < n; i++) {
      int sz = g[i].size();
      for (int j = 0; j < sz; j++) {
        if (get_hash(i, g[i][j]) == get_hash(g[i][j], i)) {
          ok = true;
          break;
        }
      }
    }
    if (!ok) {
      for (int i = 0; i < n; i++) {
        if (is_good(i, -1)) {
          ok = true;
          break;
        }
      }
    }
    printf(ok ? "" : "NOT ");
    printf("SYMMETRIC\n");
    fflush(stdout);
    fprintf(stderr, "test %d solved\n", qq);
  }
  return 0;
}
