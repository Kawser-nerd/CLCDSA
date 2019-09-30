#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	int n;
	cin >> n;

	vector<int> a(n);
	for (auto& e : a) cin >> e;

	int cost = 0;
	a.insert(a.begin(), 0);
	a.push_back(0);

	vector<int> m;
	for (int i = 1; i < n + 1; i++) {
		cost += abs(a[i] - a[i-1]);
		m.push_back(abs(a[i] - a[i-1]) + abs(a[i+1]-a[i]) - abs(a[i+1]-a[i-1]));
	}
	cost += abs(0 - a[n]);

	for (auto i : m) {
		cout << cost - i << endl;
	}
	return 0;
}