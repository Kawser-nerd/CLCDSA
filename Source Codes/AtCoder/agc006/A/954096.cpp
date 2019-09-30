#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	string s, t;
	bool ok = false;

	cin >> n >> s >> t;

	for (int i = 0; i < n; i++) {
		ok = true;
		for (int j = 0; j < n - i; j++) {
			if (s.at(j + i) != t.at(j)) {
				ok = false;
				break;
			}
		}
		if (ok) {
			cout << n + i << endl;
			return 0;
		}
	}

	cout << n + n << endl;
	return 0;
}