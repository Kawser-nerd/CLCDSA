#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll solve() {
	int N, M;
	cin >> N >> M;
	vi ord(M);
	rep(i,0,M) ord[i] = i;
	vector<vi> amt(N, vi(M));
	vi sumi(N);
	ll sum = 0;
	rep(i,0,N) {
		rep(j,0,M) {
			cin >> amt[i][j];
			sum += amt[i][j];
			sumi[i] += amt[i][j];
		}
	}
	ll best = sum;
	do {
		ll st = 0;
		rep(i,0,N) {
			int s = -sumi[i];
			int sb = s;
			rep(j,0,M) {
				s += 2*amt[i][ord[j]];
				sb = max(sb, s);
			}
			st += sb;
		}
		best = max(best, st);
	} while(next_permutation(all(ord)));
	return sum + (best - sum) / 2;
}

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	rep(i,0,N) {
		cout << "Case #" << i + 1 << ": ";
		cout << solve() << endl;
	}
}
