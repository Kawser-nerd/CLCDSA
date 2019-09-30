#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cctype>
#include <cassert>
#include <limits>
#include <functional>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
#if defined(_MSC_VER) || __cplusplus > 199711L
#define aut(r,v) auto r = (v)
#else
#define aut(r,v) __typeof(v) r = (v)
#endif
#define each(it,o) for(aut(it, (o).begin()); it != (o).end(); ++ it)
#define all(o) (o).begin(), (o).end()
#define pb(x) push_back(x)
#define mp(x,y) make_pair((x),(y))
#define mset(m,v) memset(m,v,sizeof(m))
#define INF 0x3f3f3f3f
#define INFL 0x3f3f3f3f3f3f3f3fLL
using namespace std;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> inline void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> inline void amax(T &x, U y) { if(x < y) x = y; }

template<typename T> struct GetID {
	map<T, int> ids;
	vector<T> values;
	void clear() { ids.clear(); }
	int size() const { return values.size(); }
	int get(const T &x) {
		typename map<T, int>::iterator it = ids.find(x);
		if(it != ids.end()) return it->second;
		int newID = values.size();
		values.push_back(x);
		ids.insert(make_pair(x, newID));
		return newID;
	}
};

int bipartiteMatching(const vector<vector<int> > &g) {
	int nleft = g.size(), nright = 0;
	each(es, g) if(!es->empty()) nright = max(nright, *max_element(es->begin(), es->end()) + 1);
	vi matchL(nleft, -1), matchR(nright, -1), prev(nleft), seen(nleft, -1);
	rep(i, nleft) {
		vi stk; stk.push_back(i);
		seen[i] = i; prev[i] = -1;
		while(!stk.empty()) {
			int v = stk.back(); stk.pop_back();
			each(ui, g[v]) {
				int u = *ui;
				int j = matchR[u];
				if(j == -1) {
					while(v != -1) {
						matchR[u] = v;
						swap(u, matchL[v]);
						v = prev[v];
					}
					goto break_;
				} else if(seen[j] < i) {
					seen[j] = i; prev[j] = v;
					stk.push_back(j);
				}
			}
		}
	break_:;
	}
	return (int)matchL.size() - count(matchL.begin(), matchL.end(), -1);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int ii = 0; ii < T; ++ ii) {
		int N;
		scanf("%d", &N);
		GetID<string> idL, idR;
		vpii edges;
		rep(i, N) {
			char w1[30], w2[30];
			scanf("%s%s", w1, w2);
			int a = idL.get(w1);
			int b = idR.get(w2);
			edges.emplace_back(a, b);
		}
		int L = idL.size(), R = idR.size();
		vector<vi> g(L);
		for(auto e : edges)
			g[e.first].push_back(e.second);
		int m = bipartiteMatching(g);
		int cover = m + (L + R - m * 2);
		int ans = N - cover;
		printf("Case #%d: %d\n", ii + 1, ans);
	}
	return 0;
}
