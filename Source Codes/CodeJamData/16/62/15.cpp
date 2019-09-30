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
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef double R;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define FOR(i, s, t) for(i = (s); i < (t); i++)
#define RFOR(i, s, t) for(i = (s)-1; i >= (t); i--)

const R PI = acos(-1);
const int MAXN = 11234;
const int P = 1e9+7;

int f[MAXN][MAXN];
int sum[MAXN][MAXN];
int inv[MAXN];

int main(){
#ifdef LOCAL
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#endif
	int T, i0;
	scanf("%d", &T);

	int n, k;
	int i, j;

	n = 1e4;

	inv[1] = 1;
	for(i = 2; i <= n; i++)
		inv[i] = (ll)(P-inv[P%i]) * (P/i) % P;

	f[1][1] = 0;
	sum[1][1] = 0;
	for(i = 2; i <= n; i++){
		for(j = 1; j <= i; j++){
			if(j == 1 || j == i){
				f[i][j] = (ll)(sum[i-2][1] + 1) * inv[i-1] % P;
			}
			else{
				f[i][j] = ((ll)sum[i-2][j] + sum[i-2][i-2+1-(j-2)] + 2) * inv[i-1] % P;
			}
			sum[i][j] = (sum[i-1][j] + f[i][j]) % P;
		}
	}
	for(i0 = 1; i0 <= T; i0++){

		scanf("%d%d", &n, &k);

		printf("Case #%d: %d\n", i0, f[n][k]);
	}
	return 0;
}
