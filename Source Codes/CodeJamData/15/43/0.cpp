#include <bits/stdc++.h>

using namespace std;

const int inf = (int)1e5;

const int N = 1000010;

int ss[N], ff[N], c[N], f[N], obr[N], pred[N], last[N];
int m;

void add(int x, int y, int z, int xx, int yy) {
  m++;
  ss[m] = x;
  ff[m] = y;
  c[m] = z;
  f[m] = xx;
  obr[m] = yy;
  pred[m] = last[x];
  last[x] = m;
}

int x[N], d[N];
int fin;

bool expath() {
  for (int i = 0; i <= fin; i++) d[i] = -1;
  int b = 1, e = 1;
  x[1] = 0;
  d[0] = 0;
  while (b <= e) {
    int j = last[x[b]];
    while (j > 0) {
      if (c[j] > f[j] && d[ff[j]] == -1) {
        e++;
        x[e] = ff[j];
        d[x[e]] = d[x[b]] + 1;
        if (x[e] == fin) {
          return true;
        }
      }
      j = pred[j];
    }
    b++;
  }
  return false;
}

int rec(int v, int w) {
  if (v == fin) {
    return w;
  }
  int r = 0, j = last[v];
  while (j > 0) {
    last[v] = pred[j];
    if (c[j] > f[j] && d[ff[j]] == d[v] + 1) {
      int ww = c[j] - f[j];
      if (w - r < ww) ww = w - r;
      int t = rec(ff[j], ww);
      if (t > 0) {
        f[j] += t;
        if (obr[j] != 0) f[obr[j]] -= t;
        r += t;
        if (r == w) break;
      }
    }
    j = pred[j];
  }
  return r;
}

int st[N];

vector <int> words[12345];
char foo[1234567];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    int nn;
    scanf("%d", &nn);
    gets(foo);
    map <string, int> qwe;
    for (int i = 0; i < nn; i++) {
      gets(foo);
      stringstream ss;
      for (int j = 0; foo[j]; j++) ss << foo[j];
      words[i].clear();
      string word;
      while (ss >> word) {
        if (qwe.find(word) == qwe.end()) {
          int id = qwe.size();
          qwe[word] = id;
        }
        words[i].push_back(qwe[word]);
      }
    }
    int word_cnt = qwe.size();
    fin = word_cnt * 2 + 1;
    for (int i = 0; i <= fin; i++) {
      last[i] = 0;
    }
    m = 0;
    for (int i = 0; i < word_cnt; i++) {
      add(2 * i + 1, 2 * i + 2, 1, 0, m + 2);
      add(2 * i + 2, 2 * i + 1, 0, 0, m);
    }
    for (int i = 0; i < (int)words[0].size(); i++) {
      int z = words[0][i];
      add(0, 2 * z + 1, inf, 0, 0);
    }
    for (int i = 0; i < (int)words[1].size(); i++) {
      int z = words[1][i];
      add(2 * z + 2, fin, inf, 0, 0);
    }
    for (int i = 2; i < nn; i++) {
      int sz = words[i].size();
      for (int x = 0; x < sz; x++) {
        for (int y = 0; y < sz; y++) {
          if (x == y) {
            continue;
          }
          int xx = words[i][x];
          int yy = words[i][y];
          add(2 * xx + 2, 2 * yy + 1, inf, 0, m + 2);
          add(2 * yy + 1, 2 * xx + 2, 0, 0, m);
        }
      }
    }
    for (int i = 0; i <= fin; i++) {
      st[i] = last[i];
    }
//    cout << fin << " " << m << endl;
//    for (int i = 1; i <= m; i++)  cout << ss[i] << " " << ff[i] << " " << c[i] << " " << f[i] << " " << obr[i] << endl;
    int ans = 0;
    while (expath()) {
      int t = rec(0, inf);
      ans += t;
      for (int i = 0; i <= fin; i++) {
        last[i] = st[i];
      }
    }
    printf("%d\n", ans);
    fflush(stdout);
    cerr << "test " << qq << " done" << endl;
  }
  return 0;
}
