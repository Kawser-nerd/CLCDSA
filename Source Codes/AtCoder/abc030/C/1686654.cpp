#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
int main() {
	ll n, m, x, y; cin >> n >> m >> x >> y;
	queue<ll> a, b;
	for (int i = 0; i < n; i++) {
		ll k; cin >> k; a.push(k);
	}
	for (int i = 0; i < m; i++) {
		ll k; cin >> k; b.push(k);
	}
	ll now = 0;
	int cnt = 0;
	while (true) {
		while (a.size() && a.front() < now)a.pop();
		if (a.size() == 0)goto heaven;
		now = a.front() + x;
		a.pop();
		while (b.size() && b.front() < now)b.pop();
		if (b.size() == 0)goto heaven;
		now = b.front() + y;
		b.pop();
		cnt++;
	}
heaven:cout << cnt << endl;
	char c; cin >> c;
}