#include <cstdio>
#include <cstring>

const int MAXN = 128;

char maze[MAXN][MAXN];
char newmaze[MAXN][MAXN];
int n, k;

bool checkit(char ch)
{
	for (int i = 0; i < n; ++i) {
		int cur = 0;
		for (int j = 0; j < n; ++j) {
			if (newmaze[i][j] == ch) ++cur;
			else cur = 0;
			if (cur >= k) return true;
		}
	}
	for (int j = 0; j < n; ++j) {
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			if (newmaze[i][j] == ch) ++cur;
			else cur = 0;
			if (cur >= k) return true;
		}
	}
	for (int sum = 0; sum <= (n - 1 + n - 1); ++sum) {
		int cur = 0;
		for (int i = 0; i <= sum && i < n; ++i) {
			int j = sum - i;
			if (j < 0 || j >= n) continue;
			if (newmaze[i][j] == ch) ++cur;
			else cur = 0;
			if (cur >= k) return true;
		}
	}
	for (int diff = -n + 1; diff <= n - 1; ++diff) {
		int cur = 0;
		for (int i = 0; i < n; ++i) {
			int j = i + diff;
			if (j < 0 || j >= n) continue;
			if (newmaze[i][j] == ch) ++cur;
			else cur = 0;
			if (cur >= k) return true;
		}
	}
	return false;
}

int run()
{
	int ret = 0;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; ++i) {
		scanf("%s", maze[i]);
	}
	memset(newmaze, '.', sizeof(newmaze));
	for (int i = n - 1; i >= 0; --i) {
		for (int j = n - 1, k = n - 1; j >= 0; --j) {
			if (maze[i][j] != '.') {
				newmaze[k][n - 1 - i] = maze[i][j];
				--k;
			}
		}
	}
	if (checkit('R')) ret |= 1;
	if (checkit('B')) ret |= 2;
	return ret;
}

int main()
{
	freopen("A2.in", "r", stdin);
	freopen("A2.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; ++i) {
		printf("Case #%d: ", i);
		int res = run();
		if (res == 0) puts("Neither");
		else if (res == 1) puts("Red");
		else if (res == 2) puts("Blue");
		else puts("Both");
	}
	return 0;
}