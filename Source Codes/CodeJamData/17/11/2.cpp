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

char ch[210][210];
int n, m;

void doit(int lx, int rx, int ly, int ry) {
	// printf("?? %d %d %d %d\n", );
	int xm = -1e9, xs = 1e9, ym = -1e9, ys = 1e9;
	for (int i = lx; i <= rx; i++)
		for (int j = ly; j <= ry; j++)
			if (ch[i][j] != '?') {
				xm = max(xm, i);
				xs = min(xs, i);
				ym = max(ym, j);
				ys = min(ys, j);
			}
	if (xm == xs && ym == ys) {
		for (int i = lx; i <= rx; i++)
			for (int j = ly; j <= ry; j++) 
				ch[i][j] = ch[xm][ym];
	}else if (xs < xm) {
		doit(lx, xs, ly, ry);
		doit(xs + 1, rx, ly, ry);
	}else {
		doit(lx, rx, ly, ys);
		doit(lx, rx, ys + 1, ry);
	}
}

void doit() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			for (ch[i][j] = getchar(); ch[i][j] <= 32; ch[i][j] = getchar());
	doit(1, n, 1, m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			printf("%c", ch[i][j]);
		printf("\n");
	}
}

int main() {
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; i++) {
        printf("Case #%d:\n", i);
        doit();
    }
}