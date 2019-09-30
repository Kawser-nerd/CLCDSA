#include<stdio.h>
#include<stdbool.h>
//union find?(??????????)
int par[100005];
int unifind(int n) {
	for (int i = 1; i <= n; i++) {
		par[i] = i;
	}
}
//???????
int unifind_root(int x) {
	if (par[x] == x) {
		return x;
	}
	else {
		return par[x] = unifind_root(par[x]);
	}
}
//?????????
bool unifind_same(int x, int y) {
	return unifind_root(x) == unifind_root(y);
}
//??????
int unifind_unite(int x, int y) {
	x = unifind_root(x);
	y = unifind_root(y);
	if (x == y) {
		return 0;
	}
	par[x] = y;
}
int main() {
	int p[100005] = {};
	int q[100005] = {};
	int result = 0;
	int xy[100005][2] = {};
	int m;
	int n;
	scanf("%d%d", &n,&m);
  	unifind(n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
		q[p[i]] = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &xy[i][0], &xy[i][1]);
		 unifind_unite(xy[i][0] , xy[i][1]);
	}
	for (int i = 1; i <= n; i++) {
		if (unifind_same(i, q[i])) {
			result++;
		}
	}
	printf("%d", result);
} ./Main.c: In function ‘main’:
./Main.c:39:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &n,&m);
  ^
./Main.c:42:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &p[i]);
   ^
./Main.c:46:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &xy[i][0], &xy[i][1]);
   ^