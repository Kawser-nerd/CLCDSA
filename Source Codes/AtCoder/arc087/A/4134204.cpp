#include <map>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	int N;
	cin >> N;
	map<int, int> d;
	for (int i = 0; i < N; ++i) {
		int x;
		cin >> x;
		++d[x];
	}
	int ans = 0;
	for (pair<int, int> i : d) {
		if (i.second >= i.first) ans += i.second - i.first;
		else ans += i.second;
	}
	cout << ans << endl;
	return 0;
}