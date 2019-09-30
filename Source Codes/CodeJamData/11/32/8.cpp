#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#define pb push_back
#define mp make_pair
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T a) {return a > 0 ? a : (-a); }
template<class T> T sqr(T a) {return a * a; }

using namespace std;

void solve() {
	int L, n, c;
	long long t;
	cin >> L >> t >> n >> c;
	vector<int> a(n);
	for (int i = 0; i < c; ++i)
		scanf("%d", &a[i]);
	for (int i = c; i < n; ++i) a[i] = a[i - c];
	vector<long long> abs_time(n + 1);
	abs_time[0] = 0;
	for (int i = 1; i <= n; ++i) abs_time[i] = abs_time[i - 1] + a[i - 1] * 2;
	vector<long long> delta;
	for (int i = 0; i < n; ++i) {
		if (abs_time[i] >= t) {
			delta.pb(a[i] * 2);
		} else
		if (abs_time[i + 1] >= t) {
			long long total = a[i] * 2;
			long long saved_dst = total - (t - abs_time[i]);
			delta.pb(saved_dst);
		}
	}
	long long total_time = abs_time[n];
	long long save_time = 0;
	sort(all(delta));
	reverse(all(delta));
	for (int i = 0; i < L && i < sz(delta); ++i) {
		save_time += delta[i];
	}
	if (save_time % 2 != 0) cerr << "BUG" << endl;
//	cout << total_time << " " << save_time << endl;
	cout << total_time - save_time / 2 << endl;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		cerr << i << endl;
		cout << "Case #" << i << ": ";
		solve();
	}
}
