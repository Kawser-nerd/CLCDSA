#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
#include <string>

using namespace std;

int n, m, k;
char flag[15][26];
char dic[5000][16], str[1000];

int main() {
	freopen("A.in", "r", stdin);
//	freopen("A.out", "w", stdout);
	int i, j, t, ct;
	scanf("%d%d%d",&n,&m,&k);
	for (i = 0; i < m; i++) {
		scanf("%s", dic[i]);
	}
	for (t = 1; t <= k; t++) {
		ct = 0;
		scanf("%s", str);
		memset(flag, 0, sizeof(flag));
		j = 0;
		for (i = 0; i < n; i++) {
			if (islower(str[j])) {
				flag[i][str[j] - 'a'] = 1;
				j++;
			}
			else {
				j++;
				while(str[j] != ')') {
					flag[i][str[j] - 'a'] = 1;
					j++;
				}
				j++;
			}
		}
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (!flag[j][dic[i][j] - 'a']) break;
			}
			if (j == n) ct++;
		}
		printf("Case #%d: %d\n", t, ct);
	}
	return 0;
}
