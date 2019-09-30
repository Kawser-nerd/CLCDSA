#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<map>
#include<set>
#include<queue>
#include<stack>

using namespace std;

const int inf = 2147483647;
const double pi = acos(-1.0);
const double eps = 1e-8;

int k, n;
char s[1005];
int g[100][100];
bool u[100];

int getOther(char a) {
	if(a=='o') return 26;
	else if(a=='i') return 27;
	else if(a=='e') return 28;
	else if(a=='a') return 29;
	else if(a=='s') return 30;
	else if(a=='t') return 31;
	else if(a=='b') return 32;
	else if(a=='g') return 33;
	else return 99;
}

void add(char a, char b) {
	int x = a-'a';
	int y = b-'a';
	int x2 = getOther(a);
	int y2 = getOther(b);

	g[x][y] = 1;
	g[x][y2] = 1;
	g[x2][y] = 1;
	g[x2][y2] = 1;

	u[x] = 1;
	u[y] = 1;
	u[x2] = 1;
	u[y2] = 1;
}

bool vis[100];
int IN[100], OUT[100];
int cnt;

void dfs(int x) {
	if(vis[x]) return;
	vis[x] = true;

	for(int i=0; i<34; i++) if(g[x][i] || g[i][x]) dfs(i);

	int U = 0;
	for(int i=0; i<34; i++) if(g[i][x]) U++;
	for(int i=0; i<34; i++) if(g[x][i]) U--;

	if(U > 0) IN[cnt] += U;
	else OUT[cnt] += -U;
}

int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);
	int ntest;
	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d", &k);
		scanf("%s", &s);
		n = strlen(s);
		memset(g, 0, sizeof(g));
		memset(u, 0, sizeof(u));
		for(int i=0; i+1<n; i++) {
			add(s[i], s[i+1]);
		}

		memset(vis, 0, sizeof(vis));
		cnt = 0;
		for(int i=0; i<34; i++) if(u[i] && !vis[i]) {
			IN[cnt] = OUT[cnt] = 0;
			dfs(i);
			cnt++;
		}

		int ans = 0;
		for(int i=0; i<34; i++) {
			for(int j=0; j<34; j++) {
				ans += g[i][j];
			}
		}

		int SAME = 0;
		int TIN = 0;
		for(int i=0; i<cnt; i++) {
			if(IN[i] != OUT[i]) while(1);
			if(IN[i] == 0 && OUT[i] == 0) SAME++;
			else TIN += IN[i];
		}

		int ans2 = 0;
		ans2 += TIN;
		if(cnt > 1) ans2 += SAME;

		if(ans2 > 0) ans2--;

		printf("Case #%d: %d\n", test, ans + ans2 + 1);
	}
	return 0;
}
