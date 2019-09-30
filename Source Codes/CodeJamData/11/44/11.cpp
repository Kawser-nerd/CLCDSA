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

const int VERTS = 512;
const int EDGES = 4<<10;

int n, m;
vector<int> rels[VERTS];
int edg[EDGES][2];

int deg[VERTS], dsum[VERTS];
int comm[VERTS][VERTS];

int cnt[VERTS];

struct Dist {
	int dist;
	int nbr;
	inline Dist(int _d = 0, int _n = 0) : dist(_d), nbr(_n) {}

	inline Dist operator+ (const Dist &x) const {
		return Dist(dist + x.dist, nbr + x.nbr);
	}
	inline bool operator< (const Dist &x) const {
		if (dist != x.dist) return dist < x.dist;
		if (nbr != x.nbr) return nbr > x.nbr;
		return false;
	}
};

int v;
Dist dist[EDGES];
bool used[EDGES];
struct CmpDist {
	inline bool operator() (int a, int b) const {
		if (dist[a] < dist[b]) return true;
		if (dist[b] < dist[a]) return false;
		return a < b;
	}
};
typedef set<int, CmpDist> Heap;

Heap heap;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int tt = 1; tt<=tests; tt++) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i<n; i++) rels[i].clear();
		for (int i = 0; i<m; i++) {
			char buff[16];
			scanf("%s", buff);
			int a, b;
			sscanf(buff, "%d,%d", &a, &b);
			rels[a].push_back(b);
			rels[b].push_back(a);
		}

		for (int i = 0; i<n; i++) deg[i] = rels[i].size();
		dsum[0] = 0;
		for (int i = 0; i<n; i++) dsum[i+1] = dsum[i] + deg[i];


		Dist ans;
		bool immans = false;
		for (int i = 0; i<rels[0].size(); i++) if (rels[0][i] == 1) immans = true;

		if (immans) {
			ans = Dist(0, deg[0]);
		}
		else {


		v = 0;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<rels[i].size(); j++) {
				edg[v][0] = i;
				edg[v][1] = rels[i][j];
				v++;
			}

		memset(cnt, 0, sizeof(cnt));
		int lvl = 0;
		for (int i = 0; i<n; i++)
			for (int j = 0; j<n; j++) {
				comm[i][j] = 0;
				lvl++;
				for (int u = 0; u<rels[i].size(); u++)
					cnt[rels[i][u]] = lvl;
				for (int u = 0; u<rels[j].size(); u++)
					if (cnt[rels[j][u]] == lvl)
						comm[i][j]++;
			}

		memset(used, 0, sizeof(used));
		memset(dist, 63, sizeof(dist));
		for (int i = 0; i<rels[0].size(); i++) {
			int b = rels[0][i];
			dist[i] = Dist(1, deg[0] + deg[b] - comm[0][b] - 2);
		}
		heap.clear();
		for (int i = 0; i<v; i++) heap.insert(i);

		while (heap.size()) {
			Heap::iterator it = heap.begin();
			int curr = *it;
			heap.erase(it);
			used[curr] = true;

            int ca = edg[curr][0];
            int cb = edg[curr][1];
			for (int i = 0; i<rels[cb].size(); i++) {
				int cc = rels[cb][i];

				int next = dsum[cb] + i;
                Dist ndist = dist[curr] + Dist(1, deg[cc] - comm[cc][cb] - comm[cc][ca] - 1);
                if (ndist < dist[next]) {
                	heap.erase(next);
					dist[next] = ndist;
					heap.insert(next);
                }
			}
		}

		ans = Dist(1000000000, -1);
		for (int i = 0; i<v; i++) {
//			printf("%d %d: %d %d\n", edg[i][0], edg[i][1], dist[i].dist, dist[i].nbr);

            int cb = edg[i][1];
            bool ok = false;
			for (int j = 0; j<rels[cb].size(); j++)
				if (rels[cb][j] == 1)
					ok = true;
			if (ok)
				if (dist[i] < ans)
					ans = dist[i];
		}


		}


		printf("Case #%d: %d %d\n", tt, ans.dist, ans.nbr);
		fflush(stdout);
	}
	return 0;
}
