#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
bool f(string s) { for (int i = 1; i < s.size(); i++)if (s[i] != s[0])return false; return true; }
int main() {
	string s; cin >> s;
	int ans = 114514;
	for (int i = 0; i < s.size(); i++) {
		string a, b;
		a = s;
		for (int j = 0; ; j++) {
			if (f(a)) {
				ans = min(ans, j);
				goto heaven;
			}
			for (int k = 0; k < a.size() - 1; k++) {
				if (a[k] == s[i] || a[k + 1] == s[i])b += s[i];
				else b += a[k];
			}
			a = b;
			b = "";
		}
	heaven:;
	}
	cout << ans << endl;
	cin >> s;
	return 0;
}