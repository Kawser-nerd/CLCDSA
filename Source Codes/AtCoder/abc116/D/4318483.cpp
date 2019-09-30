#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int MAX = 1e5 + 9;
const long long INF = 1e18 + 9;

bool cmp(const pair<long long, int> &a, const pair<long long, int> &b) {
	return a.first > b.first;
}

pair<long long, int> a[MAX];
int kind[MAX];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i].second >> a[i].first;
	}
	sort(a, a + n, cmp);
	/*
	for (int i = 0; i < n; i++) {
		auto sushi = a[i];
		cerr << sushi.first << ' ' << sushi.second << '\n';
	}
	cerr << '\n';
	*/
	multiset<pair<long long, int>> s, b;
	int cnt = 0;
	long long sum = 0;
	for (int i = 0; i < k; i++) {
		if (!kind[a[i].second]) {
			cnt++;
			s.insert(make_pair(INF, a[i].second));
		} else {
			s.insert(a[i]);
		}
		kind[a[i].second]++;
		sum += a[i].first * 1LL;
	}
	for (int i = k; i < n; i++) {
		b.insert(make_pair(-a[i].first, a[i].second));
	}
//	cerr << cnt << ' ' << sum << '\n';
	long long ret = cnt * cnt * 1LL + sum * 1LL;
	while (!b.empty() && (*s.begin()).first != INF) {
		if (!kind[(*b.begin()).second]) {
			sum -= (*s.begin()).first * 1LL;
			sum -= (*b.begin()).first * 1LL;
			kind[(*s.begin()).second]--;
			kind[(*b.begin()).second]++;
			s.erase(s.begin());
			cnt++;
			s.insert(make_pair(INF, (*b.begin()).second));
			ret = max(ret, cnt * cnt * 1LL + sum * 1LL) * 1LL;
			/*
			for (auto sushi : s) {
				cerr << sushi.first << ' ' << sushi.second << '\n';
			}
			cerr << '\n';
			*/
		}
		b.erase(b.begin());
	}
	//cerr << cnt << ' ' << sum << '\n';
	cout << ret << '\n';
	
	return 0;
}