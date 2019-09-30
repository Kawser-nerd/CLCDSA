#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, V, nI;
int a[20000][2];
int gate[20000], change[20000], value[20000];

int dp(int node, int v) {
	int &ret = a[node][v];
	if (ret >= 0) return ret;
	int l, r, g, k, j;
	if (node >= nI) {
		if (value[node] == v) return ret = 0;
		return ret = 20000;
	}
	else {
		ret = 20000;
		for (l = 0; l <= 1; l++) {
			for (r = 0; r <= 1; r++) {
				for (g = 0; g <= 1; g++) {
					if (g == 0) {
						k = l | r;
					}
					else {
						k = l & r;
					}
					if (k == v) {
						if (g != gate[node] && !change[node]) continue;
						if (g == gate[node]) {
							j = dp(node * 2 + 1, l) + dp(node * 2 + 2, r);
						}
						else {
							j = dp(node * 2 + 1, l) + dp(node * 2 + 2, r) + 1;
						}
						if (j < ret) ret = j;
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int testcases;
	scanf("%d", &testcases);
	int i, j, z;
	for (z = 0; z < testcases; z++) {
		printf("Case #%d: ", z+1);
		scanf("%d%d",&n,&V);
		for (i = 0; i < (n - 1)/2; i++) {
			scanf("%d%d",&gate[i],&change[i]);
		}
		nI = (n - 1) / 2;
		for (i = nI; i < n; i++) {
			scanf("%d",&value[i]);
		}
		memset(a,0xff,sizeof(a));
		j = dp(0, V);
		if (j < 20000) {
			printf("%d\n",j);
		}
		else {
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
