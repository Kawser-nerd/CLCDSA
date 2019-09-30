#include <iostream>
#include <cassert>
#include <string>

using namespace std;

int solve() {
	int l;
	string s;
	cin >> l >> s;
	assert((int) s.size() == l + 1);
	int ans = 0;
	int sum = 0;
	for (int i = 0; i < l; i++) {
		sum += s[i] - '0';
		int delta = max(i + 1 - sum, 0);
		ans += delta;
		sum += delta;
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	assert(T >= 1 && T <= 100);
	for (int i = 0; i < T; i++)
		cout << "Case #" << (i+1) << ": " << solve() << endl;
	return 0;
}
