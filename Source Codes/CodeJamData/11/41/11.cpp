#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

struct Way {
	double l, r;
	double speed;
	inline bool operator< (const Way &other) const {
		return l < other.l;
	}
};

double len;
double spwalk, sprun;
double runtime;
int n;
Way ways[1024];

struct Piece {
	double len;
	double speed;
	inline Piece(double _l = 0, double _s = 0) : len(_l), speed(_s) {}
	inline bool operator< (const Piece &other) const {
		return speed < other.speed;
	}
};
vector<Piece> arr;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%lf", &len);
		scanf("%lf%lf", &spwalk, &sprun);
		scanf("%lf", &runtime);
		scanf("%d", &n);
		for (int i = 0; i<n; i++) scanf("%lf%lf%lf", &ways[i].l, &ways[i].r, &ways[i].speed);

		sort(ways, ways+n);
		arr.clear();
		double prev = 0.0;
		for (int i = 0; i<n; i++) {
			arr.push_back(Piece(ways[i].l - prev, spwalk));
			arr.push_back(Piece(ways[i].r - ways[i].l, ways[i].speed + spwalk));
			prev = ways[i].r;
		}
		arr.push_back(Piece(len - prev, spwalk));
		
		double dv = sprun - spwalk;
		double ans = 0.0;

		sort(arr.begin(), arr.end());
		double rem = runtime;
		for (int i = 0; i<arr.size(); i++) {
			double fullrt = arr[i].len / (arr[i].speed + dv);
			double rt = min(rem, fullrt);
			
			ans += rt + (arr[i].len - (arr[i].speed + dv) * rt) / arr[i].speed;
			rem -= rt;
		}

		printf("Case #%d: %0.12lf\n", tt, ans);
		fflush(stdout);
	}
	return 0;
}
