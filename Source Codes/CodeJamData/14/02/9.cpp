#include<iostream>
#include<iomanip>

using namespace std;

int main() {
	cout << fixed << setprecision(7);

	int T; cin >> T;
	for(int t = 1; t <= T; t++) {
		double C, F, X; cin >> C >> F >> X;

		double res = X / 2;
		double time = 0;
		for(int i = 1; ; i++) {
			time += C / (2 + (i - 1) * F);
			double val = time + X / (2 + i * F);
			if(val > res) break;
			res = val;
		}
		cout << "Case #" << t << ": ";
		cout << res << '\n';
	}
}
