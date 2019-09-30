// ConsoleApplication1.cpp : ????? ????????????? ???????????
//


#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
#include <utility>
#include <set>
#include <cctype>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <sstream>

#define FOR(i,a,b) for (long long i=(a);i<(b);i++)
#define RFOR(i,a,b) for (long long i=(b)-1;i>=(a);i--)
#define REP(i,n) for (unsigned long long i=0;i<(n);i++)
#define RREP(i,n) for (long long i=(n)-1;i>=0;i--)

#define inf INT_MAX/3
#define INF INT_MAX/3
#define llinf LLONG_MAX/3
#define LLINF LLONG_MAX/3
#define PB push_back
#define pb push_back
#define MP make_pair
#define mp make_pair
#define ALL(a) (a).begin(),(a).end()
#define all(a) (a).begin(),(a).end()
#define SET(a,c) memset(a,c,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define PII pair<int,int>
#define pii pair<int,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define VLL vector<long long>
#define VULL vector<unsigned long long>
#define debug(x) cout<<#x<<": "<<x<<endl
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define MIN(a,b) (a>b?b:a)
#define MAX(a,b) (a>b?a:b)
#define pi 2*acos(0.0)
#define INFILE() freopen("in0.txt","r",stdin)
#define OUTFILE()freopen("out0.txt","w",stdout)
#define in scanf
#define out printf
#define LL long long
#define ll long long
#define ULL unsigned long long
#define ull unsigned long long
#define eps 1e-14
#define FST first
#define SCD second

const LL MAX = 1000000007;

using namespace std;

struct Town
{
	LL i;
	LL x;
	LL y;

	Town()
	{
	}

	Town(LL _i, LL _x, LL _y)
	{
		i = _i;
		x = _x;
		y = _y;
	}

	static bool greater_x(const Town& t0, const Town& t1)
	{
		return t0.x < t1.x;
	}
	static bool greater_y(const Town& t0, const Town& t1)
	{
		return t0.y < t1.y;
	}
};

// Union Find
struct UnionFind
{
	const LL N;
	VLL parent;
	VLL rank;

	UnionFind(LL n)
		:N(n)
	{
		parent = VLL(N);
		rank = VLL(N, 0);
		for (size_t i = 0; i < N; i++) {
			parent[i] = i;
		}
	}

	int root(LL i)
	{
		return parent[i] == i ? i : parent[i] = root(parent[i]);
	}

	bool same(LL i, LL j)
	{
		return root(i) == root(j);
	}

	void unite(LL i, LL j)
	{
		i = root(i);
		j = root(j);
		if (i == j) {
			return;
		}

		if (rank[i] < rank[j]) {
			parent[i] = j;
		}
		else {
			parent[j] = i;
			if (rank[i] == rank[j]) {
				rank[i]++;
			}
		}
	}

	bool isOne()
	{
		for (size_t i = 1; i < N; i++) {
			if (!same(0, i)) {
				return false;
			}
		}
		return true;
	}
};

template <typename T>
struct Graph
{
	struct Node
	{
		T value;

		Node()
		{
		}

		Node(T _value)
		{
			value = _value;
		}
	};

	struct Edge
	{
		LL i;
		LL j;
		LL cost;

		Edge(LL _i, LL _j, LL _cost)
		{
			i = _i;
			j = _j;
			cost = _cost;
		}

		static bool greater(const Edge& e0, const Edge& e1)
		{
			return e0.cost < e1.cost;
		}
	};

	vector<Node> nodes;
	vector<Edge> edges;

	void add(Node node)
	{
		nodes.push_back(node);
	}

	void add(Edge edge)
	{
		edges.push_back(edge);
	}

	LL getMSTLength()
	{
		LL ret = 0;
		sort(edges.begin(), edges.end(), Edge::greater);

		UnionFind uf(nodes.size());
		for (size_t i = 0; i < edges.size(); i++) {
			//if (uf.isOne()) {
			//	break;
			//}
			if (!uf.same(edges[i].i, edges[i].j)) {
				uf.unite(edges[i].i, edges[i].j);
				ret += edges[i].cost;
			}
		}
		return ret;
	}
};



#define VT vector<Town>

signed main()
{
	LL N;
	LL ret = 0;

	cin >> N;
	VLL x(N);
	VLL y(N);
	for (size_t i = 0; i < N; i++) {
		cin >> x[i] >> y[i];
	}

	VT vt(N);
	Graph<LL> graph;
	for (size_t i = 0; i < N; i++) {
		Town t(i, x[i], y[i]);
		graph.add(Graph<LL>::Node(i));
		vt[i] = t;
	}

	sort(vt.begin(), vt.end(), Town::greater_x);
	for (size_t i = 0; i < N - 1; i++) {
		graph.add(Graph<LL>::Edge(vt[i].i, vt[i + 1].i, abs(vt[i + 1].x - vt[i].x)));
	}

	sort(vt.begin(), vt.end(), Town::greater_y);
	for (size_t i = 0; i < N - 1; i++) {
		graph.add(Graph<LL>::Edge(vt[i].i, vt[i + 1].i, abs(vt[i + 1].y - vt[i].y)));
	}

	ret = graph.getMSTLength();

	cout << ret;

	return 0;
}