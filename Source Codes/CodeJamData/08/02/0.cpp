#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int,int> pii;

#define _CRT_SECURE_NO_WARNINGS
#define For(i,a,b) for (int i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define Rep(i,n) for (int i(0),_n(n); i < _n; ++i)
#define Repd(i,n) for (int i((n)-1); i >= 0; --i)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))
#define All(v) (v).begin(), (v).end()

template<typename T, typename S> T cast(S s) {
	stringstream ss;
	ss << s;
	T res;
	ss >> res;
	return res;
}

template<typename T> inline T sqr(T a) { return a*a; }
template<typename T> inline int Size(const T& c) { return (int)c.size(); }
template<typename T> inline void checkMin(T& a, T b) { if (b < a) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (b > a) a = b; }

int readTime() {
	int h, m;
	scanf("%d:%d", &h, &m);
	return m+60*h;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int t;
	scanf("%d", &t);
	For(test, 1, t) {
		int t;
		scanf("%d", &t);
		int n1, n2;
		scanf("%d%d", &n1, &n2);
		vector<pii> t1(n1), t2(n2);
		Rep(i, n1) {
			t1[i].first = readTime();
			t1[i].second = readTime();
		}
		Rep(i, n2) {
			t2[i].first = readTime();
			t2[i].second = readTime();
		}
		sort(All(t1));
		sort(All(t2));
		int r1 = 0, r2 = 0;
		while (Size(t1) > 0 || Size(t2) > 0) {
			int x;
			if (Size(t2) > 0 && (Size(t1) == 0 || t2[0] < t1[0])) {
				++r2;
				x = t2[0].second;
				t2.erase(t2.begin());
			} else {
				++r1;
				x = -t;
			}
			for (;;) {
				int i = 0;
				while (i < Size(t1) && t1[i].first < x+t)
					++i;
				if (i == Size(t1))
					break;
				x = t1[i].second;
				t1.erase(t1.begin()+i);
				i = 0;
				while (i < Size(t2) && t2[i].first < x+t) 
					++i;
				if (i == Size(t2))
					break;
				x = t2[i].second;
				t2.erase(t2.begin()+i);
			}
		}
		printf("Case #%d: %d %d\n", test, r1, r2);
	}

	exit(0);
}
