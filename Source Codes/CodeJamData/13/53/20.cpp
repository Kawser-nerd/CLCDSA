#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
using namespace std;

#define PB push_back
#define MP make_pair

#define FOR(it,a) for (__typeof((a).begin()) it=(a).begin();it!=(a).end();++it)
#define sqr(x) ((x)*(x))
#define lowbit(x) ((x)&(-(x)))

const double PI = acos(-1.0);
const double EPS = 1e-8;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<string> VS;

inline double mySqrt(double x)
{
	if (x < EPS) {
		return 0;
	}
	return sqrt(x);
}

inline int signum(double x)
{
	if (x < -EPS) {
		return -1;
	}
	return x > EPS;
}

struct Point
{
	double x, y;
	Point(){}
	Point(double x, double y): x(x), y(y){}
	double norm(){
		return sqrt(x * x + y * y);
	}
	void rotate(double ang) {
		double co = cos(ang), si = sin(ang);
		double tx = x, ty = y;
		x = tx * co - ty * si;
		y = tx * si + ty * co;
	}
};

inline Point operator + (const Point &a,const Point &b) {return Point(a.x + b.x, a.y + b.y);}
inline Point operator - (const Point &a,const Point &b) {return Point(a.x - b.x, a.y - b.y);}
inline Point operator * (const Point &a,const double &b) {return Point(a.x * b, a.y * b);}
inline Point operator / (const Point &a,const double &b) {return Point(a.x / b, a.y / b);}
inline double det(const Point &a, const Point &b) {return a.x * b.y - a.y * b.x;}
inline double dot(const Point &a, const Point &b) {return a.x * b.x + a.y * b.y;}
//================================

const int maxn = 1005;
const int maxm = 2005;
const int inf = 1000000000;

struct ShortestPath
{
	int dist[maxn], n;
	bool vis[maxn];
	vector<PII> adj[maxn];
	
	void add(int a, int b, int c) {
//printf("add %d %d %d\n", a, b, c);
		adj[a].PB(MP(b, c));
//printf("	%d %d\n", a, adj[a].size());
	}
	
	void init(int nn) {
		n = nn;
		for (int i = 0; i < n; ++ i) {
			dist[i] = inf;
			adj[i].clear();
			vis[i] = false;
		}
	}
	
	inline void solve(int st) {
		queue<int> q;
		q.push(st);
		dist[st] = 0;
		while (q.size()) {
			int u = q.front();
			q.pop();
			vis[u] = false;
//printf("%d %d\n", u, adj[u].size());
			FOR (e, adj[u]) {
				int v = e->first;
				int c = e->second;
				if (dist[u] + c < dist[v]) {
					dist[v] = dist[u] + c;
					if (!vis[v]) {
						vis[v] = true;
						q.push(v);
					}
				}
			}
		}
	}
}target, source;

int n, m, p;
int suggest[maxn];

struct Edge
{
	int a, b, lower, upper;
	void read() {
		scanf("%d%d%d%d", &a, &b, &lower, &upper);
		-- a;
		-- b;
	}
}edge[maxm];

bool isSuggested[maxm], forbid[maxm];

int main()
{
	int T, test = 1;
	for (scanf("%d", &T); test <= T; ++ test) {
		scanf("%d%d%d", &n, &m, &p);
		for (int i = 0; i < m; ++ i) {
			edge[i].read();
		}
		memset(isSuggested, false, sizeof(isSuggested));
		for (int i = 0; i < p; ++ i) {
			scanf("%d", &suggest[i]);
			-- suggest[i];
			isSuggested[suggest[i]] = true;
		}
		memset(forbid, true, sizeof(forbid));
		for (int mask = 0; mask < 1 << m; ++ mask) {
			source.init(n);
			target.init(n);
			for (int i = 0; i < m; ++ i) {
				if (mask >> i & 1) {
					source.add(edge[i].a, edge[i].b, edge[i].lower);
					target.add(edge[i].b, edge[i].a, edge[i].lower);
				} else {
					source.add(edge[i].a, edge[i].b, edge[i].upper);
					target.add(edge[i].b, edge[i].a, edge[i].upper);
				}
			}
			source.solve(0);
			target.solve(1);
			int src = 0, current = 0;
			for (int i = 0; i < p; ++ i) {
				int nxt = edge[suggest[i]].a + edge[suggest[i]].b - src;
				int cost = edge[suggest[i]].lower;
				if (source.dist[src] + cost + target.dist[nxt] == target.dist[0]) {
					forbid[i] = false;
				}
				src = nxt;
			}
		}
		int ans = -1;
		for (int i = 0; i < p; ++ i) {
			if (forbid[i]) {
				ans = suggest[i] + 1;
				break;
			}
		}
		printf("Case #%d: ", test);
		if (ans == -1) {
			puts("Looks Good To Me");
		} else {
			printf("%d\n", ans);
		}
	}
	return 0;
}

