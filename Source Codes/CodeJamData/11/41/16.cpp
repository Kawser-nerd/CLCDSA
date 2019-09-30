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

struct T{ 
	int l, w;
	friend bool operator <(const T &a, const T &b) {
		return a.w < b.w;
	}
};

void solve(int testnum) {
	int x, s, r, t, n;
	scanf("%d%d%d%d%d", &x, &s, &r, &t, &n);
	vector<T> a(n + 1);
	int normal_dst = x;
	for (int i = 0; i < n; ++i) {
		int start, finish;
		scanf("%d%d%d", &start, &finish, &a[i].w);
		a[i].l = finish - start;
		normal_dst -= a[i].l;
	}
	a[n].l = normal_dst;
	a[n].w = 0;
	sort(all(a));
	double T = 0;
	double running_time = t;
	for (int i = 0; i <= n; ++i) {
		double max_t = (a[i].l + 0.0) / (r + a[i].w + 0.0);
		double time_to_run = min(running_time, max_t);
		T += time_to_run + (a[i].l - (r + a[i].w) * time_to_run + 0.0) / (s + a[i].w + 0.0);
//		printf("%.2lf\n", (a[i].l - (r + a[i].w) * time_to_run + 0.0) / (s + a[i].w + 0.0));
		running_time -= time_to_run;
	}
	printf("Case #%d: %.10lf\n", testnum, T);
	//adding normal distance

}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) solve(i + 1);
	return 0;
}
