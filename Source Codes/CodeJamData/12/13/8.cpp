#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <algorithm>
#include <bitset>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <map>
#include <queue>
#include <assert.h>

using namespace std;

#define sz(x) ((int)x.size())
#define all(x) (x).begin(), (x).end()
#define pb(x) push_back(x)
#define mp(x, y) make_pair(x, y)

#define forit(X,Y) for(typeof((Y).begin()) X = (Y).begin(); X != (Y).end(); ++X)

#define debug(x) cout << '>' << #x << ':' << x << endl;

typedef long long int64;

typedef vector <int> vi;
typedef vector < vi > vvi;


const double INF = 1000000;
const double EPS = 1E-6;

struct Edge {
	int i, j;
	double tstart, tend;
	int orient; // 1 - i & !j, -1 - !i & j
};

bool operator < (const Edge& e1, const Edge& e2) {
	return e1.tstart < e2.tstart || e1.tstart == e2.tstart && e1.tend < e2.tend;
}

bool intersect(const Edge& e1, const Edge& e2) {
	assert(e1.tstart < e2.tstart + EPS);
	return e1.tend > e2.tstart + EPS && (e2.i == e1.i || e2.j == e1.j || e2.j == e1.i || e2.i == e1.j);
}

int getOrient(const Edge& e1, const Edge& e) {
	assert(e1.orient != 0);
	if (e.i == e1.i || e.j == e1.j)
		return e1.orient;
	assert(e.i == e1.j || e.j == e1.i);
	return -e1.orient;
}

void propagate(vector<Edge>& edges, int i) {
	Edge& e = edges[i];
	for (int j = 0; j < edges.size(); ++j) {
		if (j == i) continue;
		Edge& e1 = edges[j];
		if (e1.orient != 0)
			continue;
		if (j < i && intersect(e1, e) || j > i && intersect(e, e1)) {
			e1.orient = getOrient(e, e1);
			propagate(edges, j);
		}
	}
}

int main() {
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);

	int testCount;
    cin >> testCount;
    for (int testNumber = 1; testNumber <= testCount; ++testNumber) {
    	int n;
    	cin >> n;
    	vector<int> v(n), p(n);
    	vector<bool> l(n);
    	for (int i = 0; i < n; ++i) {
    		char c;
    		cin >> c >> v[i] >> p[i];
    		l[i] = c == 'R';
    	}
    	double res = INF;

    	vector<Edge> edges;
    	for (int i = 0; i < n; ++i) {
    		for (int j = i + 1; j < n; ++j) {
    			if (v[i] == v[j]) {
    				if (abs(p[i] - p[j]) < 5) {
    					Edge e;
    					e.i = i;
    					e.j = j;
    					e.tstart = -INF;
    					e.tend = INF;
    					if (l[i]) {
    						assert(!l[j]);
    						e.orient = 1;
    					} else {
    						assert(l[j]);
    						e.orient = -1;
    					}
    					edges.push_back(e);
    				}
    			} else {
    				double t1 = 1.0 * (p[j] - p[i] - 5) / (v[i] - v[j]);
    				double t2 = 1.0 * (p[j] + 5 - p[i]) / (v[i] - v[j]);
    				if (t1 > t2) {
    					swap(t1, t2);
    				}
    				if (t1 < EPS && t2 < EPS)
    					continue;
    				if (t1 < EPS && t1 > -EPS)
    					t1 = 0;
    				Edge e;
    				e.i = i;
    				e.j = j;
    				e.tstart = t1;
    				e.tend = t2;
    				e.orient = 0;
    				if (t1 < -EPS) {
    					if (l[i]) {
							assert(!l[j]);
							e.orient = 1;
						} else {
							assert(l[j]);
							e.orient = -1;
						}
    				}
    				edges.push_back(e);
    			}
    		}
    	}
    	sort(all(edges));

    	for (int i = 0; i< edges.size(); ++i) {
    		Edge& e = edges[i];
    		int desired = e.orient;
    		e.orient = 0;
    		bool br = false;
    		for (int j = 0; j < i; ++j) {
    			Edge& e1 = edges[j];
    			if (intersect(e1, e)) {
    				int or1 = getOrient(e1, e);
    				if (e.orient == 0)
    					e.orient = or1;
    				if (e.orient != or1) {
    					res = e.tstart;
    					br = true;
    					break;
    				}
    			}
    		}
    		if (br) {
				break;
			}
    		if (e.orient == 0)
    			e.orient = desired;
    		if (e.orient == 0)
    		    e.orient = 1;
    		propagate(edges, i);
    	}

    	if (res < INF)
    		printf("Case #%d: %.6lf\n", testNumber, res);
    		//cout << "Case #" << testNumber << ": " << res << endl;
    	else
    		cout << "Case #" << testNumber << ": " << "Possible" << endl;
    }

    return 0;
}
