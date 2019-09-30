//By Lin
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>

#define X first
#define Y second
#define mp make_pair
#define sqr(x) ((x) * (x))
#define Rep(i, n) for(int i = 0; i<(n); i++)
#define foreach(it, n) for(__typeof(n.begin()) it = n.begin(); it != n.end(); it++)

using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define esp 1e-8
#define N 100010

int m, n;
char s[10][20];
int belong[100];
bool mark[100];

int ncnt = 0;
struct Node {
	Node *go[26];
	void clear() {
		memset(go, 0, sizeof go);
	}
}data[N], *root[100];

void insert(Node *tmp, char s[]) {
	for (int i = 0; s[i]; i++) {
		int k = s[i] - 'A';
		if (!tmp->go[k]) {
			data[ncnt].clear();
			tmp->go[k] = &data[ncnt++];
		}
		tmp = tmp->go[k];
	}
}

pii ans;
void dfs(int x) {
	if (x == m) {
		memset(mark, 0, sizeof mark);
		Rep(i, m) mark[belong[i]] = true;
		Rep(i, n) if (!mark[i]) return;
		Rep(i, n) {
			data[i].clear();
			root[i] = &data[i];
		}
		ncnt = n;
		Rep(i, m) insert(root[belong[i]], s[i]);
		if (ncnt > ans.X) ans = mp(ncnt, 0);
		if (ncnt == ans.X) ans.Y++;
		return;
	}
	for (int i = 0; i<n; i++) {
		belong[x] = i;
		dfs(x + 1);
	}
}
int main() {
	int cas, tt = 0;
	scanf("%d", &cas);
	while (cas --) {
		scanf("%d%d", &m, &n);
		Rep(i, m) scanf("%s", s[i]);
		ans = mp(0, 0);
		dfs(0);
		printf("Case #%d: %d %d\n", ++tt, ans.X, ans.Y);
	}
	return 0;
}
