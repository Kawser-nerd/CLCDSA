#pragma comment(linker, "/STACK:128777216")

#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <set>
#include <iostream>
#include <functional>
#include <numeric>
#include <sstream>
#include <exception>
#include <cassert>

typedef long long i64;
typedef unsigned int u32;
const int null = 0;

using namespace std;

template<class T> int size(const T &a) {
	return int(a.size());
}
template<class T> T abs(const T &a) {
	return (a < 0? -a: a);
}
template<class T> T sqr(const T &a) {
	return a * a;
}

#define all(a) a.begin(),a.end()

int main() {
#ifdef pperm
	freopen("input.txt", "r", stdin);
	//freopen("input.txt", "w", stdout);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	for (int iTest = 1; iTest <= T; iTest++) {
		printf("Case #%d: ", iTest);
		int c, n;
		scanf("%d %d", &c, &n);
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(all(a));
		if (c == 1) {
			printf("%d\n", n);
			continue;
		}
		int res = n;
		int cur = 0;
		for (int i = 0; i < n; i++) {
			res = min(res, cur + n - i);
			while (c <= a[i]) {
				c += c - 1;
				cur++;
			}
			c += a[i];
		}
		res = min(res, cur);
		printf("%d\n", res);
	}
#ifdef pperm
	fprintf(stderr, "\n%.3lf\n", clock() / double(CLOCKS_PER_SEC));
#endif
	return 0;
}