#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int N;
	cin >> N;
	double OrigV, TargetTemp;
	cin >> OrigV >> TargetTemp;
	bool hasHotter = false, hasColder = false;
	vector<pair<double, double> > hot, cold;
	double sumw = 0;
	rep(i,0,N) {
		double v, X;
		cin >> v >> X;
		X -= TargetTemp;
		// X *= v;
		if (X >= 0) hasHotter = true;
		if (X <= 0) hasColder = true;
		if (X > 0)
			hot.emplace_back(-X, v);
		else if (X < 0)
			cold.emplace_back(X, v);
		sumw += v;
	}
	if (!hasHotter || !hasColder) {
		puts("IMPOSSIBLE");
		return;
	}

	sort(all(hot));
	sort(all(cold));
	double sum = 0;
	trav(pa, hot) sum -= pa.first * pa.second;
	trav(pa, cold) sum += pa.first * pa.second;

	if (sum < 0) { // too cold, pretend it's too hot instead
		sum = -sum;
		swap(hot, cold);
	}
	if (sum > 0) { // too hot!
		trav(pa, hot) {
			double x = -pa.first;
			sum -= x * pa.second;
			sumw -= pa.second;
			if (sum < 0) {
				sum += x * pa.second;
				sumw += pa.second;
				sumw -= sum / x;
				break;
			}
		}
	}

	printf("%.10lf\n", OrigV / sumw);
}

int main() {
	int N;
	cin.sync_with_stdio(false);
	cin >> N;
	rep(i,0,N) {
		printf("Case #%d: ", i+1);
		solve();
	}
}
