#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;
signed main() {
	int n, ans = 0; cin >> n;
	for (int i = 0; i < n; i++) {
		int p; cin >> p;
		ans += p - 1;
	}
	cout << ans << endl;
}