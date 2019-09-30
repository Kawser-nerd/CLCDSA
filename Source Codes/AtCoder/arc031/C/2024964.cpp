#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int n, p[100009], ip[100009], bit[100009];
void add(int pos, int val) {
	for (int i = pos + 1; i <= n; i += i & (-i)) bit[i] += val;
}
int sum(int pos) {
	int ret = 0;
	for (int i = pos; i >= 1; i -= i & (-i)) ret += bit[i];
	return ret;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> p[i], p[i]--, ip[p[i]] = i, add(i, 1);
	long long ret = 0;
	for (int i = 0; i < n; i++) {
		int res = sum(ip[i]); add(ip[i], -1);
		ret += min(res, n - i - res - 1);
	}
	cout << ret << endl;
	return 0;
}