#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define two(x) (1<<(x))
#define sq(a) (a)*(a)
#define all(c) (c).begin(),(c).end()
#define For(i,b,e) for(int i = b;i < e;i ++)
#define foreach(i,c) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
const double PI = acos(-1.0);

const int dir[4][2] = {{-1,0},{0,-1},{0,1},{1,0}};

int p[7][7];
int R, C, r, c;

void input() {
	memset(p, 0, sizeof(p));
	scanf("%d%d%d%d", &C, &R, &c, &r);
	for(int i = 1;i <= R;i ++) for(int j = 1;j <= C;j ++) scanf("%d", &p[i][j]);
}

int solve(int map[7][7]) {
	int nmap[7][7];
	if(map[r][c] == 0) return 0;
	int t = 0;
	for(t = 0;t < 4;t ++) if(map[r+dir[t][0]][c+dir[t][1]] != 0) break;
	if(t >= 4) return -1;

	for(int i = 0;i < 7;i ++) for(int j = 0;j < 7;j ++) nmap[i][j] = map[i][j];
	for(int i = 1;i <= R;i ++) for(int j = 1;j <= C;j ++) {
		if(i == r&&j == c||map[i][j] == 0) continue;
		int ma = -10, ni, nj;
		for(int k = 0;k < 4;k ++) if(map[i+dir[k][0]][j+dir[k][1]] > ma) {
			ma = map[i+dir[k][0]][j+dir[k][1]];
			ni = i+dir[k][0];
			nj = j+dir[k][1];
		}
		nmap[ni][nj] -= map[i][j];
		if(nmap[ni][nj] < 0) nmap[ni][nj] = 0;
	}
	int res = -1;
	for(int k = 0;k < 4;k ++) {
		int ni = r+dir[k][0], nj = c+dir[k][1];
		if(nmap[ni][nj] == 0) continue;
		int tmp = nmap[ni][nj];
		nmap[ni][nj] -= map[r][c];
		if(nmap[ni][nj] < 0) nmap[ni][nj] = 0;
		int change = 0;
		for(int i = 1;i <= R&&!change;i ++) for(int j = 1;j <= C;j ++) if(nmap[i][j] != map[i][j]) { change = 1; break; }
		if(!change) continue;
		int tres = solve(nmap);
		if(tres == -1) { res = -1; break; }
		if(tres > res) res = tres;
		nmap[ni][nj] = tmp;
	}
	if(res != -1) ++ res;
	/*printf("----------------------------------------\n");
	for(int i = 1;i <= R;i ++) {
		for(int j = 1;j <= C;j ++) printf("%d ", map[i][j]);
		printf("\n");
	}
	printf("result: %d\n", res);*/
	return res;
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int cas;
	scanf("%d", &cas);
	for(int ca = 1;ca <= cas;ca ++) {
		input();
		printf("Case #%d: ", ca);
		int res = solve(p);
		if(res == -1) printf("forever\n");
		else printf("%d day(s)\n", res-1);
	}
	return 0;
}
