#include<iostream>
using namespace std;
int main() {
	int a, b, c, d, e, f; cin >> a >> b >> c >> d >> e >> f;
	double ans1 = 0, ans2 = 0;
	for (int i = 0; i <= f / (100 * a); i++) {
		for (int j = 0; j <= f / (100 * b); j++) {
			for (int k = 0; k <= 100; k++) {
				for (int l = 0; l <= 100; l++) {
					double w = (a*i + b*j) * 100, s = k*c + l*d;
					if (w + s <= f&&w / 100 * e >= s) {
						if (ans2 == 0 || s / (w / 100 * e) > ans2 / (ans1 / 100 * e)) {
							ans1 = w; ans2 = s;
						}
					}
				}
			}
		}
	}
	cout << ans1 + ans2 << ' ' << ans2 << endl;
	return 0;
}