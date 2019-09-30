#include<cstdio>
#include<cstring>
#include<algorithm>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

int d[400][400];
int main() {
	int n, m; scanf("%d%d", &n, &m);
	memset(d, 0x3f, sizeof(d));
	rep(i, n)d[i][i] = 0;
	rep(i, m) {
		int a, b, c; scanf("%d%d%d", &a, &b, &c); a--; b--;
		d[a][b] = d[b][a] = c;
	}
	rep(k, n)rep(i, n)rep(j, n)d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
	ll sum = 0;
	rep(i, n)for (int j = i; j < n; j++)sum += d[i][j];
	int k; scanf("%d", &k);
	rep(i, k) {
		int x, y, z; scanf("%d%d%d", &x, &y, &z); x--; y--;
		if (d[x][y] > z) {
			sum -= d[x][y]; d[x][y] = d[y][x] = z; sum += d[x][y];
			rep(j, n)for (int t = j; t < n; t++) {
				int a = min(d[j][x] + d[y][t], d[j][y] + d[x][t]) + z;
				if (d[j][t] > a) {
					sum -= d[j][t]; d[j][t] = d[t][j] = a; sum += d[j][t];
				}
			}
		}
		printf("%lld\n", sum);
	}
}