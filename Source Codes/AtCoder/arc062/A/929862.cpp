#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	int n, a, b;
	unsigned long long va, vb;
	unsigned long long aa, bb;
	cin >> n;
	cin >> va >> vb;

	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		aa = va / a;
		if (va % a != 0) {
			aa++;
		}

		bb = vb / b;
		if (vb % b != 0) {
			bb++;
		}

		if (aa > bb) {
			va = aa * a;
			vb = aa * b;
		}
		else {
			va = bb * a;
			vb = bb * b;
		}
	}
	cout << va + vb << endl;
}