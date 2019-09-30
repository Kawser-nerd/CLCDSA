#include <bits/stdc++.h>

using namespace std;

struct Edge {
  int from;
  int to;
  int type;
};

struct Graph {
  int n;
  vector <Edge> e;
  
  Graph() {
    n = 1;
    e.clear();
  }

  Graph(int digit) {
    n = 2;
    e.clear();
    e.push_back(Edge {0, 1, digit});
  }
};

Graph concat(Graph a, Graph b) {
  Graph c = a;
  for (int i = 0; i < (int) b.e.size(); i++) {
    Edge e = b.e[i];
    e.from += a.n - 1;
    e.to += a.n - 1;
    c.e.push_back(e);
  }
  c.n += b.n - 1;
  return c;
}

Graph unite(Graph a, Graph b) {
  Graph c = a;
  c.n += b.n - 2;
  for (int i = 0; i < (int) c.e.size(); i++) {
    if (c.e[i].to == a.n - 1) {
      c.e[i].to = c.n - 1;
    }
  }
  for (int i = 0; i < (int) b.e.size(); i++) {
    Edge e = b.e[i];
    if (e.from != 0) {
      e.from += a.n - 2;
    }
    e.to += a.n - 2;
    c.e.push_back(e);
  }
  return c;
}

Graph kleine(Graph a) {
  Graph c = a;
  for (int i = 0; i < (int) c.e.size(); i++) {
    c.e[i].from++;
    c.e[i].to++;
  }
  c.n += 2;
  c.e.push_back(Edge {0, 1, -1});
  c.e.push_back(Edge {0, c.n - 1, -1});
  c.e.push_back(Edge {c.n - 2, c.n - 1, -1});
  c.e.push_back(Edge {c.n - 2, 1, -1});
  return c;
}

Graph solve(string s) {
//  cout << "solving " << s << endl;
  if (s == "") {
    return Graph();
  }
  if (s[0] == '(') {
    int len = s.length();
    int balance = 1;
    int match = -1;
    for (int i = 1; i < len; i++) {
      if (s[i] == '(') {
        balance++;
      }
      if (s[i] == ')') {
        balance--;
      }
      if (balance == 0) {
        match = i;
        break;
      }
    }
//    cout << "match = " << match << endl;
    assert(match != -1);
    Graph x;
    if (match < len - 1 && s[match + 1] == '*') {
      x = solve(s.substr(1, match - 1));
      x = kleine(x);
      match++;
    } else {
      balance = 1;
      int last = 1;
      for (int i = 1; i < match; i++) {
        if (s[i] == '(') {
          balance++;
        }
        if (s[i] == ')') {
          balance--;
        }
        if (balance == 1 && s[i] == '|') {
          Graph z = solve(s.substr(last, i - last));
          if (last == 1) {
            x = z;
          } else {
            x = unite(x, z);
          }
          last = i + 1;
        }
      }
      x = unite(x, solve(s.substr(last, match - last)));
    }
    Graph y = solve(s.substr(match + 1));
    return concat(x, y);
  }
  Graph x(s[0] - '0');
  Graph y = solve(s.substr(1));
  return concat(x, y);
}

map <int, long long> f[42][2][2];
int by_eps[42];
int go[42][42];

long long get(Graph g, long long bound) {
  assert(g.n <= 31);
  bound++;
  int kd = 0, d[42];
  while (bound > 0) {
    d[kd++] = bound % 10;
    bound /= 10;
  }
  for (int i = 0; i < g.n; i++) {
    by_eps[i] = (1 << i);
  }
  bool change = true;
  while (change) {
    change = false;
    for (int i = 0; i < (int) g.e.size(); i++) {
      Edge e = g.e[i];
      if (e.type != -1) {
        continue;
      }
      int x = e.from;
      int y = e.to;
      if ((by_eps[x] | by_eps[y]) != by_eps[x]) {
        by_eps[x] |= by_eps[y];
        change = true;
      }
    }
  }
  for (int i = 0; i < g.n; i++) {
    for (int j = 0; j < 10; j++) {
      go[i][j] = 0;
    }
  }
  for (int i = 0; i < (int) g.e.size(); i++) {
    Edge e = g.e[i];
    if (e.type == -1) {
      continue;
    }
    int x = e.from;
    int y = e.to;
    int z = e.type;
    go[x][z] |= (1 << y);
  }
  for (int i = 0; i <= kd; i++) {
    for (int nz = 0; nz <= 1; nz++) {
      for (int ls = 0; ls <= 1; ls++) {
        f[i][nz][ls].clear();
      }
    }
  }
  f[kd][0][0][by_eps[0]] = 1;
  for (int i = kd; i >= 1; i--) {
    for (int nz = 0; nz <= 1; nz++) {
      for (int ls = 0; ls <= 1; ls++) {
        for (auto p : f[i][nz][ls]) {
          int mask = p.first;
          long long ft = p.second;
          for (int digit = 0; digit <= 9; digit++) {
            if (ls == 0 && digit > d[i - 1]) {
              continue;
            }
            int new_ls = ls;
            if (digit < d[i - 1]) {
              new_ls = 1;
            }
            if (nz == 0 && digit == 0) {
              f[i - 1][nz][new_ls][mask] += ft;
              continue;
            }
            int new_nz = 1;
            int tmp_mask = 0;
            for (int j = 0; j < g.n; j++) {
              if (mask & (1 << j)) {
                tmp_mask |= go[j][digit];
              }
            }
            int new_mask = 0;
            for (int j = 0; j < g.n; j++) {
              if (tmp_mask & (1 << j)) {
                new_mask |= by_eps[j];
              }
            }
            f[i - 1][new_nz][new_ls][new_mask] += ft;
          }
        }
      }
    }
  }
  long long ans = 0;
  for (auto p : f[0][1][1]) {
    int mask = p.first;
    long long ft = p.second;
    if (mask & (1 << (g.n - 1))) {
      ans += ft;
    }
  }
  return ans;
}

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d: ", qq);
    long long from, to;
    cin >> from >> to;
    string s;
    cin >> s;
    Graph g = solve(s);
    cerr << g.n << " vertices... ";
/*    printf("%d %d\n", g.n, g.e.size());
    for (int i = 0; i < (int) g.e.size(); i++) {
      printf("%d %d %d\n", g.e[i].from, g.e[i].to, g.e[i].type);
    }
    printf("-----\n");*/
    cout << (get(g, to) - get(g, from - 1)) << endl;
    fprintf(stderr, "test case %d solved\n", qq);
    fflush(stderr);
  }
  return 0;
}
