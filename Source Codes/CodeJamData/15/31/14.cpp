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

const int maxM = (1 << 20) + 10;

int r, c, w;
int dp[maxM];

int find (int mask) {
	int &res = dp[mask];
	if (res != -1) return res;
	res = 1e9;
	int cur = 0;
	vector <int> curs;
	for (int i = 0; i < c; i++)
		if (mask >> i & 1) {
			if (cur >= w) curs.push_back (cur);
			cur = 0;
		}
		else {
			res = min (res, find (mask + (1 << i)) + 1);
	//		cerr << "\tcalc " << mask << " from " << mask + (1 << i) << " -> " << res << endl;
			cur++;
		}
	if (cur >= w)
		curs.push_back (cur);

	if (curs.size() == 1)
		res = min (res, curs[0]);

	//cerr << "dp " << mask << ' ' << res << " --- ";
	//for (auto x : curs) cerr << x << ' ';
	//cerr << endl;
	return res;
}

void solve(stringstream &out) {
	cin >> r >> c >> w;
	int ans = (r - 1) * (c / w) + find (0);
	out << ans;
}

main() {
	ios::sync_with_stdio (false);

	int tests; cin >> tests;
	for (int o = 1; o <= tests; o++) {
		memset (dp, -1, sizeof dp);
		stringstream out;
		solve(out);
		cout << "Case #" << o << ": " << out.str() << endl; 
	}

	return 0;
}
