#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main() {
	int re, n;
	char type;
	int op, ot, bp, bt, p, t;

	scanf("%d", &re);
	for (int ri = 1; ri <= re; ++ri) {
		scanf("%d", &n);
		op = bp = 1;
		ot = bt = t = 0;
		for (int i = 0; i < n; ++i) {
			scanf(" %c%d", &type, &p);
			if (type == 'O') {
				ot += abs(op - p);
				ot = t = max(ot, t) + 1;
				op = p;
			} else {
				bt += abs(bp - p);
				bt = t = max(bt, t) + 1;
				bp = p;
			}
		}
		printf("Case #%d: %d\n", ri, t);
	}

	return 0;
}

