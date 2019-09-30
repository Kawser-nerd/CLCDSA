#include <string>
#include <iostream>
using namespace std;
int main() {
	string s;
	cin >> s;
	if (s.size() != 26) {
		for (char c = 'a'; c <= 'z'; ++c) {
			if (s.find(c) == string::npos) {
				cout << s + c << endl;
				break;
			}
		}
	}
	else {
		string ans;
		for (int i = s.size() - 1; i >= 0 && ans.empty(); --i) {
			int rem = 'z' - s[i];
			for (int j = 0; j < i; ++j) {
				if (s[j] > s[i]) --rem;
			}
			if (rem > 0) {
				for (char j = s[i] + 1; j <= 'z'; ++j) {
					if (s.substr(0, i).find(j) == string::npos) {
						ans = s.substr(0, i) + j;
						break;
					}
				}
			}
		}
		if (ans.empty()) cout << -1 << endl;
		else cout << ans << endl;
	}
	return 0;
}