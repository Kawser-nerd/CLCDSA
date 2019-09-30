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
#define REP(i,n) for (long long i=0;i<(n);i++)
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
#define PLL pair<long long,long long>
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

using namespace std;

const LL ANS_MAX = 1000000007;

struct Heap
{
	struct Node
	{
		LL i;
		LL cost;

		Node(LL _i, LL _cost)
		{
			i = _i;
			cost = _cost;
		}
	};

	vector<Node> nodes;

	void push(Node node)
	{
		nodes.push_back(node);
		LL i = nodes.size() - 1;
		while (0 < i) {
			LL parent_i = (i - 1) / 2;
			if (node.cost < nodes[parent_i].cost) {
				swap(i, (i - 1) / 2);
				i = parent_i;
			}
			else {
				break;
			}
		}
	}

	Node pop()
	{
		Node root = nodes[0];
		swap(0, nodes.size() - 1);
		nodes.pop_back();

		LL i = 0;
		LL child_l_i = i * 2 + 1;
		LL child_r_i = i * 2 + 2;
		while (child_r_i < size()) {
			if (child_r_i < size()) {
				LL child_i = nodes[child_l_i].cost < nodes[child_r_i].cost ? child_l_i : child_r_i;
				if (nodes[child_i].cost < nodes[i].cost) {
					swap(i, child_i);
					i = child_i;
				}
				else {
					break;
				}
			}
			else {
				if (nodes[child_l_i].cost < nodes[i].cost) {
					swap(i, child_l_i);
					i = child_l_i;
				}
				else {
					break;
				}
			}

			child_l_i = i * 2 + 1;
			child_r_i = i * 2 + 2;
		}

		return root;
	}

	size_t size()
	{
		return nodes.size();
	}

	size_t isEmpty()
	{
		return nodes.size() == 0;
	}

	void swap(size_t i, size_t j)
	{
		Node temp = nodes[i];
		nodes[i] = nodes[j];
		nodes[j] = temp;
	}
};

struct Graph
{
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
	};

	struct Vertex
	{
		vector<Edge> edges;

		Vertex()
		{
		}

		void add(Edge edge)
		{
			edges.push_back(edge);
		}
	};

	vector<Vertex> vertexes;
	vector<Edge> edges;

	Graph(ULL n)
	{
		vertexes = vector<Vertex>(n);
	}

	void add(Vertex vertex)
	{
		vertexes.push_back(vertex);
	}

	void add(Edge edge)
	{
		edges.push_back(edge);
		vertexes[edge.i].add(edge);
	}

	ULL size()
	{
		return vertexes.size();
	}

	// ???????
	VLL distances;

	struct Path
	{
		LL i;
		LL cost;

		Path(LL _i, LL _cost)
		{
			i = _i;
			cost = _cost;
		}

		bool operator<(const Path& path) const
		{
			return cost > path.cost;
		}
	};

	VLL getShortestDistances(LL start_node_i)
	{
		Vertex& start_i = vertexes[start_node_i];

		distances = VLL(size(), ANS_MAX);
		distances[start_node_i] = 0;

		Heap heap;
		heap.push(Heap::Node(start_node_i, 0));

		while (!heap.isEmpty()) {
			LL node_i = heap.pop().i;
			for (size_t i = 0; i < vertexes[node_i].edges.size(); i++) {
				Edge& edge = vertexes[node_i].edges[i];
				if (edge.j == start_node_i) {
					continue;
				}
				if (distances[node_i] + edge.cost < distances[edge.j]) {
					distances[edge.j] = distances[node_i] + edge.cost;
					heap.push(Heap::Node(edge.j, distances[edge.j]));
				}
			}
		}
		return distances;
	}
};

int main()
{
	LL N;
	LL M;
	LL T;
	cin >> N >> M >> T;
	VLL A(N);
	VLL a(M);
	VLL b(M);
	VLL c(M);
	for (size_t i = 0; i < N; i++) {
		cin >> A[i];
	}

	for (size_t i = 0; i < M; i++) {
		cin >> a[i] >> b[i] >> c[i];
	}

	Graph g_go(N);
	for (size_t i = 0; i < M; i++) {
		g_go.add(Graph::Edge(a[i] - 1, b[i] - 1, c[i]));
	}

	Graph g_re(N);
	for (size_t i = 0; i < M; i++) {
		g_re.add(Graph::Edge(b[i] - 1, a[i] - 1, c[i]));
	}

	LL ret = 0;
	LL m;
	VLL d_go = g_go.getShortestDistances(0);
	VLL d_re = g_re.getShortestDistances(0);
	for (size_t i = 0; i < N; i++) {
		if (d_go[i] == ANS_MAX || d_re[i] == ANS_MAX) {
			continue;
		}
		m = A[i] * (T - d_go[i] - d_re[i]);
		if (ret < m) {
			ret = m;
		}
	}
	cout << ret << endl;

	return 0;
}