#include <cstdio>
#include <iostream>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstring>
using namespace std;

int fa[10000], x[10000], r, c, a[20][20];
string ans[100];
bool Find;

int getl(int a, int b) {
	return r * c + c + 1 + a * (c + 1) + b;
}

int getr(int a, int b) {
	return a * c + b;
}

int get(int x) {
	if (x <= c)
		return getr(0, x);
	else if (x <= c + r)
		return getl(x - c, c);
	else if (x <= 2 * c + r)
		return getr(r, c - (x - c - r) + 1);
	else	return getl(r - (x - c - r - c) + 1, 0);
}

int gf(int x) {
	if (fa[x] != x)
		fa[x] = gf(fa[x]);
	return fa[x];
}

int Merge(int x, int y) {
	x = gf(x);
	y = gf(y);
	fa[x] = y;
}


void check() {
	// return ;
	// printf("xx\n");
	for (int i = 0; i <= 1000; i++)
		fa[i] = i;
	for (int i = 1; i <= r; i++)
		for (int j = 1; j <= c; j++)
			if (a[i][j] == 0) {
				Merge(getr(i - 1, j), getl(i, j));
				Merge(getr(i, j), getl(i, j - 1));
			}else {
				Merge(getr(i - 1, j), getl(i, j - 1));
				Merge(getr(i, j), getl(i, j));
			}
	// printf("xx\n");

	for (int i = 1; i <= 2 * (r + c); i += 2)
		if (gf(get(x[i])) != gf(get(x[i + 1])))
			return ;
	Find = true;

	// for (int i = 1; i <= 2 * (r + c); i++)
	// 	printf("?? %d\n", gf(get(i)));
	// printf("\n\n\n");

	for (int i = 1; i <= r; i++) {
		string s = "";
		for (int j = 1; j <= c; j++)
			if (a[i][j] == 0)
				s.push_back('\\');
			else s.push_back('/');
		ans[i] = s;
	}
}

void dfs(int x, int y) {
	// printf("?? %d %d\n", x, y);
	if (x > r)
		check();
	else if (y > c) 
		dfs(x + 1, 1);
	else {
		a[x][y] = 0;
		dfs(x, y + 1);
		a[x][y] = 1;
		dfs(x, y + 1);
	}
}

void doit() {
	scanf("%d%d", &r, &c);
	for (int i = 1; i <= 2 * (r + c); i++)
		scanf("%d", &x[i]);
	// printf("%d %d\n", r, c);
	// printf("!!\n");
	Find = false;
	// a[1][1] = 1;
	// a[1][2] = 1;
	// a[1][3] = 0;
	// check();
	// printf("%d\n", check());
	dfs(1, 1);
	printf("\n");
	if (!Find)
		printf("IMPOSSIBLE\n");
	else {
		for (int i = 1; i <= r; i++)
			cout << ans[i] << endl;
	}
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: " , i);
		doit();
	}
}
