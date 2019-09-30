#include <iostream>

using namespace std;

int main() {
	int n;
	int k;
	cin >> n;
	cin >> k;

	int val = 1;

	while(n--) {
		if(val * 2 < val + k) {
			val *= 2;
		} else {
			val += k;
		}
	}

	cout << val << endl;

	return 0;
}