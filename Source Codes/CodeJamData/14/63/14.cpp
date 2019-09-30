#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <queue>
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 
#include <cstring> 

using namespace std; 

typedef long long ll; 
typedef pair<int, int> pii;

#define INF 1000000000
#define pb push_back 
#define itr iterator 
#define sz size() 
#define mp make_pair

int numbertot, teste;
int n,a,b;
vector<pii> edges;
vector<int> adj[30000];
unsigned long long t[30000];
int size[30000];
char color[30000];
int order[30000];

int dfs(int v, int p, int e) {
	if (size[e] != -1) return size[e];

	size[e] = 1;

	for (int i = 0; i < adj[v].size(); i++) {
		int dest;
		if (adj[v][i] >= n-1) {
			dest = edges[adj[v][i] - (n-1)].first;
		}
		else {
			dest = edges[adj[v][i]].second;
		}
		if (dest != p) size[e] += dfs(dest, v, adj[v][i]);
	}

	return size[e];
}

int v_to_e(int v) {
	return 2*(n-1) + v;
}

unsigned long long newr() {
	unsigned long long a = rand();
	unsigned long long b = rand();
	unsigned long long c = rand();
	unsigned long long d = rand();
	unsigned long long e = rand();
	 
	return (a << 48) + (b << 32) + (c << 16) + d + (e&1);
}

pair<int, unsigned long long> get_seq(int e) {
	int v, p;
	if (e >= (n-1)) {
		v = edges[e-(n-1)].first;
		p = edges[e-(n-1)].second;
	}
	else {
		v = edges[e].second;
		p = edges[e].first;
	}

	pair<int, unsigned long long> ans;
	ans.first = color[v];
	ans.second = 0;

	for (int i = 0; i < adj[v].size(); i++) {
		int dest;
		if (adj[v][i] >= n-1) {
			dest = edges[adj[v][i] - (n-1)].first;
		}
		else {
			dest = edges[adj[v][i]].second;
		}

		if (dest != p) {
			unsigned long long th = t[adj[v][i]];
			ans.second += th;
		}
	}

	return ans;
}

bool check(int v, int p) {
	set<unsigned long long> s;

	for (int i = 0; i < adj[v].size(); i++) {
		int dest;
		if (adj[v][i] >= n-1) {
			dest = edges[adj[v][i] - (n-1)].first;
		}
		else {
			dest = edges[adj[v][i]].second;
		}

		if (dest != p) {
			unsigned long long th = t[adj[v][i]];
			set<unsigned long long>::iterator it = s.find(th);
			if (it == s.end()) s.insert(th);
			else s.erase(it);
		}
	}

	int tam = s.size();
	/*printf("check %d %d tam %d\n", v, p, tam);
	for (set<unsigned long long>::iterator it = s.begin(); it != s.end(); it++) {
		printf("%llu ", *it);
	}
	printf("\n");*/

	if (tam == 0) return true;
	if (tam == 1) {
		for (int i = 0; i < adj[v].size(); i++) {
			int dest;
			if (adj[v][i] >= n-1) {
				dest = edges[adj[v][i] - (n-1)].first;
			}
			else {
				dest = edges[adj[v][i]].second;
			}

			if (dest != p) {
				unsigned long long th = t[adj[v][i]];
				
				set<unsigned long long>::iterator it = s.find(th);
				if (it != s.end()){
					bool ret = check(dest, v);	
					//printf("check %d %d = %d\n", v, p, ret);
					return ret;
				} 
			}
		}
	}
	else return false;
}

bool comps(int a, int b) {
	return size[a] < size[b];
}

int main() {
	srand(5886);

	for (scanf("%d", &numbertot); numbertot; numbertot--) {
		memset(size, -1, sizeof(size));

		edges.clear();
		for (int i = 0; i < n; i++) adj[i].clear();

		printf("Case #%d: ", ++teste);
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			scanf(" %c", &color[i]);
		}

		for (int i = 0; i < n-1; i++) {
			scanf("%d %d", &a, &b); a--; b--;
			edges.push_back(mp(a,b));
			adj[a].push_back(i);
			adj[b].push_back((n-1) + i);
		}

		for (int i = 0; i < n-1; i++) {
			if (size[i] == -1) dfs(edges[i].second, edges[i].first, i);
			if (size[(n-1) + i] == -1) dfs(edges[i].first, edges[i].second, i + (n-1));
		}

		/*for (int i = 0; i < n; i++) {
			if (size[v_to_e(i)] == -1) dfs(i, -1, v_to_e(i));
		}*/

		for (int i = 0; i < 2*(n-1); i++) {
			order[i] = i;
		}
		sort(order, order + 2*(n-1), comps);

		int cur = 0;
		while (cur < 2*(n-1)) {
			int st = cur;
			int th = size[order[cur]];
			while (cur < 2*(n-1) && size[order[cur]] == th) cur++;

			vector< pair< pair<int, long long >, int > > seqs;
			for (int k = st; k < cur; k++) {
				seqs.push_back(make_pair(get_seq(order[k]), order[k]));
			}

			sort(seqs.begin(), seqs.end());

			unsigned long long cur_t = 0;
			for (int k = 0; k < seqs.size(); k++) {
				if (k == 0 || seqs[k].first != seqs[k-1].first) {
					cur_t = newr();
				}
				//printf("t[%d]=%llu (%d %llu)\n", seqs[k].second, cur_t, seqs[k].first.first, seqs[k].first.second);
				t[seqs[k].second] = cur_t;
			}
		}

		for (int i = 0; i < 2*(n-1); i++) {
			int to,fr;
			if (i >= n-1) to = edges[i-(n-1)].first, fr = edges[i-(n-1)].second;
			else fr = edges[i].first, to = edges[i].second;
			//printf("%d (%d -> %d): %llu\n", i, fr+1, to+1, t[i]);
		}

		bool ok = false;
		for (int i = 0; i < n && !ok; i++) {
			if (check(i, -1)) {
				ok = true;
			}
		}

		for (int i = 0; i < (n-1) && !ok; i++) {
			if (t[i] == t[i + (n-1)]) ok = true;
		}

		printf("%s\n", ok ? "SYMMETRIC" : "NOT SYMMETRIC");
	}

    return 0;
}