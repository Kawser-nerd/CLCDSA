#include <cmath>
#include <vector>
#include <iomanip>
#include <iostream>
#include <algorithm>
using namespace std;
const double pi = 3.14159265358979323;
int n, x[109], y[109];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
	for (int i = 0; i < n; i++) {
		vector<double> ar(n - 1);
		for (int j = 1; j < n; j++) ar[j - 1] = atan2(y[(i + j) % n] - y[i], x[(i + j) % n] - x[i]);
		double res = 1.0e+9;
		for (int j = 0; j < n - 1; j++) {
			double val = 0.0;
			for (int k = 0; k < n - 1; k++) {
				val = max(val, fmod(ar[k] - ar[j] + pi * 2 + 1.0e-8, pi * 2));
			}
			res = min(res, val);
		}
		if (res > pi) cout << 0 << endl;
		else cout << fixed << setprecision(15) << (pi - res) / (pi * 2) << endl;
	}
	return 0;
}