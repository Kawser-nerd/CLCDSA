#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef double du;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const int P = 1000000007;
const int MAXN = 1123;
const int MAXM = 112;

int C[MAXM][MAXM];
int f[MAXM][MAXM][MAXM];

int next[MAXN*MAXM][26];
int num[MAXN*MAXM], s[MAXN*MAXM];
bool local[MAXN*MAXM];
int cnt;

int dfs(int i){
	int g[MAXM];
	int tg[MAXN];
	memset(g, 0, sizeof g);
	int j, k1, k2;
	int ret = 1;

	if(local[i]){
		g[1] = 1;
	}
	else{
		g[0] = 1;
	}

	for(int x = 0; x < 26; x++)
		if(next[i][x] != -1){
			j = next[i][x];
			ret = (ll)ret*dfs(j)%P;

			memset(tg, 0, sizeof tg);
			for(k1 = 0; k1 <= s[i]; k1++)
				for(k2 = k1; k2 <= s[i]; k2++)
					tg[k2] = (tg[k2] + (ll)f[k1][s[j]][k2]*g[k1]) % P;

			for(k1 = 0; k1 <= s[i]; k1++)
				g[k1] = tg[k1];
		}

	ret = (ll)ret*g[s[i]]%P;
	return ret;
}

int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int i0 = 1;
	int T;
	scanf("%d", &T);
	for (i0 = 1; i0 <= T; i0++) {
		int n, m;
		int i, j, k;

		scanf("%d%d", &n, &m);

		for(i = 0; i <= m; i++){
			C[i][0] = 1;
			for(j = 1; j <= i; j++){
				C[i][j] = (C[i-1][j-1] + C[i-1][j]) % P;
			}
		}

		for(k = 0; k <= m; k++){
			for(i = 0; i <= k; i++)
				for(j = 0; j <= k; j++){
					if(i + j < k)
						f[i][j][k] = 0;
					else{
						f[i][j][k] = (ll)C[k][i] * C[i][i+j-k] % P;
					}
				}
		}

		cnt = 1;
		memset(next, -1, sizeof next);
		memset(num, 0, sizeof num);
		memset(local, 0, sizeof local);
		for(i = 0; i < n; i++){
			char s[MAXM];
			scanf("%s", s);
			j = 0;
			for(k = 0; s[k]; k++){
				int t = s[k]-'A';
				if(next[j][t] == -1){
					next[j][t] = cnt++;
				}
				num[j]++;
				j = next[j][t];
			}
			num[j]++;
			local[j] = true;
		}

		int ans = 0;
		for(i = 0; i < cnt; i++){
			s[i] = min(num[i], m);
			ans += s[i];
		}

		int way = dfs(0);

		printf("Case #%d: %d %d\n", i0, ans, way);
	}
	return 0;
}
