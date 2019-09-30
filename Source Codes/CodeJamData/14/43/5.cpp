#include<iostream>
#include<algorithm>
#include<queue>
#include<cassert>

using namespace std;

typedef long long ll;

typedef pair<ll, ll> pll;
typedef pair<pll, pll> rect; //stored as (x0, x1) and (y0, y1)

const ll INF = 1e18;

const int MAXB = 2e3;
int B;
ll W, H;
rect R[MAXB];
ll dist[MAXB][MAXB];

bool in(pll a, ll b) {
	return a.first <= b && b <= a.second;
}

ll rangeDist(pll a, pll b) {
	if(a.second < b.first) {
		return b.first - a.second - 1;
	} else if(b.second < a.first) {
		return a.first - b.second - 1;
	} else {
		return 0;
	}
}

ll rectDist(rect a, rect b) {
	return max(rangeDist(a.first, b.first), rangeDist(a.second, b.second));
}

ll minDist[MAXB];

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> W >> H >> B;
		R[0].first.first = -1;
		R[0].first.second = -1;
		R[0].second.first = 0;
		R[0].second.second = H - 1;
		for(int i = 1; i <= B; i++) {
			cin >> R[i].first.first >> R[i].second.first >> R[i].first.second >> R[i].second.second;
		}
		B++;
		R[B].first.first = W;
		R[B].first.second = W;
		R[B].second.first = 0;
		R[B].second.second = H - 1;
		for(int i = 0; i <= B; i++) {
			for(int j = 0; j <= B; j++) {
				dist[i][j] = rectDist(R[i], R[j]);
			}
		}
		priority_queue<pll, vector<pll>, greater<pll> > pq;
		for(int i = 0; i <= B; i++) minDist[i] = INF;
		minDist[0] = 0;
		pq.push(pll(minDist[0], 0));
		while(!pq.empty()) {
			ll d = pq.top().first;
			int loc = pq.top().second;
			pq.pop();
			if(loc == B) break;
			if(d != minDist[loc]) continue;
			assert(d >= 0);
			for(int j = 0; j <= B; j++) {
				ll nd = d + dist[loc][j];
				if(nd < minDist[j]) {
					minDist[j] = nd;
					pq.push(pll(minDist[j], j));
				}
			}
		}
		cout << "Case #" << t << ": " << minDist[B] << '\n';
	}
}
