#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cassert>
#include <cstdlib>
#include <ctime>

using namespace std;
typedef long long int64;
#define E(c) cerr<<#c
#define Eo(x) cerr<<#x<<" = "<<(x)<<endl

const int SIZE = 10<<10;

struct Road {
	int s, t;
	int vmin, vmax;
};

int n, m, p;
Road roads[SIZE];
vector<int> nbr[SIZE], anti[SIZE];
int path[SIZE];

bool used[SIZE];
int dist[SIZE];

inline int GetL(int eidx, int prof) {
	if (prof & (1<<eidx))
		return roads[eidx].vmin;
	else
		return roads[eidx].vmax;
}

bool Solve(int pref) {
	bool res = false;
	for (int p = 0; p<(1<<m); p++) {
		memset(dist, 63, n * sizeof(dist[0]));
		memset(used, false, n * sizeof(used[0]));
		dist[1] = 0;

		while (1) {
			int best = -1;
			int mind = 1000000000;
			for (int i = 0; i<n; i++)
				if (!used[i] && dist[i] < mind) {
					mind = dist[i];
					best = i;
				}
			if (best < 0) break;
			used[best] = true;
			for (int i = 0; i<anti[best].size(); i++) {
				int eidx = anti[best][i];
				int nv = roads[eidx].s;
				int newd = dist[best] + GetL(eidx, p);
				if (dist[nv] > newd)
					dist[nv] = newd;
			}
		}

		int d0 = 0;
		for (int i = 0; i<pref; i++)
			d0 += GetL(path[i], p);

/*		for (int i = 0; i<m; i++) printf("%d ", GetL(i, p)); printf("\n");
		for (int i = 0; i<n; i++) printf("%d ", dist[i]); printf("\n");
		printf("%d\n", d0);*/

		int lastc = (pref == 0 ? 0 : roads[path[pref-1]].t);
		int wetake = d0 + dist[lastc];
		int possible = dist[0];

		if (wetake <= possible) {
			res = true;
			return true;
		}
	}
	return res;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d%d%d", &n, &m, &p);
		for (int i = 0; i<n; i++) {
			nbr[i].clear();
			anti[i].clear();
		}
	    for (int i = 0; i<m; i++) {
	    	scanf("%d%d%d%d", &roads[i].s, &roads[i].t, &roads[i].vmin, &roads[i].vmax);
			roads[i].s--;
			roads[i].t--;
			nbr[roads[i].s].push_back(i);
			anti[roads[i].t].push_back(i);
	    }
		for (int i = 0; i<p; i++) {
			scanf("%d", &path[i]);
			path[i]--;
		}

		int left = 0;
		int right = p+1;
		while (right - left > 1) {
			fprintf(stderr, "[%d;%d)", left, right);
			int mid = (left + right) >> 1;
			if (Solve(mid))
				left = mid;
			else
				right = mid;
		}
		fprintf(stderr, "\n");

		printf("Case #%d: ", tt);
		if (left == p) printf("Looks Good To Me\n");
		else printf("%d\n", path[left] + 1);
		fflush(stdout);
	}
	return 0;
}
