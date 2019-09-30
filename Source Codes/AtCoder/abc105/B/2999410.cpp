// B.

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int n;
	cin >> n;
	bool ans = false;
	for (int i = 0; i <= 100; ++i) {
		for (int j = 0; j <= 100; ++j) {
			if (i * 4 + j * 7 == n) {
				ans = true;
			}
		}
	}
	cout << (ans ? "Yes" : "No") << endl;
	return 0;
}