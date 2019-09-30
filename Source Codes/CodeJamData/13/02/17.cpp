#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int n, m, map[105][105], row[105], col[105];

int main() {
	
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for (int V = 1; V <= T; ++V) {
	  scanf("%d %d", &n, &m);
	  for (int i = 1; i <= n; ++i) {
	    row[i] = 0;
		}
		for (int j = 1; j <= m; ++j) {
		  col[j] = 0;
		}
	  for (int i = 1; i <= n; ++i) {
	    for (int j = 1; j <= m; ++j) {
	      scanf("%d", &map[i][j]);
	      row[i] = max(row[i], map[i][j]);
	      col[j] = max(col[j], map[i][j]);
			}
		}
		bool flag = true;
		for (int i = 1; i <= n; ++i) {
		  for (int j = 1; j <= m; ++j) {
		    flag = flag && map[i][j] == min(row[i], col[j]);
			}
		}
		if (flag) printf("Case #%d: YES\n", V); else printf("Case #%d: NO\n", V);
	}
	return 0;
}
