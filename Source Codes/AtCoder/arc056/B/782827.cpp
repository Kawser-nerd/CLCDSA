#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdlib>
#include <climits>

using namespace std;

int N,M,S;

vector<int> road[200010];
int cost[200010];

int main (int argc, char const *argv[])
{
  cin >> N >> M >> S;
  for (size_t i = 0; i < M; i++) {
    int u,v;
    // cin >> u >> v;
    scanf("%d %d\n",&u,&v);
    road[u].push_back(v);
    road[v].push_back(u);
  }

  set<int> visit;
  priority_queue<pair<int,int>> q;
  q.push(make_pair(S,S));
  cost[S] = S;

  while (!q.empty()) {
    auto f = q.top(); q.pop();
    auto x = f.second;

    if(visit.count(x)) continue;
    visit.insert(x);

    for (auto &&e:road[x]) {
      auto ncost = min(e, cost[x]);
      if(cost[e]<ncost) {
        cost[e] = ncost;
        q.push(make_pair(ncost,e));
      }
    }
  }

  for (size_t i = 1; i <= N; i++)
    if (cost[i]>=i) cout << i << endl;

  return 0;
}