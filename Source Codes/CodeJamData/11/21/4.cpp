#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <cassert>
#include <queue>
#include <bitset>
#include <cmath>
#include <sstream>
#include <string>
#include <vector>
#include <ppl.h>

#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()

using namespace std;
using namespace Concurrency;

typedef pair<int, int> ii;
typedef long long int64;
typedef vector<int> vi;

template<class T> T abs(T x) {return x > 0 ? x : (-x); }
template<class T> T sqr(T x) {return x * x; }

critical_section criticalSection;

struct Problem {
	int problemId;
	// problem data
	int n;
	vector<vi> a;

	// some data
	vector<double> res;

	void read() {
		cin >> n;
		a = vector<vi>(n, vi(n, 0));
		for (int i = 0; i < n; ++i) {
			string s;
			cin >> s;
			for (int j = 0; j < n; ++j) {
				if (s[j] == '1') a[i][j] = 1;
				if (s[j] == '0') a[i][j] = -1;
			}
		}
	}

	double calcWp(int x, int y) {
		double res = 0.0;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			if (a[x][i] != 0 && i != y)
				++cnt, res += a[x][i] == 1 ? 1 : 0;
		res /= cnt;
		return res;
	}

	void solve() {
		criticalSection.lock();
		cerr << "Solving case " << problemId << "\n";
		criticalSection.unlock();
		vector<double> wp(n);
		for (int i = 0; i < n; ++i)
			wp[i] = calcWp(i, -1);
		vector<double> owp(n);
		for (int i = 0; i < n; ++i) {
			double cur = 0.0;
			double cnt = 0.0;
			for (int j = 0; j < n; ++j)
				if (i != j && a[i][j] != 0) cur += calcWp(j, i), cnt += 1.0;
			cur /= cnt;
			owp[i] = cur;
		}
		vector<double> oowp(n);
		for (int i = 0; i < n; ++i) {
			double cur = 0.0, cnt = 0.0;
			for (int j = 0; j < n; ++j)
				if (i != j && a[i][j] != 0)
					cur += owp[j], cnt += 1.0;
			cur /= cnt;
			oowp[i] = cur;
		}
		res.resize(n);
		for (int i = 0; i < n; ++i)
			res[i] = 0.25 * wp[i] + 0.50 * owp[i] + 0.25 * oowp[i];
	}

	void save() {
		printf("\n");
		for (int i = 0; i < n; ++i)
			printf("%.10lf\n", res[i]);
	}
};

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	int nc;
	cin >> nc;
	vector<Problem> problems(nc);
	for (int it = 0; it < nc; ++it) {
		problems[it].problemId = it;
		problems[it].read();
	}

	parallel_for_each(all(problems), 
		[&](Problem& p) {
			p.solve();
		}
	);	

	for (int it = 0; it < nc; ++it) {
		printf("Case #%d:", it + 1);
		problems[it].save();
	}
	return 0;
}
