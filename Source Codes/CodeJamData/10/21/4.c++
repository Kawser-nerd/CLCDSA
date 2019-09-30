#include <cassert>
#include <cstdio>
#include <set>
#include <string>

using namespace std;

set <string> dirs;
int sum = 0;
char temp[1000];

void addDir( string const &dir ) {
  if (dirs.count(dir) != 0)
    return;
  sum++;
  dirs.insert(dir);
  int i = dir.length() - 1;
  while (dir[i] != '/')
    i--;
  addDir(dir.substr(0, i));
}

int main() {
  int tn;
  assert(scanf("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    int n, m;
    dirs.clear();
    dirs.insert("");
    assert(scanf("%d%d", &n, &m) == 2);
    for (int i = 0; i < n; i++)
      assert(scanf("%s", temp)), addDir(temp);
    sum = 0;
    for (int i = 0; i < m; i++)
      assert(scanf("%s", temp)), addDir(temp);
    printf("Case #%d: %d\n", tt, sum);
  }
  return 0;
}

