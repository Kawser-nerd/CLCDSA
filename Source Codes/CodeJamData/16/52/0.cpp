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

char S[1100000], SS[1100000];
int zhan[1100000];
int Next[110];
int tr[110][110], z[110], used[110];
int n, ll, h;
int l[110], go[110][110], sum[110];
long double C[110][110], dp[110];

int sample(int tt) {
	int tot = 0;
	for (int i = 1; i <= h; i++)
		if (!used[i]) {
			tot += sum[z[i]];
		}
	int x = rand() % tot + 1;
	// cout << x << endl;
	int last;
	for (int i = 1; i <= h; i++)
		if (!used[i]) {
			x -= sum[z[i]];
			if (x <= 0)
				return i;
			last = i;
		}
	return last;
	// int x;
	// for (x = rand() % h + 1; used[x]; x = rand() % h + 1);
	// return x;
}

int dd() {
	for (int i = 1; i <= n; i++)
		used[i] = false;
	h = 0;
	for (int i = 1; i <= l[0]; i++)
		z[++h] = go[0][i];
	// printf("?? %d %d\n", h, z[h]);
	int now = 0;

	for (int i = 1; i <= n; i++) {
		int x = sample(i);
		used[x] = true;
		for (int i = 1; i <= l[z[x]]; i++)
			z[++h] = go[z[x]][i];
		// if (i == 1)
			// printf("%c\n", S[z[x]]);
		now = tr[now][S[z[x]] - 'A'];
		// printf("%c", S[z[x]]);
		// printf("?? %d\n", now);
		if (now == ll)
			return 1;
	}

	return 0;
}

void dfs(int k) {
	sum[k] = 1;
	dp[k] = 1;
	for (int i = 1; i <= l[k]; i++) {
		dfs(go[k][i]);
		sum[k] += sum[go[k][i]];
		dp[k] *= C[sum[k]][sum[go[k][i]]];
	}
}

void doit() {
	scanf("%d", &n);
	l[0] = 0;
	for (int i = 1; i <= n; i++) {
		l[i] = 0;
	}
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		go[x][++l[x]] = i;
	}
	C[0][0] = 1;
	for (int i = 1; i <= 100; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= 100; j++) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
		}
	}
	dfs(0);

	// printf("?? %d\n", l[0]);
	scanf("%s", S + 1);
	int kk;
	scanf("%d", &kk);
	while (kk--) {
		scanf("%s", SS + 1);
		Next[1] = 0;
		ll = strlen(SS + 1);
		int p = 0;
		for (int i = 2; i <= ll; i++) {
			for (; p && SS[p + 1] != SS[i]; p = Next[p]);
			if (SS[p + 1] == SS[i])
				p += 1;
			Next[i] = p;
		}
		// for (int i = 1; i <= ll; i++)
		// 	printf("%d ", Next[i]);	
		// printf("\n");
		for (int i = 0; i < ll; i++) {
			for (int j = 'A'; j <= 'Z'; j++) {
				int p = i;
				for (; p && SS[p + 1] != j; p = Next[p]);
				if (SS[p + 1] == j)
					p += 1;
				tr[i][j - 'A'] = p;
				// if (i == 0 && j == SS[1])
			}
		}
		// printf("%d\n", tr[0][2]);
		int cnt = 0;
		for (int i = 1; i <= 10000; i++) {
			cnt += dd();
			// printf("\n");
		}
		// printf("?? %d\n", cnt);
		printf(" %.8lf", cnt / 10000.0);
	}
	printf("\n");
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d:" , i);
		doit();
	}
}
