#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n, k, p[5];
int g[16][16], last[16][16];
int a[1<<16][16], first;
char str[50001];

void init() {
	int i, j, t, r;
	for (i = 0; i < k; i++) {
		for (j = 0; j < k; j++) {
			last[i][j] = 0;
			for (t = 0; t < n; t += k) {
				r = t + k;
				if (r >= n) break;
				if (str[t+i] != str[r+j]) last[i][j]++;
			}
			if (i == j) continue;
			g[i][j] = 0;
			for (t = 0; t < n; t += k) {
				if (str[t+i] != str[t+j]) g[i][j]++;
			}
		}
	}
}

int dp(int mask,int pre) {
	int &ret = a[mask][pre];
	if (ret >= 0) return ret;
	if (mask == 0) return ret = last[pre][first];
	int i, j;
	ret = n;
	for (i = 0; i < k; i++) if (mask & (1 << i)) {
		j = g[pre][i] + dp(mask ^ (1<<i), i);
		if (j < ret) ret = j;
	}
	return ret;
}

int main() {
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	int testcases;
	scanf("%d", &testcases);
	int i, j, ret, z;
	for (z = 0; z < testcases; z++) {
		printf("Case #%d: ", z + 1);
		scanf("%d%s",&k,str);
		n = strlen(str);
		init();
		ret = n;
		for (first = 0 ; first < k; first++) {
			memset(a,0xff,sizeof(a));
			j = (1 << k) - 1;
			j ^= (1 << first);
			i = dp(j, first);
			if (i < ret) ret = i;
		}
		printf("%d\n",ret+1);
	}
	return 0;
}
