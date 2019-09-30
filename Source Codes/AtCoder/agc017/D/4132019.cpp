#include <set>
#include <vector>
#include <iostream>
using namespace std;
vector<vector<int> > G;
int calc(int pos, int pre) {
	int ans = 0;
	for (int i : G[pos]) {
		if (i != pre) {
			ans ^= calc(i, pos) + 1;
		}
	}
	return ans;
}
int main() {
	int N;
	cin >> N;
	G.resize(N);
	for (int i = 0; i < N - 1; ++i) {
		int x, y;
		cin >> x >> y; --x, --y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	int ans = calc(0, -1);
	cout << (ans ? "Alice" : "Bob") << endl;
	return 0;
}