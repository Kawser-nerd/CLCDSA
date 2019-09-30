#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <set>
#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#define MP make_pair
#define PB push_back
#define foreach(e,x) for(__typeof(x.begin()) e=x.begin(); e!=x.end(); ++e)

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MAX_N = 400 + 10;
int n, k, cnt;
int t[MAX_N];
int key[MAX_N];
int tot[MAX_N];
int kic[MAX_N][MAX_N];
int vis[MAX_N];
int path[MAX_N];
int inset[MAX_N];

void dfs(int u)
{
	if (vis[u]) return;
	vis[u] = true;
	-- cnt;
	
	for(int i = 1; i < n; ++ i)
		if (! vis[i] && ! inset[i]) {
			int have = false;
			for(int j = 0; j < tot[u]; ++ j)
				if (kic[u][j] == t[i]) {
					have = true;
					break;
				}
			if (have) 
				dfs(i);
		}
}

int check()
{
	cnt = 0;
	memset(key, 0, sizeof key);
	for(int i = 0; i < n; ++ i) {
		vis[i] = false;
		if (inset[i]) {
			for(int j = 0; j < tot[i]; ++ j)
				++ key[kic[i][j]];
			if (i)
				-- key[t[i]];
		} else ++ cnt;
	}
	
	for(int i = 1; i < n; ++ i)
		if (key[t[i]] && ! inset[i])
			dfs(i);
	return ! cnt;
}

int tkey[MAX_N];

void doIt(int cur)
{
	if (cur == n - 1) {
		for(int i = 0; i < n - 1; ++ i) {
			printf("%d", path[i]);
			if (i != n - 2) putchar(' ');
		}
		printf("\n");
		return;
	}
	
	memset(tkey, 0, sizeof tkey);
	for(int i = 0; i < n; ++ i) {
		if (inset[i]) {
			for(int j = 0; j < tot[i]; ++ j)
				++ tkey[kic[i][j]];
			if (i)
				-- tkey[t[i]];
		}
	}
	
	for(int i = 1; i < n; ++ i)
		if (! inset[i] && tkey[t[i]]) {
			inset[i] = true;
			if (check()) {
				path[cur] = i;
				doIt(cur + 1);
				return;
			}
			inset[i] = false;
		}
}

void solve(int test)
{
	printf("Case #%d: ", test);
	scanf("%d%d", &k, &n);
	
	tot[0] = k;
	++ n;
	
	memset(key, 0, sizeof key);
	for(int i = 0; i < tot[0]; ++ i) {
		scanf("%d", &kic[0][i]);
		key[kic[0][i]] ++;
	}
	
	for(int i = 1; i < n; ++ i) {
		scanf("%d%d", &t[i], &tot[i]);
		for(int j = 0; j < tot[i]; ++ j) {
			scanf("%d", &kic[i][j]);
			key[kic[i][j]] ++;
		}
	}
	
	for(int i = 1; i < n; ++ i) {
		-- key[t[i]];
		if (key[t[i]] < 0) {
			puts("IMPOSSIBLE");
			return;
		}
	}
	memset(inset, 0, sizeof inset);
	inset[0] = true;
	if (! check()) {
		puts("IMPOSSIBLE");
		return;
	}
	doIt(0);
}

int main()
{
	//freopen("D.in", "r", stdin); freopen("D.out", "w", stdout);
	//freopen("D-small-attempt0.in", "r", stdin); freopen("D.out", "w", stdout);
	freopen("D-large.in", "r", stdin); freopen("D-large.out", "w", stdout);
	int testcase; scanf("%d", &testcase);
	for(int i = 1; i <= testcase; ++ i) solve(i);
	fclose(stdout);
	return 0;
}
