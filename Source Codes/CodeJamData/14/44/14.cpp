#pragma comment(linker, "/STACK:100000000")
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <ctime>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
#define int64 long long
#define ldb long double
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(a) ((int) (a).size())
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define taskname "task_d"
const ldb pi = acos(-1.0);
const int MDL = (int) 1e9 + 7;
const int N = 111111;
const int M = 111;
const int A = 26;
int fact[N], cnt[N], invfact[N], go[N][A], total, done[2][N], t, n, m, value, ways[N][M];
bool term[N];
char s[N];

void add(char * s) {
	cnt[0]++;
	int j = 0;
	for (int i = 0; s[i]; ++i) {
		int c = s[i] - 'A';
		if (go[j][c] == -1) {
			memset(go[total], -1, sizeof(go[total]));
			term[total] = false;
			cnt[total] = 0;
			go[j][c] = total++;
		}
		j = go[j][c], cnt[j]++;
	}
	term[j] = true;
}

int mult(int a, int b) {
	return (a * (int64) b) % MDL;
}

int pow(int a, int b) {
	if (!b) return 1 % MDL;
	if (b & 1) return mult(pow(a, b - 1), a);
	int tmp = pow(a, b / 2);
	return mult(tmp, tmp);
}

int inverse(int a) {
	return pow(a, MDL - 2);
}

void add(int& a, int b) {
	a = (a + b) % MDL;
}

int choose(int n, int k) {
	return mult(fact[n], mult(invfact[k], invfact[n - k]));
}

int split(int n, int k) {
	return choose(n + k - 1, k - 1);
}

void solve(int v) {
	/*if (cnt[v] < m) {
		value += cnt[v];
		ways[v][0] = 0;
		for (int i = 1; i <= cnt[v]; ++i)
			ways[v][i] = mult(split(cnt[v] - i, i), fact[i]);
		return;
	}*/
	value += min(m, cnt[v]);
	vector<int> a;
	for (int i = 0; i < A; ++i)
		if (go[v][i] != -1) {
			solve(go[v][i]);
			a.pb(go[v][i]);
		}
	int t = 0;
	for (int j = 0; j <= m; ++j)
		done[t][j] = (j == (int) term[v]) ? 1 : 0;
	for (int i = 0; i < sz(a); ++i, t ^= 1) {
		for (int j = 0; j <= m; ++j)
			done[t ^ 1][j] = 0;
		for (int j = 0; j <= m; ++j)
			if (done[t][j])
				for (int k = min(m, cnt[a[i]]); k <= min(m, cnt[a[i]]); ++k)
					if (ways[a[i]][k])
						for (int l = 0; l <= min(j, k); ++l)
							if (k + j - l <= m)
								add(done[t ^ 1][k + j - l], mult(mult(done[t][j], ways[a[i]][k]), 
								mult(choose(k + j - l, j), choose(j, l))));
	}
	for (int j = 0; j <= m; ++j)
		ways[v][j] = done[t][j];
}

int main() {
	assert(freopen(taskname".in", "r", stdin));
	assert(freopen(taskname".out", "w", stdout));
	fact[0] = invfact[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = mult(fact[i - 1], i);
		invfact[i] = inverse(fact[i]);
	}
	scanf("%d", &t);
	for (int it = 0; it < t; ++it) {
		scanf("%d%d", &n, &m);
		memset(go[0], -1, sizeof(go[0]));
		term[0] = false;
		cnt[0] = 0, total = 1, value = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%s", s);
			add(s);
		}
		solve(0);
		/*for (int i = 0; i < total; ++i)
			for (int j = 0; j <= m; ++j)
				printf("%d%c", ways[i][j], " \n"[j == m]);*/
		printf("Case #%d: %d %d\n", it + 1, value, ways[0][m]);
	}
	return 0;
}

