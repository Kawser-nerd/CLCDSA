#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000;
const int N = 777;

long double total;
int n;

long double fact[N];
int p[N];
char names[N];
int sub[N];
string cool[N];
bool known[N];
vector <int> g[N];
int ways[N];

long double dfs(int v) {
  long double ans = 1.0;
  int sz = g[v].size();
  sub[v] = 1;
  vector <int> chi;
  for (int j = 0; j < sz; j++) {
    int u = g[v][j];
    ans *= dfs(u);
    sub[v] += sub[u];
    ans /= fact[sub[u]];
  }
  ans *= fact[sub[v] - 1];
  return ans;
}

long double calc() {
  for (int i = 0; i <= n; i++) {
    g[i].clear();
  }
  for (int i = 0; i < n; i++) {
    if (known[i]) {
      continue;
    }
    if (p[i] == -1 || known[p[i]]) {
      g[n].push_back(i);
    } else {
      g[p[i]].push_back(i);
    }
  }
  return dfs(n);
}

string get_random() {
  string res = "";
  for (int i = 0; i < n; i++) {
    known[i] = false;
  }
  long double id = (1.0 * rand() / (RAND_MAX + 1)) * total;
  long double all = total;
  for (int it = 0; it < n; it++) {
    bool found = false;
    for (int i = 0; i < n; i++) {
      if (known[i]) {
        continue;
      }
      if (p[i] != -1 && !known[p[i]]) {
        continue;
      }
      known[i] = true;
      long double cur = all / (n - it) * sub[i]; //calc();
//      cerr << "cur = " << (double)cur << " for i = " << i << ", while id = " << (double)id << endl;
//      cerr << "is cur > id? " << (cur > id) << endl;
      if (cur > id) {
        res += names[i];
        found = true;
        all = cur;
        break;
      } else {
        id -= cur;
        known[i] = false;
      }
    }
//    cerr << "id = " << (double)id << ", it = " << it << ", known = " << known[0] << " " << known[1] << " " << known[2] << " " << known[3] << ", found = " << found << endl;
    assert(found);
  }
  return res;
}

int main() {
  srand(8753);
  fact[0] = 1;
  for (int i = 1; i < N; i++) {
    fact[i] = fact[i - 1] * i;
  }
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  int tt;
  scanf("%d", &tt);
  for (int qq = 1; qq <= tt; qq++) {
    printf("Case #%d:", qq);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      scanf("%d", p + i);
      p[i]--;
    }
    scanf("%s", names);
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      cin >> cool[i];
      ways[i] = 0;
    }
    for (int i = 0; i <= n; i++) {
      known[i] = false;
    }
    total = calc();
    cerr << "total = " << (double)total << endl;
    for (int i = 0; i < MAX; i++) {
      string z = get_random();
      for (int j = 0; j < m; j++) {
        if (z.find(cool[j]) != string::npos) {
          ways[j]++;
        }
      }
    }
    for (int i = 0; i < m; i++) {
      printf(" %.17f", ways[i] * 1.0 / MAX);
    }
    printf("\n");
    fflush(stdout);
    cerr << "test case " << qq << " out of " << tt << " done" << endl;
  }
  return 0;
}
