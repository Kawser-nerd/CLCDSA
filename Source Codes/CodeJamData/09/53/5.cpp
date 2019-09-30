// Adrian Kügel
#include <stdio.h>
#include <vector>
#include <set>
#include <queue>
#include <math.h>
#include <stdlib.h>
#include <map>
#include <assert.h>
#include <string.h>
#include <limits.h>
#include <complex>
#include <algorithm>
#include <ctype.h>
#include <string>
using namespace std;

typedef set<int> SI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef complex<double> tComp;
typedef pair<short, int> PCI;

VI adj[1000];
char visit[1000];
int comp;

void dfs(int cur) {
	if (visit[cur])
		return;
	visit[cur] = comp;
	for (VI::iterator it=adj[cur].begin(); it!=adj[cur].end(); ++it)
		dfs(*it);
}

int maxc, minc, n;
int col[1000], ncols[1000];
int cnt[1000][5];
int x[1000], y[1000];
void backtrack(int cols) {
	if (cols >= minc || minc <= maxc)
		return;
	/*
	int by = -1, bx, ind;
	for (int i=0; i<n; ++i)
		if (visit[i] == comp && col[i] < 0 && (y[i] > by || y[i] == by && x[i] > bx)) {
			ind = i;
			by = y[i];
			bx = x[i];
		}
	if (by < 0) {
		minc = cols;
		return;
	}
*/
	int bcols = -1, bcnt, bx, by, ind;
	for (int i=0; i<n; ++i) 
		if (visit[i] == comp && col[i] < 0 && (ncols[i] > bcols || ncols[i] == bcols && (y[i] > by || y[i] == by && x[i] > bx))) {
			bcnt = adj[i].size();
			bcols = ncols[i];
			ind = i;
			bx = x[i];
			by = y[i];
		}
	if (bcols < 0) {
		minc = cols;
		return;
	}
	for (int i=0; i<=cols; ++i) {
		if (cnt[ind][i] == 0) {
			col[ind] = i;
			for (VI::iterator it=adj[ind].begin(); it!=adj[ind].end(); ++it)
				if (++cnt[*it][i] == 1)
					++ncols[*it];
			backtrack(cols + (i == cols));
			for (VI::iterator it=adj[ind].begin(); it!=adj[ind].end(); ++it)
				if (--cnt[*it][i] == 0)
					--ncols[*it];
		}
	}
	col[ind] = -1;
}

int ind[1000];

bool compare(int a, int b) {
	return x[a] < x[b];
}

int main() {
	int tc;
	scanf("%d", &tc);
	for (int scen=1; scen<=tc; ++scen) {
		printf("Case #%d: ", scen);
		int k;
		scanf("%d", &n);
		for (int i=0; i<n; ++i) {
			adj[i].clear();
			visit[i] = 0;
			col[i] = -1;
			ncols[i] = 0;
			memset(cnt[i], 0, n*sizeof(int));
			scanf("%d %d", &x[i], &y[i]);
			ind[i] = i;
		}
		sort(ind, ind + n, compare);
		for (int i=0; i<n; ++i) {
			for (int j=i+1; j<n; ++j) {
				if (y[ind[j]] == y[ind[i]]) {
					adj[ind[i]].push_back(ind[j]);
					adj[ind[j]].push_back(ind[i]);
					break;
				}
			}
			for (int j=i+1; j<n; ++j) {
				if (y[ind[j]] == y[ind[i]] + 1) {
					adj[ind[i]].push_back(ind[j]);
					adj[ind[j]].push_back(ind[i]);
					break;
				}
			}
			for (int j=i+1; j<n; ++j) {
				if (y[ind[j]] == y[ind[i]] - 1) {
					adj[ind[i]].push_back(ind[j]);
					adj[ind[j]].push_back(ind[i]);
					break;
				}
			}
		}
		maxc = 0;
		comp = 0;
		for (int i=0; i<n; ++i)
			if (!visit[i]) {
				++comp;
				dfs(i);
				minc = 4;
				backtrack(0);
				maxc = max(maxc, minc);
			}
		printf("%d\n", maxc);
		fflush(stdout);
	}
	return 0;
}
