#include <cstdio>
#include <cstring>
using namespace std;

#define P 1000000007

int ans, T, ll, i, n, mi[210], sum[210], to[210], l[210], zhan[11000];
bool can[210], in[210], used[210], uu[210], uu1[210];
char S[210][210];

void dfs(int k) {
	used[k] = true;
	for (int i = 0; i < l[k]; i++)	zhan[++zhan[0]] = S[k][i];
	uu1[S[k][0]] = uu1[S[k][l[k] - 1]] = true;
	if (to[k]) {
		if (!used[to[k]])	dfs(to[k]);
		else	ans = 0;
	}
}

void check1() {
	for (int i = 1; i <= zhan[0]; i++) {
		if (uu[zhan[i]] && (i == 1 || zhan[i] != zhan[i - 1]))	ans = 0;
		uu[zhan[i]] = 1;
	}
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for (mi[0] = 1, i = 1; i <= 200; i++)	mi[i] = 1LL * mi[i - 1] * i % P;
	for (int Case = 1; Case <= T; Case++) {
		scanf("%d", &n);
		for (int i = 0; i <= 200; i++)	sum[i] = 0;
		memset(to, 0, sizeof to);
		memset(in, 0, sizeof in);
		memset(used, 0, sizeof used);
		memset(uu, 0, sizeof uu);
		memset(uu1, 0, sizeof uu1);
		zhan[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%s", S[i]);
			l[i] = strlen(S[i]);
			can[i] = true;
			int j;
			for (j = 1; j < l[i]; j++)
				if (S[i][j] != S[i][0])	break;
			if (j == l[i])	sum[S[i][0]]++, can[i] = false;
		}
		ans = 1;
		for (int i = 1; i <= 200; i++)	ans = 1LL * ans * mi[sum[i]] % P;
		for (int i = 1; i <= n; i++)
			if (can[i])
				for (int j = 1; j <= n; j++)
					if (can[j] && S[j][0] == S[i][l[i] - 1])	to[i] = j;
		for (int i = 1; i <= n; i++)	in[to[i]] = true;
		ll = 0;
		for (int i = 1; i <= n; i++)
			if (!in[i] && can[i])	dfs(i), ans = 1LL * ans * (++ll) % P;
		for (int i = 1; i <= n; i++)
			if (can[i] && !used[i])	ans = 0;
		check1();
		for (int i = 0; i <= 200; i++)
			if (sum[i]) {
				if (uu[i] && !uu1[i])	ans = 0;
				if (!uu[i])	ans = 1LL * ans * (++ll) % P;
			}
		printf("Case #%d: %d\n", Case, ans);
	}
}
