#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

// Recycled Numbers

int main()
{
	string line;

	int cases;
	cin >> cases;

	for (int caseno = 1; caseno <= cases; caseno++) {
		int A, B;
		cin >> A >> B;
		long long ret = 0;
		for (int n = A; n <= B; n++) {
			int x = n;
			int d = 1;
			while (x) {
				x /= 10;
				d *= 10;
			}
			d /= 10;
			x = n;
			do {
				x = x / 10 + (x % 10) * d;
				if (x > n && x <= B) {
					ret++;
				}
			} while (x != n);
		}
		cout << "Case #" << caseno << ": " << ret << endl;
	}

	return 0;
}
