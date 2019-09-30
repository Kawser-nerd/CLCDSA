#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define Min(...) min({__VA_ARGS__})
#define Max(...) max({__VA_ARGS__})
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
static inline ll sgn(ll x) { return (x>0)-(x<0); }
static inline bool vowel(char c) { c = (char)tolower(c); return c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or c == 'y'; }
static inline vi rvi(int N) { vi res(N); rep(i,0,N) cin >> res[i]; return res; }
static inline int ri() { int N; cin >> N; return N; }
static inline void pvi(const vi& r) { trav(it,r) cout << it << " "; cout << endl; }
template<class S, class T> static inline void smax(S& s, const T& t) { if (t > s) s = t; }
template<class S, class T> static inline void smin(S& s, const T& t) { if (t < s) s = t; }
template<class S> static inline void in(S& s) { cin >> s; }
template<class S> static inline void ut(const S& s) { cout << s << " "; }
static inline void nl() { cout << endl; }

int sol(int N, int R, int C, const vector<vi>& ts) {
	vector<int> avail(C);
	rep(i,0,C) avail[i] = R;
	int ans = 0;
	queue<int> ppl;
	for (int i = N - 1; i >= 0; --i) {
		int left = R;
		trav(buyer, ts[i]) {
			if (avail[buyer] && left) {
				--avail[buyer];
				--left;
			} else {
				ppl.push(buyer);
			}
		}
		while (left && !ppl.empty()) {
			int nx = ppl.front(); ppl.pop();
			if (!avail[nx]) return -1;
			--left;
			--avail[nx];
			++ans;
		}
	}
	if (sz(ppl)) return -1;
	return ans;
}

void solve() {
	int N, C, M;
	cin >> N >> C >> M;
	vector<vi> tickets(N);
	rep(i,0,M) {
		int pos, buy;
		cin >> pos >> buy;
		--pos; --buy;
		tickets[pos].push_back(buy);
	}
	int lo = 0;
	int hi = M;
	while (hi - lo > 1) {
		int mid = (lo + hi) / 2;
		int ans = sol(N, mid, C, tickets);
		if (ans != -1) {
			hi = mid;
		} else lo = mid;
	}
	cout << hi << " " << sol(N, hi, C, tickets) << endl;
}

signed main() {
	cin.sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	int TC;
	cin >> TC;
	rep(i,0,TC) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}
