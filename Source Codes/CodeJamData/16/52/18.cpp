#include <bits/stdc++.h>

using namespace std;

const int M = 120;
const int B = 10000;

int n;
string s;
vector<int> g[M];
bool up[M];
string t;
string f;
int sz[M];

random_device rd;
mt19937 mt(rd());
vector<uniform_int_distribution<unsigned long long>> dist;

void ini() {
  for (int i = 0; i <= 100; ++i)
    dist.push_back(uniform_int_distribution<unsigned long long>(0, i));
}

int rnd(int x) {
  return dist[x - 1](mt);
}

void read() {
  cin >> n;

  for (int i = 0; i < M; ++i) {
    g[i].clear();
    up[i] = false;
  }

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    --x;
    if (x >= 0) {
      up[i] = true;
      g[x].push_back(i);
    }
  }

  cin >> s;
}

void dfs(int v) {
  sz[v] = 1;
  for (int to : g[v]) {
    dfs(to);
    sz[v] += sz[to];
  }
}

void run(set<int> cur) {
  int sum = n;

  while (sum > 0) {
    int x = rnd(sum);

   // cerr << "round: ";
   // for (int x : cur)
   //   cerr << x << " ";
   // cerr << ", " << x << endl;

    for (int a : cur) {
      if (sz[a] <= x) {
        x -= sz[a];
        continue;
      }

      f.push_back(s[a]);
      cur.erase(a);
      for (int x : g[a])
        cur.insert(x);
      break;
    }

    --sum;
  }
}

int kill() {
  set<int> cur;
  for (int i = 0; i < n; ++i)
    if (!up[i]) {
      dfs(i);
      cur.insert(i);
    }

  int ans = 0;
  for (int _ = 0; _ < B; ++_) {
    f = "";

    run(cur);
    //cerr << f << "!" << endl;

    int x = 0;
    for (int i = 0; i + (int) t.length() <= n; ++i)
      if (f.substr(i, t.length()) == t)
        x = 1;
    ans += x;
  }

  return ans;
}

int main() {
  cout.precision(7);
  cout << fixed;
  ini();

  int T;
  cin >> T;
  for (int i = 1; i <= T; ++i) {
    cout << "Case #" << i << ": ";
    read();

    int m;
    cin >> m;
    while (m--) {
      cin >> t;
      cout << 1.0 * kill() / B << " ";
    }
    cout << endl;

    cerr << "Case #" << i << " done.\n";
  }
  return 0;
}
