#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	long long ans = 1;
	map < char, int > cnt;
	for (int i = n - 1; i >= 0; i--) {
		cnt[s[i]]++;
		ans += i + 1;
		ans -= cnt[s[i]];
	}
cout << ans << endl;
}