#include <string>
#include <vector>
#include <cmath>
#include <cctype>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <utility>
#include <numeric>
#include <complex>

using namespace std;

int main(void)
{
  int T; cin >> T;
  for (int t = 1; t <= T; t++) {
    int ans = 0;
    set <string> have, want;
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
      string path; cin >> path;
      have.insert(path);
    }
    for (int i = 0; i < M; i++) {
      string path; cin >> path;
      want.insert(path);
      for (int j = 1; j < path.length(); j++)
	if (path[j] == '/')
	  want.insert(path.substr(0, j));
    }
    for (set <string>::iterator it = want.begin(); it != want.end(); it++)
      if (!have.count(*it))
	ans++;
    printf("Case #%d: %d\n", t, ans);
  }
}
