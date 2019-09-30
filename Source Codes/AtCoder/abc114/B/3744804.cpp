#include <cmath>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
	string s;
	cin >> s;
	int ans = 1000;
	for (int i = 2; i < s.size(); ++i) {
		ans = min(ans, abs(753 - stoi(s.substr(i - 2, 3))));
	}
	cout << ans << endl;
	return 0;
}