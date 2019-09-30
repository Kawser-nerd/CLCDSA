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

tuple<ll, string, string> sol;

string stra, strb;
void rec(string& tempa, string& tempb, int at, ll dif) {
	// cout << "at " << at << ' ' << tempa << ' ' << tempb << ' ' << dif << endl;
	if (at == sz(stra)) {
		sol = min(sol, make_tuple(abs(dif), tempa, tempb));
		return;
	}
	dif *= 10;
	if (dif == 0) {
		if (stra[at] == '?' && strb[at] == '?') {
			tempa[at] = '0';
			tempb[at] = '0';
			rec(tempa, tempb, at+1, dif);

			tempa[at] = '0';
			tempb[at] = '1';
			rec(tempa, tempb, at+1, dif - 1);

			tempa[at] = '1';
			tempb[at] = '0';
			rec(tempa, tempb, at+1, dif + 1);
		}
		else if (stra[at] == '?') {
			tempa[at] = strb[at];
			rec(tempa, tempb, at+1, dif);

			if (strb[at] != '0') {
				tempa[at] = (char)(strb[at] - 1);
				rec(tempa, tempb, at+1, dif - 1);
			}

			if (strb[at] != '9') {
				tempa[at] = (char)(strb[at] + 1);
				rec(tempa, tempb, at+1, dif + 1);
			}
		}
		else if (strb[at] == '?') {
			tempb[at] = stra[at];
			rec(tempa, tempb, at+1, dif);

			if (stra[at] != '0') {
				tempb[at] = (char)(stra[at] - 1);
				rec(tempa, tempb, at+1, dif + 1);
			}

			if (stra[at] != '9') {
				tempb[at] = (char)(stra[at] + 1);
				rec(tempa, tempb, at+1, dif - 1);
			}
		}
		else {
			rec(tempa, tempb, at+1, dif + stra[at] - strb[at]);
		}
	}
	else if (dif < 0) {
		if (stra[at] == '?') tempa[at] = '9';
		if (strb[at] == '?') tempb[at] = '0';
		rec(tempa, tempb, at+1, dif + tempa[at] - tempb[at]);
	}
	else if (dif > 0) {
		if (stra[at] == '?') tempa[at] = '0';
		if (strb[at] == '?') tempb[at] = '9';
		rec(tempa, tempb, at+1, dif + tempa[at] - tempb[at]);
	}
}

void solve() {
	cin >> stra >> strb;
	string tempa = stra, tempb = strb;
	sol = make_tuple(1LL << 62, string(), string());
	rec(tempa, tempb, 0, 0);
	cout << get<1>(sol) << ' ' << get<2>(sol) << endl;
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
