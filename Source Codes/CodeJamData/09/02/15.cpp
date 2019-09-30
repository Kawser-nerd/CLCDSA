#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <cstring>
using namespace std;

#define rep(i,b) for(int i=(0);i<(b);++i)
#define fo(i,a,b) for(int i=(a);i<=(b);++i)
#define ford(i,a,b) for(int i=(a);i>=(b);--i)
#define fore(a,b) for(__typeof((b).begin()) a = (b).begin();a!=(b).end();++a)
#define vv vector
#define pb push_back
#define ll long long
#define ld long double
#define ss(a) (int)(a).size()
#define all(x) (x).begin(),(x).end()
#define clr(x,a) memset(x,a,sizeof(x))
#define vi vv<int>
#define vs vv<string>

int cond = (ll)1;
#define db(x) { if (cond > 0) { cond--; rep (xxx, 1) cerr << __LINE__ << " " << #x << " " << x << endl; cerr.flush(); } }


#define pii pair<int,int>
#define r first
#define c second
const int len_sz = 111;
int wys[len_sz][len_sz];
pii res[len_sz][len_sz];

int dr[] = { -1, 0, 0, 1};
int dc[] = { 0, -1, 1, 0};
pii next(pii pos) {
	pii next(-1, -1);
	int cand = wys[pos.r][pos.c];

	rep (d, 4) {
		pii tmp(pos.r + dr[d], pos.c + dc[d]);
		if (wys[tmp.r][tmp.c] < cand) {
			next = tmp;
			cand = wys[tmp.r][tmp.c];
		}
	}

	return next;
}

void solve (int test) {
	int H, W;
	scanf("%d%d", &H, &W);
	clr(wys, 0x3f);
	fo (i, 1, H) fo (j, 1, W) {
		scanf("%d", &wys[i][j]);
	}
	clr(res, 0x80);
	fo (i, 1, H) fo (j, 1, W) {
		pii cur(i, j);
		if (res[i][j].r < -1) {
			while (true) {
				if (res[cur.r][cur.c].r > -1) {
					cur = res[cur.r][cur.c];
					break;
				}
				pii ne = next(cur);
				if (ne.r == -1) {
					break;
				}
				cur = ne;
			}
			pii p(i,j);
			while (res[p.r][p.c].r <= -1) {
				res[p.r][p.c] = cur;
				pii ne = next(cur);
				cur = ne;
			}
		}
	}
	printf("Case #%d:\n", test);
	map<pii, int> pii2i;
	fo (i, 1, H) {
		fo (j, 1, W) {
			if (pii2i.count(res[i][j]) == 0) {
				int nlen = pii2i.size();
				pii2i[res[i][j]] = nlen;
			}
			if (j > 1) printf(" ");
			printf("%c", pii2i[res[i][j]] + 'a');
		}
		printf("\n");
	}



}

int main(int argc, char ** argv) {
	ios::sync_with_stdio(false);
	cond = argc >= 2 && argv[1][0] == 'q' ? 1 << 30 : 0;
	int t;
	scanf("%d", &t);
	rep (i, t)
		solve(i + 1);
	return 0;
}

