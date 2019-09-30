#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <set>
#include <map>

using namespace std;

int dbg;

string readLine() {
	char sz[1000];
	fgets(sz, 1000, stdin);
	int l = strlen(sz);
	if (sz[l-1] == '\n') sz[l-1] = 0;
	return sz;
}

int readIntLine() {
	string s = readLine();
	return atoi(s.c_str());
}

vector<int> readVI() {
	int n;
	scanf("%d ", &n);
	vector<int> v(n);
	for (int i = 0; i < n; i++) scanf("%d ", &v[i]);
	return v;
}

double solveIt(vector<vector<double> > &p, int M) {
	for (int i = 0; i < p.size(); i++) sort(p[i].rbegin(), p[i].rend());
	sort(p.rbegin(), p.rend());

	double pc = 1.0, ip;
	for (int i = 0; i < p.size(); i++) pc *= p[i][0];
	
	priority_queue<pair<double, vector<int> > > pq;
	pq.push(make_pair(pc, vector<int>(p.size(), 0)));

	set<vector<int> > seen;

	seen.insert(vector<int>(p.size(), 0));
	int n = 0;
	double ans = 0.0;
	while (n < M && !pq.empty()) {
		n++;
		double v = pq.top().first;
		ans += v;
		vector<int> w = pq.top().second;

if (dbg) {
	for (int i = 0; i < w.size(); i++) printf("%d ", w[i]);
	printf("%.6lf\n", v);
}

		pq.pop();
		for (int i = 0; i < w.size(); i++) if (w[i] < 3) {
			if (p[i][w[i]] == 0.0) continue;
			double nv = v*p[i][w[i]+1]/p[i][w[i]];
			w[i]++;
			if (!seen.count(w)) {
				seen.insert(w);
				pq.push(make_pair(nv, w));
			}
			w[i]--;
		}
	}

	return ans;
}

int main(int argc, char ** /*argv*/) {
	dbg = argc-1;
	int CCT = readIntLine();
	for (int cn = 1; cn <= CCT; cn++) {
		int Q, M;
		scanf("%d %d ", &M, &Q);
		vector<vector<double> > p(Q, vector<double>(4));
		for (int i = 0; i < Q; i++) scanf("%lf %lf %lf %lf", &p[i][0], &p[i][1], &p[i][2], &p[i][3]);

		double res = solveIt(p, M);
		printf("Case #%d: %.15lf\n", cn, res);
	}
	return 0;
}

