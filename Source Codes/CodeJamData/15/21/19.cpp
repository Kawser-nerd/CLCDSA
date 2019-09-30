#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll pw(int n) {
	ll r = 1;
	rep(i,0,n) r *= 10;
	return r;
}

string tos(ll n) {
	ostringstream oss;
	oss << n;
	return oss.str();
}

ll toi(string s) {
	ll n;
	istringstream iss(s);
	iss >> n;
	return n;
}

ll solve() {
	ll n;
	cin >> n;
	if (n <= 10) return n;

	ll p10 = 1;
	int digs = 0;
	while (p10 <= n) {
		digs++;
		p10 *= 10;
	}
	string srev = tos(n);
	assert(digs == sz(srev));
	reverse(all(srev));
	ll nrev = toi(srev);
cerr << n << ' ' << nrev << endl;

	ll res = 1; // "1"
	rep(i,0,digs) {
		ll prev = res;
		// go from 100000 with i zeroes, to either 1000000 with i+1 zeroes, or to n
		if (i+1 == digs) {
			if (n - (p10 / 10) < pw((digs + 1) / 2)) {
				res += n - (p10 / 10);
			}
			else if (n % pw((digs + 1) / 2) != 0) {
				res += nrev % pw(digs / 2); // + 1
				res++; // swap
				res += (n % pw((digs + 1) / 2)) - 1; // + 1
			}
			else {
				ll hi = n / pw((digs + 1) / 2);
				string s = tos(hi - 1);
				reverse(all(s));
				ll lo = toi(s);
				res += min(n - pw(digs-1), // + 1
						lo // + 1
						+ 1 // swap
						+ pw((digs + 1) / 2) - 1 // + 1
						);

				// cerr << "option is: " << lo << " " << 1 << " " << pw((digs + 1) / 2) - 1 << endl;
			}
		}
		else if (i == 0) {
			res += 9; // + 1
		}
		else {
			int ndigs = i + 1;
			res += pw((ndigs + 1) / 2) - 1; // + 1
			res++; // swap
			res += pw(ndigs / 2) - 2; // + 1
			res++; // + 1
		}

cerr << "add " << (res - prev) << endl;
	}

	return res;
}

int main() {
	int N;
	cin.sync_with_stdio(false);
	cin >> N;
	rep(i,0,N) {
		printf("Case #%d: %lld\n", i+1, solve());
	}
}
