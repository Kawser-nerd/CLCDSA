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

int dbg = 0;

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

class Mixture {
public:
	int i;
	vector<int> ing;
};

vector<long long> memo;
map<string, int> mxi;

long long doit(const vector<Mixture> &rec, int w) {
	if (memo[w] >= 0) return memo[w];
	if (rec[w].ing.empty()) return memo[w] = 1;

	vector<int> nb(rec[w].ing.size(), 0);
	for (int i = 0; i < nb.size(); i++) nb[i] = doit(rec, rec[w].ing[i]);

	sort(nb.rbegin(), nb.rend());
	long long mx = nb[0];
	for (int i = 1; i < nb.size(); i++) if (nb[i]+i > mx) mx = nb[i]+i;
	if (nb.size()+1 > mx) mx = nb.size()+1;
if (dbg) printf(" %d -> %d\n", w, mx);
	return memo[w] = mx;
}

long long solveIt(const vector<Mixture> &rec) {
	memo.clear();
	memo.resize(rec.size(), -1);


	vector<int> uct(rec.size(), 0);
	for (int i = 0; i < rec.size(); i++)
	       	for (int j = 0; j < rec[i].ing.size(); j++)
			uct[rec[i].ing[j]]++;

	int w = 0;
	for (int i = 0; i < uct.size(); i++) if (!uct[i]) w = i;

	for (int i = 0; i < rec.size(); i++) if (memo[i] < 0) doit(rec, i);

	return memo[w];
}

int mct;
int getIdx(string s) {
	int idx = -1;
	if (mxi.find(s) == mxi.end()) {
		idx = mct++;
		mxi[s] = idx;
	} else
		idx = mxi[s];
	return idx;
}

int main(int argc, char ** /*argv*/) {
	dbg = argc-1;
	int CCT = readIntLine();
	for (int cn = 1; cn <= CCT; cn++) {
		int N;
		scanf("%d ", &N);

		vector<Mixture> rec(N);
		char sz[100];
	       	int n;
		mxi.clear();
		mct = 0;
if (dbg) printf("\n\n\nN %d\n", N);
		for (int i = 0; i < N; i++) {
			scanf(" %99s %d", sz, &n);
			int idx = getIdx(sz);
			rec[idx].i = idx;
if (dbg) printf("%s -> %d\n", sz, rec[idx].i);
			for (int j = 0; j < n; j++) {
				scanf(" %99s", sz);
				if (sz[0] < 'a') {
					rec[idx].ing.push_back(getIdx(sz));
if (dbg) printf(" -- %d\n", rec[idx].ing.back());
				}
			}
if (dbg) printf("  ###### %d\n", rec[idx].ing.size());
		}

		long long res = solveIt(rec);
		printf("Case #%d: %lld\n", cn, res);
	}
	return 0;
}

