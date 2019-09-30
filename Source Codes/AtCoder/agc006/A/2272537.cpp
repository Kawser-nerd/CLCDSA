#include<iostream>
#include<string>
using namespace std;
int main() {
	int n; string s, t;
	cin >> n >> s >> t;
	for (int i = n; i >= 0; i--) {
		if (s.substr(n - i, i) == t.substr(0, i)) {
			cout << 2 * n - i << endl;
			return 0;
		}
	}
	return 0;
}