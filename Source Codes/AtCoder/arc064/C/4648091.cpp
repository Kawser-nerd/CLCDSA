#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<map>
#include<vector>
#include<functional>
#include <random>
using namespace std;

long long xt, yt, x[1002], y[1002], r[1002];
long long N;
double dist[1002][1002];


int main(void) {
	scanf("%lld %lld %lld %lld", &x[0], &y[0], &xt, &yt);
	r[0] = 0;
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		scanf("%lld %lld %lld", &x[i + 1], &y[i + 1], &r[i + 1]);
	}
	x[N + 1] = xt;
	y[N + 1] = yt;
	r[N + 1] = 0;

	for (int i = 0; i < N + 2; i++) {
		for (int j = 0; j < N + 2; j++) {
			long long xd = x[i] - x[j];
			long long yd = y[i] - y[j];
			dist[i][j] = sqrt(xd * xd + yd * yd) - r[i] - r[j];
			if (dist[i][j] < 0) { dist[i][j] = 0; }
		}
	}

	for (int k = 0; k < N + 2; k++) {
		for (int i = 0; i < N + 2; i++) {
			for (int j = 0; j < N + 2; j++) {
				if (dist[i][j] > dist[i][k] + dist[k][j]) {
					dist[i][j] = dist[i][k] + dist[k][j];
				}
			}

		}
	}
	printf("%.15f\n", dist[0][N + 1]);

}