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

char in[105][105];

void test_case() {
	int h, w;
	scanf("%d%d", &h, &w);
	for(int row = 0; row < h; ++row)
		scanf("%s", in[row]);
	for(int rep = 0; rep < 2; ++rep) {
		for(int col = 0; col < w; ++col) {
			for(int row = 0; row < h - 1; ++row)
				if(in[row][col] != '?' && in[row+1][col] == '?')
					in[row+1][col] = in[row][col];
			for(int row = h - 2; row >= 0; --row)
				if(in[row][col] == '?' && in[row+1][col] != '?')
					in[row][col] = in[row+1][col];
		}
		for(int col = 0; col < max(w,h); ++col)
			for(int row = 0; row < max(w,h); ++row)
				if(row < col)
					swap(in[row][col], in[col][row]);
		swap(w, h);
	}
	for(int row = 0; row < h; ++row)
		printf("%s\n", in[row]);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int nr = 1; nr <= T; ++nr) {
		printf("Case #%d:\n", nr);
		test_case();
	}
}
