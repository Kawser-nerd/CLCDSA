#include <bits/stdc++.h>
#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define ll long long
#define alok(n,t) ((t*)malloc((n)*sizeof(t)))
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)
using namespace std;

typedef pair<ll,ll> pt;
#define INF (1LL<<60)
#define i first
#define j second
#define INF (1LL<<60)

char grid[1111][1111];
pt prev[1111][1111];
pt next[1111][1111];
ll dfsdist[1111][1111];

int di[5] = {0, 1, 0, -1, 0};
int *dj = di + 1;
pt go(pt p, int d) {
	return make_pair(p.i + di[d], p.j + dj[d]);
}
int r, c, d;
int si, sj, ei, ej;
pt start, end;
int compute_seq() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			dfsdist[i][j] = INF;
		}
	}
	dfsdist[si][sj] = 0;
	vector<pt> queue;
	queue.push_back(start);
	fr(f, queue.size()) {
		pt p = queue[f];
		fr(d,4) {
			pt q = go(p, d);
			if (grid[q.i][q.j] != '#' && dfsdist[q.i][q.j] >= INF) {
				dfsdist[q.i][q.j] = dfsdist[p.i][p.j] + 1;
				prev[q.i][q.j] = p;
				queue.push_back(q);
			}
		}
	}
	pt p = make_pair(ei, ej);
	while (p != start) {
		pt pr = prev[p.i][p.j];
		next[pr.i][pr.j] = p;
		p = pr;
	}
	return dfsdist[ei][ej];
}
pt add(pt p, pt q) {
	return make_pair(p.i + q.i, p.j + q.j);
}
pt sub(pt p, pt q) {
	return make_pair(p.i - q.i, p.j - q.j);
}
ll manh(pt p) {
	return llabs(p.i) + llabs(p.j);
}
ll dist(pt p, pt q) {
	return manh(sub(p, q));
}
bool aligned(pt p, pt q) {
	return p.i == q.i || p.j == q.j;
}
pt _prev(pt p) {
	return prev[p.i][p.j];
}
pt _next(pt p) {
	return next[p.i][p.j];
}
pt npt = make_pair(-1, -1);
bool corner(pt p) {
	return _prev(p) != npt && _next(p) != npt && sub(p, _prev(p)) != sub(_next(p), p);
}
void attach(pt p, pt q) {
	// fprintf(stderr, "attaching (%lld %lld) (%lld %lld)\n", p.i, p.j, q.i, q.j);
	next[p.i][p.j] = q;
	prev[q.i][q.j] = p;
}
int path[1111][1111];
int compute_dist() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			dfsdist[i][j] = INF;
		}
	}
	dfsdist[si][sj] = 0;
	vector<pt> queue;
	queue.push_back(start);
	fr(f, queue.size()) {
		pt p = queue[f];
		fr(d,4) {
			pt q = go(p, d);
			if (grid[q.i][q.j] != '#' && dfsdist[q.i][q.j] >= INF) {
				dfsdist[q.i][q.j] = dfsdist[p.i][p.j] + 1;
				prev[q.i][q.j] = p;
				queue.push_back(q);
			}
		}
	}
	pt p = make_pair(ei, ej);
	while (p != start) {
		pt pr = prev[p.i][p.j];
		next[pr.i][pr.j] = p;
		p = pr;
	}
	return dfsdist[ei][ej];
}
bool goodcorner(pt prevc, pt p) {
	return prevc != npt && aligned(_prev(prevc), _next(p));
}

char cgrid[1111][1111];
int cdistance() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			dfsdist[i][j] = INF;
		}
	}
	dfsdist[si][sj] = 0;
	vector<pt> queue;
	queue.push_back(start);
	fr(f, queue.size()) {
		pt p = queue[f];
		fr(d,4) {
			pt q = go(p, d);
			if (cgrid[q.i][q.j] != '#' && dfsdist[q.i][q.j] >= INF) {
				dfsdist[q.i][q.j] = dfsdist[p.i][p.j] + 1;
				queue.push_back(q);
			}
		}
	}
	pt p = make_pair(ei, ej);
	while (p != start) {
		pt pr = prev[p.i][p.j];
		next[pr.i][pr.j] = p;
		p = pr;
	}
	return dfsdist[ei][ej];
}
bool try_remove(pt B, pt C, int odist) {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cgrid[i][j] = grid[i][j];
		}
	}
	pt A = _prev(B);
	pt D = _next(C);
	pt delta = sub(A, B);
	pt forward = sub(_next(B), B);
	pt curr = add(A, forward);
	while (curr != D) {
		cgrid[curr.i][curr.j] = '.';
		A = curr;
		curr = add(curr, forward);
	}
	return cdistance() == odist - 2;
}
void really_remove(pt B, pt C) {
	pt A = _prev(B);
	pt D = _next(C);
	pt delta = sub(A, B);
	pt forward = sub(_next(B), B);
	pt curr = add(A, forward);
	while (curr != D) {
		attach(A, curr);
		grid[curr.i][curr.j] = '.';
		A = curr;
		curr = add(curr, forward);
	}
	attach(A, curr);
}

