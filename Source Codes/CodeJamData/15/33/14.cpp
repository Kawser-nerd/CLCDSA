#include <bits/stdc++.h>

using namespace std;

#define int long long

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))

typedef long long ll;
typedef pair <int, int> pie;

int c, d, v;

void solve(stringstream &out) {
	cin >> c >> d >> v;
	vector <int> a;
	for (int i = 0, x; i < d; i++) cin >> x, a.push_back (x);
	sort (a.begin(), a.end());
	int lim = 1, res = 0;
	for (auto x : a) {
		while (x > lim && lim <= v)
			res++, lim *= (c + 1);
		lim += c * x;
		if (lim > v) break;
	}
	while (lim <= v)
		res++, lim *= (c + 1);
	out << res;
}

main() {
	ios::sync_with_stdio (false);

	int tests; cin >> tests;
	for (int o = 1; o <= tests; o++) {
		stringstream out;
		solve(out);
		cout << "Case #" << o << ": " << out.str() << endl; 
	}

	return 0;
}
