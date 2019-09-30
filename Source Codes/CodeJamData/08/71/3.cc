#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>
#include <cmath>
using namespace std;

map<string, int> mix;
int p[1005];
int nc[1005];
int ct = 1;
string m,ppp;
int mm,pp,M;
vector<int> c[1005];

bool ismix(string p) {
  return (p[0] >= 'A' && p[0] <= 'Z');
}

int _(string x) {
  if (mix[x] > 0) return mix[x];
  return mix[x] = ct++;
}

int go(int n) {
  //    printf("node %d\n", n);
  vector<int> res;
  for (int i = 0; i < c[n].size(); i++) {
    res.push_back(go(c[n][i]));
  }
  if (res.size() == 0) return 1;
  int ret = c[n].size() + 1;
  sort(res.rbegin(), res.rend());
  for (int i = 0; i < res.size(); i++) res[i] += i;
  sort(res.begin(), res.end());
  ret = max(ret, res[res.size()-1]);
  //  printf("node %d -> %d\n", n, ret);
  return ret;
}

int main() {
  int C, N;
  cin >> C;
  for (int i = 1; i <= C; i++) {
    cin >> N;

    ct = 1;
    mix.clear();
    memset(p, -1, sizeof(p));
    memset(nc, 0, sizeof(nc));
    for (int j = 0; j < 1005; j++) c[j].clear();

    for (int j = 0; j < N; j++) {
      cin >> m >> M;

      mm = _(m);

      for (int k = 0; k < M; k++) {
	cin >> ppp;
	if (ismix(ppp)) {
	  pp = _(ppp);

	  p[pp] = mm;
	  c[mm].push_back(pp);
	  nc[mm]++;
	}
      }
    }

    // find root
    int root = -1;
    for (int j = 1; j <= N; j++)
      if (p[j] == -1) {
	root = j;
	break;
      }

    printf("Case #%d: %d\n", i, go(root));
  }
}
