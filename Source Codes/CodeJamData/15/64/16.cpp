#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cassert>
#include <cmath>
#include <cstring>
#include <functional>
using namespace std;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef long long ll;
#define REP(i,a,n) for (int i = (a); i < (n); i++)

template<class T> T& setmin(T &a, const T &b) {return a = min(a, b);}
template<class T> T& setmax(T &a, const T &b) {return a = max(a, b);}
template<class T> T MODD(const T &a, const T &b) {T r = a%b; if (r < 0) r += b; return r;}

int N, M, K;
VI adj[100];
int dist[100];

const int INF = 1E9;


int S; // source
int T; // sink
int FN; // number of nodes
int FM; // number of edges (initialize this to 0)
// ra[a]: edges connected to a (NO MATTER WHICH WAY!!!); clear this in the beginning
VI ra[100000];
int kend[1000000], cap[1000000]; // size: TWICE the number of edges
// Adds an edge from a to b with capacity c and returns the number of the new edge
int addedge(int a, int b, int c) {
// 	fprintf(stderr, "add %d -> %d (%d)\n", a, b, c);
	int i = 2*FM;
	kend[i] = b;
	cap[i] = c;
	ra[a].push_back(i);
	kend[i+1] = a;
	cap[i+1] = 0;
	ra[b].push_back(i+1);
	FM++;
	return i;
}

bool fou[100000];
PII pre[100000];
// Returns the maximum flow from the source to the sink
ll solve() { // reinitialize costs if rerun
	ll totflow = 0;
	while(true) {
		memset(fou, 0, sizeof(fou));
		queue<int> qu;
		qu.push(S);
		fou[S] = true;
		while(!qu.empty()) {
			int i = qu.front();
			qu.pop();
			if (i == T)
				break;
			for (int e : ra[i]) {
				int k = kend[e];
				if (cap[e] > 0 && !fou[k]) {
					qu.push(k);
					pre[k] = PII(i,e);
					fou[k] = true;
				}
			}
		}
		if (!fou[T])
			break;
		int mk = INF;
		for (int i = T; i != S; i = pre[i].first)
			mk = min(mk, cap[pre[i].second]);
		totflow += mk;
		for (int i = T; i != S; i = pre[i].first) {
			cap[pre[i].second] -= mk;
			cap[pre[i].second^1] += mk;
		}
	}
	return totflow;
}

void docase() {
	scanf("%d%d%d", &N, &M, &K);
	REP(i,0,N)
		adj[i].clear();
	REP(i,0,M) {
		int a, b;
		scanf("%d%d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fill_n(dist, N, INF);
	queue<int> qu;
	dist[0] = 0;
	qu.push(0);
	while(!qu.empty()) {
		int i = qu.front();
		qu.pop();
		for (int j : adj[i]) {
			if (dist[j] > dist[i]+1) {
				dist[j] = dist[i]+1;
				qu.push(j);
			}
		}
	}
	S = 1;
	T = 2*(N-1);
	fill_n(ra, 1000, VI());
	FN = 2*N;
	FM = 0;
	REP(i,0,N)
		addedge(2*i, 2*i+1, 1);
	REP(i,0,N)
		for (int j : adj[i])
			if (dist[j] == dist[i]+1)
				addedge(2*i+1, 2*j, INF);
	ll sol = solve();
	fprintf(stderr, "dist = %d, solve = %lld\n", dist[N-1], sol);
	int res = 0;
	if (sol <= K-1)
		res = dist[N-1]+2;
	else
		res = dist[N-1]+1;
	printf("%d\n", res);
}

int main() {
	int T;
	scanf("%d ", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		docase();
		fflush(stdout);
		fflush(stderr);
	}
	return 0;
}
