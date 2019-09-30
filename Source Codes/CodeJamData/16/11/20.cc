#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int T, prob=1;
	for (cin >> T; T--;) {
		cout << "Case #" << prob++ << ": ";

		string s;
		cin >> s;
		vector<int> left(s.size());
		int x = s.size();
		while (x > 0) {
			int cur = x, curlet = 0;
			for (int i = x-1; i >= 0; i--) if (s[i] > curlet) {
				curlet = s[i];
				cur = i;
			}
			left[cur] = true;
			x = cur;
		}

		string ret;
		for (int i = 0; i < s.size(); i++) {
			if (left[i]) ret = s[i] + ret; else ret += s[i];
		}
		cout << ret << endl;
	}
}
