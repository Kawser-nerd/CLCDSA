#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

double p[57];

void solve() {
	int n, k;
	cin >> n >> k;
	double U;
	cin >> U;
	for(int i = 1; i <= n; ++i) cin >> p[i];
	double pp = 0.0;
	double kk = 1.0;
	double re = 0.0;
	for(int it = 0; it < 80 && pp < kk; ++it) {
		double ss = (pp + kk) * 0.5;
		double il = 0.0;
		for(int i = 1; i <= n; ++i) {
			il += max(0.0, ss - p[i]);
		}
		if(il <= U) {
			re = ss;
			pp = ss;
		}
		else kk = ss;
	}
	
	double wynik = 1.0;
	for(int i = 1; i <= n; ++i) wynik *= max(re, p[i]);
	cout << wynik << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cout.precision(10);
	cout << fixed;
	int tt;
	cin >> tt;
	for(int it = 1; it <= tt; ++it) {
		cout << "Case #" << it << ": ";
		solve();
	}	
	return 0;
}
