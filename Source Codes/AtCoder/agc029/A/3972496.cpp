#include <string>
#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	int cnt = 0; long long ans = 0;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == 'W') {
			ans += i - cnt;
			++cnt;
		}
	}
	cout << ans << endl;
	return 0;
}