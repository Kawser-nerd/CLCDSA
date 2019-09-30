#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

char str[20] = "welcome to code jam";
char dic[1501];
int n, a[501][20];

int dp(int i, int j) {
	int &ret = a[i][j];
	if (ret >= 0) return ret;
	if (j == 19) return ret = 1;
	if (i == n) return ret = 0;
	ret = dp(i + 1, j);
	if (dic[i] == str[j]) ret = (ret + dp(i + 1, j + 1)) % 10000;
	return ret;
}

int main() {
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int T;
	scanf("%d", &T);
	gets(dic);

	for (int t = 1; t <= T; t++) {
		memset(a, 0xff, sizeof(a));
		gets(dic);
		n = strlen(dic);
		printf("Case #%d: %.4d\n", t, dp(0, 0));
	}

	return 0;
}
