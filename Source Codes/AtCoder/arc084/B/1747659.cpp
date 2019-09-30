#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
  int k;
  cin >> k;

  vector<bool> visited(k, false);
  typedef pair<int, int> pi;
  priority_queue<pi, vector<pi>, greater<pi> > que;

  int ans = 0;
  que.push(make_pair(0, 1));
  while (!que.empty()) {
    int cost = que.top().first;
	int mod = que.top().second;
	que.pop();

	if (visited[mod]) continue;
	visited[mod] = true;

	if (mod == 0) {
	  ans = cost + 1;
	  break;
	}

	que.push(make_pair(cost, (mod * 10) % k));
	que.push(make_pair(cost + 1, (mod + 1) % k));
  }

  cout << ans << endl;
  return 0;
}