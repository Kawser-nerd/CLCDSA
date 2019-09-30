#include <iostream>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;
int main() {
	string s;
	cin >> s;

	size_t ans = s.size();

	for (size_t i = 0; i < s.size() - 1; i++) {
		if (s[i] != s[i+1]) {
			ans = min(ans, max(i + 1, s.size() - i - 1));
		}
	}
	cout << ans << endl;
	return 0;
}