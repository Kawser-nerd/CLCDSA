#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
	int n;
	cin >> n;
	vector<int> cost;
	auto accum = 0;
	auto x = 0;
	for (auto i=0; i<n; ++i) {
		int y;
		cin >> y;
		cost.push_back(x - y);
		accum += abs(x - y);
		x = y;
	}
	cost.push_back(x - 0);
	accum += abs(x - 0);

	for (auto i=0; i<n; ++i) {
		cout << (accum - abs(cost[i]) - abs(cost[i + 1]) + abs(cost[i] + cost[i + 1])) << endl;
	}
	return 0;
}