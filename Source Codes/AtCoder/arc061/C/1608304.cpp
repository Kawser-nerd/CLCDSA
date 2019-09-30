# include <iostream>
# include <algorithm>
# include <vector>
# include <string>
# include <set>
# include <map>
# include <cmath>
# include <iomanip>
# include <functional>
# include <utility>
# include <stack>
# include <queue>
# include <list>
using namespace std;
using LL = long long;
constexpr long long MOD = 1000000000 + 7;
constexpr long long INF = 1000000000;
const double PI = acos(-1);


long long int N, M, K, H, W, L, R;
multimap<pair<int, int>, pair<pair<int, int>, int>>edge;
map<pair<int, int>, int>dis;
priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>>PQ;


void dijkstra() {
	dis[{1, 0}] = 0;
	PQ.push({ 0,{ 1,0 } });
	while (!PQ.empty()) {
		auto cn = PQ.top().second;
		int c = PQ.top().first;
		PQ.pop();
		if (c > dis[cn])continue;
		auto m = edge.equal_range(cn);
		for (auto i = m.first; i != m.second; ++i) {
			if (dis.find(i->second.first) == dis.end()) {
				dis[i->second.first] = dis[cn] + i->second.second;
				PQ.push({ dis[i->second.first], i->second.first });
			}
			else if (dis[i->second.first] > dis[cn] + i->second.second) {
				dis[i->second.first] = dis[cn] + i->second.second;
				PQ.push({ dis[i->second.first], i->second.first });
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> L >> R >> K;
		edge.insert({ { L,K },{ { R,K },0 } });
		edge.insert({ { R,K },{ { L,K },0 } });
		edge.insert({ { L,0 },{ { L,K },1 } });
		edge.insert({ { R,0 },{ { R,K },1 } });
		edge.insert({ { R,K },{ { R,0 },0 } });
		edge.insert({ { L,K },{ { L,0 },0 } });
	}
	dijkstra();
	if (dis.find({ N,0 }) == dis.end()) {
		cout <<-1<<endl;
	}
	else {
		cout << dis[{N, 0}] << endl;
	}
}