#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < (to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
void PR(vi &v) { trav(x, v) cout << x << ' '; cout << endl; }

vector<int> match;
vector<bool> seen;
template<class G>
bool find(int j, G &g) {
	if (match[j] == -1) return 1;
	seen[j] = 1; int di = match[j];
	trav(e, g[di])
		if (!seen[e] && find(e, g)) {
			match[e] = di;
			match[j] = -1;
			return 1;
		}
	return 0;
}
template<class G>
int dfs_matching(G &g, int n, int m) {
	match.assign(m, -1);
	rep(i,0,n) {
		seen.assign(m, false);
		trav(j,g[i])
			if (find(j, g)) {
				match[j] = i;
				break;
			}
	}
	return m - (int)count(all(match), -1);
}

void solve() {
	int N;
	cin >> N;
	int Numa = 0, Numb = 0;
	map<string, int> luta, lutb;
	vector<pii> ed;
	rep(i,0,N) {
		string a, b;
		cin >> a >> b;
		int& ia = luta[a];
		int& ib = lutb[b];
		if (!ia) ia = ++Numa;
		if (!ib) ib = ++Numb;
		ed.emplace_back(ia, ib);
	}
	vector<vi> gr(Numa);
	trav(pa, ed) {
		gr[pa.first - 1].push_back(pa.second - 1);
	}
	int s = dfs_matching(gr, Numa, Numb);
	cout << N - (Numa + Numb - s) << endl;
}

int main() {
	cin.sync_with_stdio(false);
	cin.tie(0);
	int N;
	cin >> N;
	rep(i,0,N) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}
