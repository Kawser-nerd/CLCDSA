#include<stdio.h>
#include<assert.h>
#include<math.h>
#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<cmath>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;

const double EPS = 1e-8;
const double PI = acos(-1);

const int MX = 105;

int a, b, c, d;

int E[MX], S[MX];
ll G[MX][MX];
int N, Q;

int solve()
{
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%d%d", E+i, S+i);
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <= N; j++){
			scanf("%lld", G[i] + j);
		}
	}
	for(int i = 1; i <= N; i++) G[i][i] = 0;
	for(int k = 1; k <= N; k++){
		for(int i = 1; i <= N; i++){
			for(int j = 1; j <= N; j++){
				if( G[i][k] == -1 || G[k][j] == -1 ) continue;
				if( G[i][j] != -1 ) G[i][j] = min(G[i][k] + G[k][j], G[i][j]);
				else G[i][j] = G[i][k] + G[k][j];
			}
		}
	}
	int s, e;
	for(int i = 1; i <= Q; i++){
		scanf("%d%d", &s, &e);
		double dist[MX];
		int chk[MX] = {};
		for(int i = 1; i <= N; i++) dist[i] = 1e18;
		dist[s] = 0;

		for(int i = 1; i <= N; i++){
			int mn = -1;
			for(int i = 1; i <= N; i++) if( !chk[i] && (mn == -1 || dist[mn] > dist[i] )) mn = i;
			chk[mn] = 1;
			for(int i = 1; i <= N; i++){
				if( chk[i] ) continue;
				if( G[mn][i] == -1 || G[mn][i] > E[mn] ) continue;
				dist[i] = min(dist[i], dist[mn] + G[mn][i] / (double)S[mn]);
			}
		}
		printf("%.10lf ", dist[e]);
	}
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		printf("Case #%d: ", t);
		solve();
	}
}
