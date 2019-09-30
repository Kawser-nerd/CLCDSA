#include <cassert>
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

typedef pair <int, int> pii;
int ansx[1005];
int ansy[1005];

void run (const vector <pii> &v, int &begin, int w, int h, int x0, int y0) {
  if (begin >= (int)v.size()) {
    return;
  }
  int num = v[begin].second;
  int r = v[begin].first;
  if (2 * r > w || 2 * r > h) {
    return;
  }
  ansx[num] = x0 + r;
  ansy[num] = y0 + r;
  begin++;
  r *= 2;
  vector <pii> vv;
  for (int i = 0; i <= 1; i++)
    for (int j = 0; j <= 1; j++)
      if (i || j) {
        int nw = w * i + (1 - 2 * i) * r;
        int nh = h * j + (1 - 2 * j) * r;
        vv.push_back(make_pair(nw * nh, 2 * i + j));
      }
  sort(vv.begin(), vv.end());
  reverse(vv.begin(), vv.end());
  for (int t = 0; t < 3; t++) {
    int i = vv[t].second / 2;
    int j = vv[t].second & 1;
    int nw = w * i + (1 - 2 * i) * r;
    int nh = h * j + (1 - 2 * j) * r;
    run (v, begin, nw, nh, x0 + i * r, y0 + j * r);
  }
}

int main(void) {
  int tn, nt;
  scanf("%d", &nt);
  for (tn = 1; tn <= nt; tn++) {
    printf ("Case #%d:", tn);
    fprintf (stderr, "Case #%d: \n", tn);

    int n, w, h;
    scanf ("%d%d%d", &n, &w, &h);
    vector <pii> v;
    for (int i = 0; i < n; i++) {
      int r;
      scanf("%d", &r);
      v.push_back(make_pair(r, i));
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    int begin = 0;
    int x0 = 0, y0 = 0;
    while (begin < (int)v.size() && v[begin].first * 2 > w || v[begin].first * 2 > h) {
      int r = v[begin].first;
      int num = v[begin].second;
      if (w > h) {
        ansx[num] = x0 + r;
        ansy[num] = 0;
        w -= 2 * r;
        x0 += 2 * r;
      } else {
        ansx[num] = 0;
        ansy[num] = y0 + r;
        h -= 2 * r;
        y0 += 2 * r;
      }
      begin++;
    }
    run (v, begin, w, h, x0, y0);
    if (begin != (int)v.size()) {
      fflush (stdout);
      assert (0);
    }
    for (int i = 0; i < n; i++) {
      cout << " " << ansx[i] << " " << ansy[i];
    }
    cout << endl;
  }

  return 0;
}
