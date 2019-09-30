#include <iostream>
using namespace std;
 
int main() {
	int n; cin >> n; bool OK = false;
	for (int j = 0; j <= n / 4; j++) {
		for (int k = 0; k <= n / 7; k++) {
			if (4 * j + 7 * k == n) OK = true;
		}
	}
	if (OK == false) cout << "No" << endl;
	else cout << "Yes" << endl;
	return 0;
}