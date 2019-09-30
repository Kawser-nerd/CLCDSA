#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int dir, cx, cy, x[1000000], y[1000000], n;
int d[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

char flag[6010][6010];
char str[1000];

int m;
int lh[6010],lv[6010],hh[6010],hv[6010];

int min(int a, int b) {
	return a<b?a:b;
}

int area(int n)
{
	int i;
	__int64 s = 0;
	for (i = 0; i < n; i++){
		s += x[i] * y[i+1];
		s -= y[i] * x[i+1];
	}
	if (s < 0) s = -s;
	return (int)s / 2;
}

void move(char *str) {
	int i, bx, by, mx, my;
	for (i = 0; i < strlen(str); i++) {
		if (str[i] == 'F') {
			bx = cx;
			by = cy;
			cx += d[dir][0];
			cy += d[dir][1];
			x[n] = cx;
			y[n] = cy;
			n++;
			mx = min(bx, cx);
			my = min(by, cy);
			if (bx == cx) {
				if (bx < lh[my]) lh[my] = bx;
				if (bx > hh[my]) hh[my] = bx;
			}
			else {
				if (by < lv[mx]) lv[mx] = by;
				if (by > hv[mx]) hv[mx] = by;
			}
		}
		else if (str[i] == 'R') {
			dir++;
			if (dir == 4) dir = 0;
		}
		else {
			dir--;
			if (dir < 0) dir = 3;
		}
	}
}

int main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int testcases;
	scanf("%d", &testcases);
	int i, j, k, z;
	for (z = 0; z < testcases; z++) {
		printf("Case #%d: ", z+1);
		dir = 0;
		scanf("%d",&m);
		cx = 3005;
		cy = 3005;
		x[0] = cx;
		y[0] = cy;
		n = 1;
		for (i = 0; i < 6010; i++) {
			lh[i] = lv[i] = 10000;
			hh[i] = hv[i] = -1;
		}
		while(m--) {
			scanf("%s%d",str,&i);
			while(i--) move(str);
		}
		memset(flag, 0, sizeof(flag));
		k = 0;
		for (i = 0; i < 6010; i++) {
			if (hv[i] > 0) {
				for (j = lv[i]; j < hv[i]; j++) {
					flag[i][j] = 1;
					k++;
				}
			}
		}
		for (i = 0; i < 6010; i++) {
			if (hh[i] > 0) {
				for (j = lh[i]; j < hh[i]; j++) {
					if (!flag[j][i]) {
						flag[j][i] = 1;
						k++;
					}
				}
			}
		}
		printf("%d\n",k - area(n-1));
	}
	return 0;
}
