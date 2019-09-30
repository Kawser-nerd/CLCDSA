#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define int long long
int t[234567];
set<int>s;
signed main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a;
		t[a] = i;
	}
	int ans = 0;
	s.insert(0);
	s.insert(n + 1);
	for (int i = 1; i <= n; i++) {
		auto itr = s.upper_bound(t[i]);
		ans += i * (*itr - t[i])*(t[i] - *(--itr));
		s.insert(t[i]);
	}
	cout << ans << endl;
}