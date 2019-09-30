#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <bitset>
#include <numeric>
#include <ctime>
#include <cmath>
#include <cassert>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;
typedef long long ll;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pct __builtin_popcount

#define N 110
int H[N],G[N];
int n, P, Q; 

int f[N][N*10];
void upd(int &S, int T) {S = max(S, T);}

int main()
{
	int _; cin >> _;
	for (int __ = 1; __ <= _; __ ++) {
		cin >> P >> Q >> n;
		for (int i = 0; i < n; i ++) 
			cin >> H[i] >> G[i];
		memset(f,-1,sizeof f);
		f[0][1] = 0;
		for (int i = 0; i < n; i ++) 
			for (int j = 0; j <= n*10; j ++) if (f[i][j] != -1) 
				for (int k = 0; k <= 10; k ++) {
					if (H[i]-k*Q <= 0) {
						upd(f[i+1][j+k],f[i][j]);
						break;
					}
					int c = (H[i]-k*Q-1)/P+1;
					if (j+k >= c) upd(f[i+1][j+k-c],f[i][j]+G[i]);
				}
		int S = 0;
		for (int j = 0; j <= n*10; j ++) 
			S = max(S, f[n][j]);
		printf ("Case #%d: %d\n",__,S);
	}
	return 0;
}