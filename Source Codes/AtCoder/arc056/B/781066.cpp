#include <iostream>
#include <queue>
#include <map>
#include <list>
#include <vector>
#include <string>
#include <limits>
#include <cassert>
#include <fstream>
#include <cstring>
#include <bitset>
#include <iomanip>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <ciso646>
#include <array>

using namespace std;

#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)

#define inf 0x3f3f3f3f
#define CLEAR(a) a = decltype(a)()
#define MP make_pair
#define ALL(a) (a).begin(),(a).end()
#define pii pair<int ,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VI vector<int>
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define pi 2*acos(0.0)
#define INFILE() freopen("in.txt","r",stdin)
#define OUTFILE() freopen("out.txt","w",stdout)
#define ll long long
#define ull unsigned long long
#define eps 1e-14
#define FIN std::ifstream cin("D:\input.txt")

template<int N>
class union_find {
private:
	int par[N];
	int rank[N];
public:

	union_find() {
		for (int i = 0; i < N; ++i) {
			par[i] = i;
			rank[i] = 0;
		}
	}

	int find(int x) {
		if (par[x] == x) {
			return x;
		}
		else {
			return par[x] = find(par[x]);
		}
	}

	void unite(int x, int y) {
		x = find(x);
		y = find(y);
		if (x == y) return;

		if (rank[x] < rank[y]) {
			par[x] = y;
		}
		else {
			par[y] = x;
			if (rank[x] == rank[y]) rank[x]++;
		}
	}

	bool same(int x, int y) {
		return find(x) == find(y);
	}
};

union_find<200001> uf;

int main(void) {
	int N, M, S; cin >> N >> M >> S;
	--S;
	vector<vector<int> > V(N);
	REP(i, M) {
		int u, v; cin >> u >> v;
		--u, --v;
		V[min(u,v)].push_back(max(u,v));
	}


	vector<int> res;

	RFOR(i, 0, N) {
		for (int to : V[i]) {
			uf.unite(i, to);
		}
		if (uf.same(i,S)) {
			res.push_back(i);
		}
	}

	reverse(ALL(res));

	for (auto a : res) {
		cout << a+1 << endl;
	}

	return 0;
}