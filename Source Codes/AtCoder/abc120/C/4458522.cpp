#include <iostream> 
#include <cmath>
#include <string>
using namespace std;





int main() {
	string s;
	cin >> s;

	int zero = 0;
	int one = 0;
	int total = 0;

	for (char c : s) {
		if (c == '0') {
			if (one > 0) {
				one --;
				total += 2;
			} else {
				zero++;
			}
		} else {
			if (zero > 0) {
				zero--;
				total += 2;
			} else {
				one++;
			}
		}
	}

	cout << total << endl;
	return 0;
}