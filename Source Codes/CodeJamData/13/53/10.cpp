using namespace std;
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cassert>
#include<cstring>
#include<cmath>

typedef long double D; typedef long long LL; typedef pair<int,int> pii;
#define ALL(v) (v).begin(),(v).end()
#define REP(i, n) for (int i (0); i < (n); i ++)
#define FORIT(a,b, it) for(__typeof(b)it(a);it!=(b);++it)
#define FOREACH(v, it) FORIT((v).begin(),(v).end(),it)
#define len(v) ((int)(v).size())
#define append push_back
#define _ make_pair
#define fi first
#define se second
#define add insert
#define remove erase
#define TWO(x) (1<<(x))
#define UNIQUE(v) (v).erase(unique(ALL(v)),(v).end())
const int infInt (1010101010);
const LL  infLL  (4 * LL (infInt) * LL (infInt));

template<class T>void pv(T a,T b){FORIT(a,b,it)cout<<*it<<" ";cout<<endl;}

inline void chmin(int&x,int y){x=min(x,y);}
inline void chmax(int&x,int y){x=max(x,y);}

#include <set>

struct Edge {
	int x, y;
	long long a, b;
	void read() { scanf("%d%d%lld%lld",&x,&y,&a,&b); }
};

int main() {
	int T;
	scanf("%d",&T);
	for (int case_nr=1; case_nr<=T; case_nr++) {
		// city 1 --> city 2
		int n, m, p;
		scanf("%d%d%d",&n,&m,&p);
		static int aa[2005];
		static int bb[2005];
		static Edge edges[2005];
		vector<vector<int> > adj (n + 1);
		for (int e=1; e<=m; e++) {
			edges[e].read();
			adj[edges[e].x].push_back(e);
		}
		vector<int> all_path (p);
		for (int i=0; i<p; i++) {
			scanf("%d",&all_path[i]);
		}
		int l = 0, r = (int) all_path.size();
		while (l != r) {
			int m = (l + r) / 2;
			vector<int> path (all_path.begin(), all_path.begin() + (m + 1));
			vector<bool> on_path (2005, false);
			FOREACH(path, it) on_path[*it] = true;
			vector<long long> d_ref; // max. weights
			{
				vector<long long> d (n + 1, infLL);
				set<pair<long long, int> > se; // (distance, city)
				d[1] = 0;
				se.insert(make_pair(d[1], 1));
				while (not se.empty()) {
					int x = (*se.begin()).second;
					se.erase(se.begin());
					FOREACH(adj[x], it) {
						int e = *it;
						Edge & edge (edges[e]);
						int y = edge.y;
						long long w = on_path[e] ? edge.a : edge.b;
						if (d[y] > d[x] + w) {
							se.erase(make_pair(d[y], y));
							d[y] = d[x] + w;
							se.insert(make_pair(d[y], y));
						}
					}
				}
				d_ref = d;
			}
			long long sum_weights=0;
			FOREACH(path, it) {
				int e = *it;
				sum_weights += edges[e].a;
			}
			bool ok;
			int to = edges[path.back()].y;
			if (sum_weights > d_ref[to]) {
				ok = false;
			}
			else {
				vector<long long> d (n + 1, infLL);
				set<pair<long long, int> > se; // (distance, city)
				d[to] = sum_weights;
				se.insert(make_pair(d[to], to));
				while (not se.empty()) {
					int x = (*se.begin()).second;
					se.erase(se.begin());
					FOREACH(adj[x], it) {
						int e = *it;
						Edge & edge (edges[e]);
						int y = edge.y;
						long long w = edge.a;
						if (d[y] > d[x] + w and d_ref[y] >= d[x] + w) {
							se.erase(make_pair(d[y], y));
							d[y] = d[x] + w;
							se.insert(make_pair(d[y], y));
						}
					}
				}
				ok = d[2] < infLL;
			}
			ok ? (l = m + 1) : (r = m);
		}
		printf("Case #%d: ", case_nr);
		if (l == (int) all_path.size()) printf("Looks Good To Me\n"); else printf("%d\n", all_path[l]);
	}
}
