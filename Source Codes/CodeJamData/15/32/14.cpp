#include <bits/stdc++.h>

using namespace std;

#define int long long

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define sqr(x) ((x)*(x))
#define next shit

typedef long long ll;
typedef pair <int, int> pie;

const int maxN = 100 + 10;

int k, l, s;
string K, L;

double rem[maxN][maxN];
int best[maxN][maxN];

int next[maxN][maxN];
int gift[maxN][maxN];

void solve(stringstream &out) {
	cin >> k >> l >> s;
	cin >> K >> L;

	for (int i = 0; i < l; i++)
		for (int j = 0; j < k; j++) {
			string tmp = L.substr (0, i) + K.substr (j, 1);
			int match = tmp.size();
			bool whole = false;
			for (; match >= 0; match--)
				if (L.substr (0, match) == tmp.substr ((int)tmp.size() - match))
					if (match == l) whole = true;
					else break;
			gift[i][j] = whole;
			next[i][j] = match;
//			cerr << i << ' ' << j << ' ' << next[i][j] << ' ' << gift[i][j] << endl;
		}

	for (int i = 0; i < l; i++) rem[s][i] = best[s][i] = 0;

	for (int i = s - 1; i >= 0; i--)
		for (int j = 0; j < l; j++) {
			for (int k = 0; k < ::k; k++) {
				best[i][j] = max (best[i][j], best[i + 1][next[j][k]] + gift[j][k]);
				rem[i][j] += (rem[i + 1][next[j][k]]+ (double)(gift[j][k])) / (double)::k;
//				cerr << "\t" << i << ' ' << j << ' ' << k << ' ' << next[j][k] << ' ' << gift[j][k] << endl;
			}
//			cerr << i << ' ' << j << ' ' << best[i][j] << ' ' << rem[i][j] << endl;
		}

	out << fixed << setprecision(10) << best[0][0] - rem[0][0];
}

main() {
	ios::sync_with_stdio (false);

	int tests; cin >> tests;
	for (int o = 1; o <= tests; o++) {
		stringstream out;
		solve(out);
		cout << "Case #" << o << ": " << out.str() << endl; 
		memset (next, 0, sizeof next);
		memset (gift, 0, sizeof gift);
		memset (best, 0, sizeof best);
		for (int i = 0; i < maxN; i++)
			for (int j = 0; j < maxN; j++) rem[i][j] = 0;
	}

	return 0;
}
