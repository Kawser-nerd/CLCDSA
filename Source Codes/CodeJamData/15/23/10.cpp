#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef pair<ll, ll> pll;
#define A first
#define B second

const int MAXG = 1000;
const int MAXN = 1e6;

const ll C = 360; // complete circle

int G;
int N;

ll D[MAXN];
ll M[MAXN];

int go() {
	int res = N;
	int cnt = N;
	priority_queue<pll, vector<pll>, greater<pll> > pq;

	ll end = 0;
	for(int i = 0; i < N; i++) {
		end = max(end, (C - D[i]) * M[i]);
		pq.push(pll((C - D[i]) * M[i], C * M[i]));
	}

	while(pq.top().first <= end && cnt <= N * 2) {
		ll t = pq.top().first;
		while(pq.top().first <= t) {
			pll v = pq.top(); pq.pop();

			if(v.A < v.B) cnt--;
			else cnt++;

			v.A += v.B;
			pq.push(v);
		}
		res = min(res, cnt);
	}

	assert(res <= N - 1);

	//assert(res == slow());
	return res;
}

int main() {
	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		cin >> G;
		N = 0;
		for(int i = 0; i < G; i++) {
			ll d, h, m; cin >> d >> h >> m;
			for(int j = 0; j < h; j++) {
				D[N] = d;
				M[N] = m;
				N++;
				m++;
			}
		}

		int res = go();
		cout << "Case #" << t << ": " << res << '\n';
	}

	return 0;
}
