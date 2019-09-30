#define _CRT_SECURE_NO_WARNINGS
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <ctime>
using namespace std;

typedef long long int64;
typedef vector<string> vs;
typedef vector<double> vd;
typedef pair<int,int> pii;
typedef vector<pii> vpii;

#define For(i,a,b) for (int i(a),_b(b); i <= _b; ++i)
#define Ford(i,a,b) for (int i(a),_b(b); i >= _b; --i)
#define Rep(i,n) for (int i(0),_n(n); i < _n; ++i)
#define Repd(i,n) for (int i((n)-1); i >= 0; --i)
#define Fill(a,c) memset(&a, c, sizeof(a))
#define MP(x, y) make_pair((x), (y))
#define All(v) (v).begin(), (v).end()

template<typename T, typename S> T cast(S s) {
	stringstream ss;
	ss << s;
	T res;
	ss >> res;
	return res;
}

template<typename T> inline T sqr(T a) { return a*a; }
template<typename T> inline int Size(const T& c) { return (int)c.size(); }
template<typename T> inline void checkMin(T& a, T b) { if (b < a) a = b; }
template<typename T> inline void checkMax(T& a, T b) { if (b > a) a = b; }

bool seekEoln() {
	int ch;
	for (;;) {
		ch = getc(stdin);
		if (ch != ' ')
			break;
	}
	ungetc(ch, stdin);
	return ch == '\r' || ch == '\n' || ch == -1;
}

#ifndef _DEBUG
#define assert(f) if (!(f)) printf("\n%s\n", "ASSERTION FAILED!");
#endif

char buf[1024*1024];

int rd() {
	int x;
	bool f = scanf("%d", &x) == 1;
	assert(f);
	return x;
}

double rlf() {
	double x;
	bool f = scanf("%lf", &x) == 1;
	assert(f);
	return x;
}

string rs() {
	bool f = scanf("%s", buf) == 1;
	assert(f);
	return buf;
}

#define j1 J1

const int di[] = {0, -1, 0, 1}, dj[] = {1, 0, -1, 0};
int m, n, i1, j1, i2, j2;
char a[15][15];
int pi[4][15][15], pj[4][15][15];
int dist[15][15][15][15][5];

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	int numTests(rd());
	For(test, 1, numTests) {
		printf("Case #%d:", test);
		scanf("%d%d", &m, &n);
		Rep(i, m) {
			scanf("%s", a[i]);
			assert(strlen(a[i]) == n);
			Rep(j, n) {
				if (a[i][j] == 'O') {
					i1 = i;
					j1 = j;
					a[i][j] = '.';
				} else if (a[i][j] == 'X') {
					i2 = i;
					j2 = j;
					a[i][j] = '.';
				}
			}			
		}
		Rep(i, m) Rep(j, n) {
			Rep(d, 4) {
				if (a[i][j] == '#') {
					pi[d][i][j] = pj[d][i][j] = -1;
				} else {
					int ci = i, cj = j;
					while (ci+di[d] >= 0 && ci+di[d] < m && cj+dj[d] >= 0 && cj+dj[d] < n && a[ci+di[d]][cj+dj[d]] == '.') {
						ci += di[d];
						cj += dj[d];
					}
					pi[d][i][j] = ci;
					pj[d][i][j] = cj;
				}
			}
		}
		Fill(dist, -1);
		dist[i1][j1][0][0][4] = 0;
		queue<int> que;
		que.push(i1); que.push(j1); que.push(0); que.push(0); que.push(4);
		int res = INT_MAX;
		while (!que.empty()) {
			int ci = que.front(); que.pop();
			int cj = que.front(); que.pop();
			int ti = que.front(); que.pop();
			int tj = que.front(); que.pop();
			int td = que.front(); que.pop();
			if (ci == i2 && cj == j2)
				checkMin(res, dist[ci][cj][ti][tj][td]);
			For(d1, 0, 4) For(d2, 0, 4) {
				vector<int> vi, vj, vd;
				if (td != 4) {
					vi.push_back(ti);
					vj.push_back(tj);
					vd.push_back(td);
				}
				if (d1 != 4) {
					vi.push_back(pi[d1][ci][cj]);
					vj.push_back(pj[d1][ci][cj]);
					vd.push_back(d1);
				} 
				if (d2 != 4) {
					vi.push_back(pi[d2][ci][cj]);
					vj.push_back(pj[d2][ci][cj]);
					vd.push_back(d2);
				}
				int k = Size(vi);
				while (k > 1 && vi[k-1] == vi[k-2] && vj[k-1] == vj[k-2] && vd[k-1] == vd[k-2]) {
					vi.pop_back();
					vj.pop_back();
					vd.pop_back();
					--k;
				}
				Rep(dir, 4) For(z, max(0, k-2), k) {
					int ni = ci+di[dir], nj = cj+dj[dir];
					if (0 <= ni && ni < m && 0 <= nj && nj < n && a[ni][nj] == '.') {
						int& tmp = dist[ni][nj][z==k?0:vi[z]][z==k?0:vj[z]][z==k?4:vd[z]];
						if (tmp == -1) {
							tmp = dist[ci][cj][ti][tj][td]+1;
							que.push(ni); que.push(nj); que.push(z==k?0:vi[z]); que.push(z==k?0:vj[z]);
							que.push(z==k?4:vd[z]);
						}
					} else if (k >= 2 && ci == vi[k-1] && cj == vj[k-1] && dir == vd[k-1]) {
						int ni = vi[k-2], nj = vj[k-2];
						int& tmp = dist[ni][nj][z==k?0:vi[z]][z==k?0:vj[z]][z==k?4:vd[z]];
						if (tmp == -1) {
							tmp = dist[ci][cj][ti][tj][td]+1;
							que.push(ni); que.push(nj); que.push(z==k?0:vi[z]); que.push(z==k?0:vj[z]);
							que.push(z==k?4:vd[z]);
						}
					} else if (k >= 2 && ci == vi[k-2] && cj == vj[k-2] && dir == vd[k-2]) {
						int ni = vi[k-1], nj = vj[k-1];
						int& tmp = dist[ni][nj][z==k?0:vi[z]][z==k?0:vj[z]][z==k?4:vd[z]];
						if (tmp == -1) {
							tmp = dist[ci][cj][ti][tj][td]+1;
							que.push(ni); que.push(nj); que.push(z==k?0:vi[z]); que.push(z==k?0:vj[z]);
							que.push(z==k?4:vd[z]);
						}
					}				
				}
			}
		}
		if (res == INT_MAX)
			printf(" THE CAKE IS A LIE\n");
		else
			printf(" %d\n", res);
	}

	exit(0);
}
