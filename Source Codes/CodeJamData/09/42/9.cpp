//	GCJ 2009 Round 2 (B)

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned uint;
typedef long long Int;
typedef vector<int> vint;
typedef pair<int,int> pint;
#define mp make_pair

template<class T> void pv(T a, T b) { for (T i = a; i != b; ++i) cout << *i << " "; cout << endl; }
int in_c() { int c; while ((c = getchar()) <= ' ') { if (!~c) throw ~0; } return c; }
int in() {
	int x = 0, c;
	while ((uint)((c = getchar()) - '0') >= 10) { if (c == '-') return -in(); if (!~c) throw ~0; }
	do { x = (x << 3) + (x << 1) + (c - '0'); } while ((uint)((c = getchar()) - '0') < 10);
	return x;
}

struct qint {
	int x, y, s, t;
	qint() {}
	qint(int x, int y, int s, int t) : x(x), y(y), s(s), t(t) {}
};

int M, N, F;
char A[60][60];
int B[60];

int d[15][15][70][70];
qint que[1000010], *qb, *qe;

void go0(int xx, int yy, int ss, int tt, int c) {
	if (!~d[xx][yy][ss][tt]) {
		d[xx][yy][ss][tt] = c;
		*--qb = qint(xx, yy, ss, tt);
	}
}
void go1(int xx, int yy, int ss, int tt, int c) {
	if (!~d[xx][yy][ss][tt]) {
		d[xx][yy][ss][tt] = c + 1;
		*qe++ = qint(xx, yy, ss, tt);
	}
}

int main() {
	int x, y, s, t;
	int dy;
	int xx, yy;
	int c;
	
	for (int TC = in(), tc = 0; TC--; ) {
		printf("Case #%d: ", ++tc);
		
		M = in() - 1;
		N = in();
		F = in();
		for (x = 0; x <= M; ++x) {
			scanf("%s", A[x]);
		}
		
		memset(B, 0, (M + 1) << 2);
		for (x = 0; x <= M; ++x) {
			for (y = 0; y < N; ++y) {
				if (A[x][y] == '#') B[x] |= 1 << y;
			}
		}
//pv(B,B+M+1);
		
		qb = qe = que + 500000;
		memset(d, ~0, sizeof(d));
		d[0][0][B[0]][B[1]] = 0;
		*qe++ = qint(0, 0, B[0], B[1]);
		
		for (; qb != qe; ) {
			x = qb->x;
			y = qb->y;
			s = qb->s;
			t = qb->t;
			++qb;
			
			c = d[x][y][s][t];
//cout<<x<<" "<<y<<" "<<s<<" "<<t<<"  "<<c<<endl;
			if (x == M) {
				printf("Yes %d\n", c);
				goto found;
			}
			
			for (dy = 1; dy >= -1; dy -= 2) {
				yy = y + dy;
				if (0 <= yy && yy < N && !(s & 1 << yy)) {
					//	move
					xx = x;
					if (!(t & 1 << yy)) {
						for (xx += 2; xx <= M && !(B[xx] & 1 << yy); ++xx);
						--xx;
						if (xx - x <= F) go0(xx, yy, (xx == x + 1) ? t : B[xx], B[xx + 1], c);
					} else {
						go0(xx, yy, s, t, c);
					}
					
					//	dig
					if (t & 1 << yy) {
						go1(x, y, s, t ^ 1 << yy, c);
					}
					
				}
			}
			
			
		}
		
		puts("No");
	found:;
		
	}
	
	
	return 0;
}

