#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1000;
pair <int, int> tab[N + 7];

void solve() {
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; ++i) cin >> tab[i].first >> tab[i].second;
	sort(tab + 1, tab + n + 1);
	vector <double> T;
	double wynik = 0.0;
	
	for(int i = 1; i <= n; ++i) {
		double res = tab[i].first;
		res *= tab[i].first;
		for(int j = 0; j < k - 1 && j < (int) T.size(); ++j) res += T[j];
		double pp = 2.0 * tab[i].first;
		pp *= tab[i].second;
		res += pp;
		wynik = max(wynik, res);
		T.push_back(pp);
		sort(T.begin(), T.end(), greater <double> ());
	}
	wynik *= M_PI;
	cout << wynik;
}

int main() {
	ios_base::sync_with_stdio(0);
	int tt;
	cin >> tt;
	cout.precision(10);
	cout << fixed;
	for(int it = 1; it <= tt; ++it) {
		cout << "Case #" << it << ": ";
		solve();
		cout << endl;
	}
	return 0;
}
