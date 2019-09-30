#include<iostream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<map>
#include<iomanip>
using namespace std;
#define INF 1<<20


struct edge{
	int to;
	int cost;
	edge() {};
	edge(int a, int b) {
		to = a;
		cost = b;
	}
};

struct Node {
	int pos;
	int cost;
	Node() {};
	Node(int a, int b) {
		pos = a;
		cost = b;
	}
	bool operator <(const Node& rhs) const {
		return cost > rhs.cost;
	}
};

void dijkistra(int st, int TO,int V,vector<vector<edge> > graph) {
	priority_queue<Node> q;
	vector<int> d(V);
	for (int i = 0;i < V;i++) {
		d[i] = INF;
	}
	d[st] = 0;
	q.push(Node(st, 0));
	while (!q.empty()) {
		Node s = q.top(); q.pop();
		int pos = s.pos;
for (int i = 0;i < graph[pos].size();i++) {
	int to = graph[pos][i].to;
	int cost = graph[pos][i].cost;
	if (d[pos] + cost < d[to]) {
		d[to] = d[pos] + cost;
		q.push(Node(to, d[to]));
	}

}
	}
	cout << d[TO] << endl;
}
int partition(int A[], int p, int r) {
	int x = A[r];
	int i = p - 1;
	for (int j = p;j < r;j++) {
		if (x >= A[j]) {
			i = i + 1;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}
void quicksort(int A[], int p, int r) {
	if (p < r) {
		int q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}

int getNumberOfCoin(int C[], int n, int m) {
	int T[50000];
	for (int j = 0;j <= n;j++) {
		T[j] = INF;
	}
	T[0] = 0;
	for (int i = 0;i < m;i++) {
		for (int j = 0;j <= n;j++) {
			if (j - C[i] >= 0) {
				T[j] = min(T[j], T[j - C[i]] + 1);
			}
		}
	}
	return T[n];
}
int knapsack(int w, int n, int* v, int* ww) {
	int W[101][10001];
	for (int j = 0;j <= w;j++) {
		W[0][j] = 0;
	}
	for (int i = 0;i < n;i++) {
		for (int k = 0;k < n;k++) {
			for (int j = 0;j <= w;j++) {
				if (j - ww[k] < 0) {
					W[i + 1][j] = W[i][j];
				}
				if (j - ww[i] >= 0) {
					W[i + 1][j] = max(W[i][j], W[i][j - ww[k]] + v[k]);

				}
			}
		}
	}
	return W[n][w];
}
int fib(int n) {
	vector<int> v(n + 1);
	v[0] = 1;
	v[1] = 1;
	for (int i = 2;i < n + 1;i++) {
		v[i] = v[i - 2] + v[i - 1];
	}
	return v[n];
}
int isPrime(int x) {
	if (x <= 1) return false;
	if (x > 2 && x % 2 == 0) return false;
	for (int i = 2;i <= sqrt(x);i++) {
		if (x%i == 0) {
			return false;
		}
	}
	if (x == 2) return true;
	return true;
}
int gnc(int a, int b) {
	while (b%a != 0) {
		if (a > b) swap(a, b);
		else {
			b = b%a;
		}
	}
	return a;
}
vector<pair<int, int> > b(100000);
vector<int> src(100000);

int main() {
	string s;
	int A, B, C,D;
	cin >> s;
	cin >> A >> B >> C>>D;
	s.insert(s.begin() + A, '"');
	s.insert(s.begin()+ B + 1, '"');
	s.insert(s.begin()+ C + 2, '"');
	s.insert(s.begin()+ D+ 3, '"');
	cout << s << endl;

	}