bool solve() {
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (grid[i][j] == 'S') si = i, sj = j;
			if (grid[i][j] == 'F') ei = i, ej = j;
			prev[i][j] = next[i][j] = npt;
			path[i][j] = -1;
		}
	}
	start = make_pair(si, sj);
	end = make_pair(ei, ej);
	int mind = manh(sub(start, end)); // manhattan!
	int maxd = compute_seq();
	if (!(mind <= d && d <= maxd && (mind & 1) == (d & 1))) return false;

	for (; maxd > d; maxd -= 2) {
		// fprintf(stderr, "\n\nstart\n");

		for (pt p = start; p != end;) {
			path[p.i][p.j] = maxd;
			pt pp = _next(p);
			assert(_prev(pp) == p);
			p = pp;
		}
		path[ei][ej] = maxd;
		pt B = npt, C = npt;
		// /**/ fprintf(stderr, "now at %d\n", maxd);
    	/**/ for (int i = 0; i < r; i++) {
    	/**/ 	for (int j = 0; j < c; j++) {
    	/**/ 		pt xx = make_pair(i, j);
    	// /**/ 		fprintf(stderr, "%c", start == xx || end == xx ? grid[i][j] : B == xx ? 'B' : C == xx ? 'C' : path[i][j] == maxd ? 'o' : grid[i][j]);
    	/**/ 	}
    	// /**/ 	fprintf(stderr, "\n");
    	/**/ }

		pt p = start;
		pt prevc = npt;
		bool bad = true;
		while (p != end) {
			path[p.i][p.j] = maxd;
			if (corner(p)) {
				// fprintf(stderr, "corner %lld %lld\n", p.i, p.j);
				if (goodcorner(prevc, p)) {
					// /**/ fprintf(stderr, "trying\n");
			    	/**/ for (int i = 0; i < r; i++) {
			    	/**/ 	for (int j = 0; j < c; j++) {
			    	/**/ 		pt xx = make_pair(i, j);
			    	// /**/ 		fprintf(stderr, "%c", start == xx || end == xx ? grid[i][j] : prevc == xx ? 'B' : p == xx ? 'C' : path[i][j] == maxd ? 'o' : grid[i][j]);
			    	/**/ 	}
			    	// /**/ 	fprintf(stderr, "\n");
			    	/**/ }
					if (try_remove(prevc, p, maxd)) {
						// fprintf(stderr, "YEY\n");
						really_remove(prevc, p);
						bad = false;
						break;
					}
				}
				prevc = p;
			}
			p = _next(p);
		}
		if (bad) {
			// fprintf(stderr, "bad!!!!\n");
			return false;
		}
		// /**/ fprintf(stderr, "got\n");
    	/**/ for (int i = 0; i < r; i++) {
    	/**/ 	for (int j = 0; j < c; j++) {
    	/**/ 		pt xx = make_pair(i, j);
    	// /**/ 		fprintf(stderr, "%c", start == xx || end == xx ? grid[i][j] : path[i][j] == maxd ? 'o' : grid[i][j]);
    	/**/ 	}
    	// /**/ 	fprintf(stderr, "\n");
    	/**/ }
		for (pt p = start; p != end;) {
			pt pp = _next(p);
			pt ppp = _prev(pp);
			// fprintf(stderr, "(%lld %lld) -> (%lld %lld) -> (%lld %lld)\n", p.i, p.j, pp.i, pp.j, ppp.i, ppp.j);
			assert(ppp == p);
			p = pp;
		}
	}
	// fprintf(stderr, "good!!!!\n");
	return true;
}

int main() {
    int z;
    sf("%d", &z);
    fq(cas,z) {
    	scanf("%d%d%d", &r, &c, &d);
    	// fprintf(stderr, "\n\n\n\nr = %d, c = %d, d = %d\n", r, c, d);
    	for (int i = 0; i < r; i++) {
    		scanf("%s", grid[i]);
    		// fprintf(stderr, "%s\n", grid[i]);
    	}
    	bool possible = solve();
        pf("Case #%d: %s\n", cas, possible ? "POSSIBLE" : "IMPOSSIBLE");
        if (possible) {
        	for (int i = 0; i < r; i++) {
        		printf("%s\n", grid[i]);
        	}
        	int thedist = compute_dist();
        	// fprintf(stderr, "dist is %d == %d\n", thedist, d);
        	assert(thedist == d);
        }
    }
}
