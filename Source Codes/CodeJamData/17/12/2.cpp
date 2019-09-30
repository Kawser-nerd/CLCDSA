#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
using namespace std;

int n, p, a[1100], q[1100], b[1100][1100];

int calc_min(int a, int b) {
	return (10 * b + 11 * a - 1) / 11 / a;
}

int calc_max(int a, int b) {
	return (10 * b ) / 9 / a;
}

void doit() {
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= p; j++)
			scanf("%d", &b[i][j]);
		sort(b[i] + 1, b[i] + p + 1);
		q[i] = 1;
	}
	int ans = 0;
	while (true) {
		int l = -1e9, r = 1e9, ind = 0;
		for (int i = 1; i <= n; i++) {
			if (q[i] > p) {
				printf("%d\n", ans);
				return;
			}
			int R = calc_max(a[i], b[i][q[i]]);
			l = max(l, calc_min(a[i], b[i][q[i]]));
			if (R < r)
				ind = i;
			r = min(r, calc_max(a[i], b[i][q[i]]));
		}
		if (l <= r) {
			ans += 1;
			for (int i = 1; i <= n; i++)
				q[i] += 1;
		}else {
			q[ind] += 1;
		}
	}
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d: ", i);
        doit();
    }
}