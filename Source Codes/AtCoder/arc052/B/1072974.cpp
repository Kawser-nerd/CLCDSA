#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <numeric>
#include <algorithm>
#include <functional>
#include <array>
#include <map>
#include <queue>
#include <limits.h>
#include <set>
#include <stack>
#include <random>
#include <complex>
#include <unordered_map>
#define rep(i,s,n) for(int i = (s); (n) > i; i++)
#define REP(i,n) rep(i,0,n)
#define RANGE(x,a,b) ((a) <= (x) && (x) <= (b))
#define DUPLE(a,b,c,d) (RANGE(a,c,d) || RANGE(b,c,d) || RANGE(c,a,b) || RANGE(d,a,b))
#define INCLU(a,b,c,d) (RANGE(a,c,d) && (b,c,d))
#define PW(x) ((x)*(x))
#define ALL(x) (x).begin(), (x).end()
#define RALL(x) (x).rbegin(), (x).rend()
#define MODU 1000000007
#define bitcheck(a,b)   ((a >> b) & 1)
#define bitset(a,b)      ( a |= (1 << b))
#define bitunset(a,b)    (a &= ~(1 << b))
#define MP(a,b) make_pair((a),(b))
#define Manh(a,b) (abs((a).first-(b).first) + abs((a).second - ((b).second))
#define pritnf printf
#define scnaf scanf
#define itn int
#define PI 3.141592653589
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
template<typename A, size_t N, typename T>
void Fill(A(&array)[N], const T &val) {
	std::fill((T*) array, (T*) (array + N), val);
}
pii Dir [] = {
	{ 1,0 },{ 0,1 }
};

signed main() {
	int n, q;
	scanf("%d %d", &n, &q);

	vector<pair<pii, int>> ensui(n);
	REP(i, n) {
		scanf("%d %d %d", &ensui[i].first.first, &ensui[i].second, &ensui[i].first.second);
		ensui[i].first.second += ensui[i].first.first;
	}

	REP(i, q) {
	double ans = 0;
		int a, b;
		scnaf("%d %d", &a, &b);

		REP(i, n) {
			if (DUPLE(a, b, ensui[i].first.first, ensui[i].first.second)) {
				int tp = min(b, ensui[i].first.second);
				int kg = max(a, ensui[i].first.first);
				double r = ensui[i].second,mh = ensui[i].first.second- ensui[i].first.first,h = tp-kg;
				double r1 = (r / mh*(ensui[i].first.second - kg)), r2 = (r / mh*(ensui[i].first.second - tp));
				ans += h*(r1*r1 + r1*r2 + r2*r2)*PI / 3;
			}
		}

		printf("%lf\n", ans);
	}

	return 0;
}