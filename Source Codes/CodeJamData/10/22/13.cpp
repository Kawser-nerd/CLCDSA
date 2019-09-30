#define _CRT_SECURE_NO_DEPRECATE

#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

template<class T> int size(const T & a) {
	return (int)a.size();
}
template<class T> T sqr(const T &a) {
	return a * a;
}
int x[100];
int v[100];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int ntests;
	scanf("%d", &ntests);
	for (int itest = 1; itest <= ntests; itest++) {
		printf("Case #%d: ", itest);
		int n, k, b, t;
		cin >> n >> k >> b >> t;
		for (int i = 0; i < n; i++) {
			scanf("%d", &x[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &v[i]);
		}
		int res = 0;
		for (int i = n - 1; k && i > -1; i--) {
			if (x[i] + v[i] * t >= b) {
				k--;
			} else {
				res += k;
			}
		}
		if (k) {
			printf("IMPOSSIBLE\n");
			continue;
		} else {
			cout << res << endl;
		}
	}
	return 0;
}