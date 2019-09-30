#include <bits/stdc++.h>
using namespace std;
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge {c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
    *this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

const int nax = 1005;
const int inf = 1e9 + 5;
int req[nax];
int in[nax][nax];
pair<int,int> ran[nax][nax];

int divCeil(int a, int b) { return (a + b - 1) / b; }

#define mini(a,b) a=min(a,(b))
#define maxi(a,b) a=max(a,(b))

void test_case() {
	int n, p;
	scanf("%d%d", &n, &p);
	for(int i = 0; i < n; ++i)
		scanf("%d", &req[i]);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < p; ++j)
			scanf("%d", &in[i][j]);
		sort(in[i], in[i] + p);
		for(int j = 0; j < p; ++j) {
			// in[i][j] >= 0.9 * x * req[i]
			// x <= in[i][j] / req[i] / 0.9
			ran[i][j].second = in[i][j] * 10 / 9 / req[i];
			ran[i][j].first = divCeil(in[i][j] * 10, 11 * req[i]);
			debug() << imie(i) << imie(j) << imie(ran[i][j]);
		}
	}
	vector<int> pointer(n, 0);
	int answer = 0;
	while(true) {
		int max_left = -inf, min_right = inf;
		for(int i = 0; i < n; ++i) {
			maxi(max_left, ran[i][pointer[i]].first);
			mini(min_right, ran[i][pointer[i]].second);
		}
		if(max_left <= min_right) {
			++answer;
			for(int i = 0; i < n; ++i) {
				if(++pointer[i] == p) {
					printf("%d\n", answer);
					return;
				}
			}
			continue;
		}
		pair<int,int> best = {inf, -1};
		for(int i = 0; i < n; ++i)
			mini(best, make_pair(ran[i][pointer[i]].second, i));
		int i = best.second;
		assert(i != -1);
		if(++pointer[i] == p) break;
	}
	printf("%d\n", answer);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d: ", nr);
		test_case();
	}
}
