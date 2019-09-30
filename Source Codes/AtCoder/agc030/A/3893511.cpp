#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int main() {
	int A, B, C;
	cin >> A >> B >> C;

	int deliciousCookies = 0;

	if (C >= A) {
		deliciousCookies += A;
		C -= A;
		if (C > B) {
			deliciousCookies += 2 * B + 1;
		}
		else {
			deliciousCookies += C + B;
		}
	}
	else {
		deliciousCookies += C;
		deliciousCookies += B;
	}

	cout << deliciousCookies << endl;

	system("pause");
}