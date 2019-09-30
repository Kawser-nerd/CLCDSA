#include <bits/stdc++.h>

using namespace std;


struct Point {
  int x, y, z;

  void read() {
    cin >> x >> y >> z;
  }
};

int sq(int x) {
  return x * x;
}

int dist(Point a, Point b) {
  return sq(a.x - b.x) + sq(a.y - b.y) + sq(a.z - b.z);
}


const int M = 1010;
const int inf = 1e9;

int n, s;
int p[M];
Point a[M], v[M];

void read() {
  cin >> n >> s;
  for (int i = 0; i < n; ++i) {
    a[i].read();
    v[i].read();
  }
}

void ini() {
  for (int i = 0; i < n; ++i)
    p[i] = i;
}

#define get jdaslkfjls

int get(int x) {
  return p[x] = p[x] == x ? x : get(p[x]);
}

void uni(int x, int y) {
  x = get(x);
  y = get(y);
  p[x] = y;
}

void build(int B) {
  ini();
  for (int x = 0; x < n; ++x)
    for (int b = x + 1; b < n; ++b)
      if (dist(a[x], a[b]) <= B)
        uni(x, b);
}

void bin() {
  int l = 0, r = inf;
  while (l < r) {
    int m = (l + r) / 2;
    build(m);
    if (get(0) == get(1))
      r = m;
    else
      l = m + 1;
  }
  cout << sqrt(l) << endl;
}


int main() {
  cout.precision(10);
  cout << fixed;
  int t;
  cin >> t;
  for (int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    read();
    bin();
    cerr << "Case #" << i << " done.\n";
  }
  return 0;
}
