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
	int n, d;
	vector<ii> v;
	// some data
	double res;

	void read() {
		cin >> n >> d;
		v.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i].first >> v[i].second;
		}
	}

	bool check(double t) {
		double cur = -1E100;
		for (int i = 0; i < sz(v); ++i) {
			for (int j = 0; j < v[i].second; ++j) {
				cur = max(cur + d, v[i].first - t);
				if (cur > v[i].first + t) return false;
			}
		}
		return true;
	}

	void solve() {
		criticalSection.lock();
		cerr << "Solving case " << problemId << "\n";
		criticalSection.unlock();
		sort(all(v));
		double up = 1E57, down = 0.0;
		for (int it = 0; it < 300; ++it) {
			double t = (up + down) * 0.5;
			if (check(t)) up = t;
			else down = t;
		}
		res = (up + down) * 0.5;
	}

	void save() {
		printf("%.10lf\n", res);
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
		printf("Case #%d: ", it + 1);
		problems[it].save();
	}
	return 0;
}
