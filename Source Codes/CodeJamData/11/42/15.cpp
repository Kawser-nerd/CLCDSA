#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
using namespace std;

#define FOREACH(it,vec) for(typeof((vec).begin()) it = (vec).begin(); it != (vec).end(); it++)

int T;
char zeile[1000];
int feld[500][500];
int sum[505][505];
int ssum[505][505];
int sssum[505][505];

int main() {
	scanf("%d", &T);
	for (int test = 0; test < T; test++) {
		fprintf(stderr, "Test %d/%d\n", test+1, T);
		printf("Case #%d: ", test+1);
		int Y, X, D;
		scanf("%d %d %d ", &Y, &X, &D);
		for (int y = 0; y < Y; y++) {
			scanf("%s ", zeile);
			sum[0][y] = 0;
			ssum[0][y] = 0;
			sssum[0][y] = 0;
			for (int x = 0; x < X; x++) {
				feld[x][y] = zeile[x]-'0';
				sum[x+1][y] = sum[x][y]+feld[x][y];
				ssum[x+1][y] = ssum[x][y]+x*feld[x][y];
				sssum[x+1][y] = sssum[x][y]+y*feld[x][y];
			}
		}
		int maxK = 0;
		for (int x1 = 0; x1 < X; x1++) {
			for (int x2 = x1+2; x2 < X; x2++) {
				int K = x2-x1+1;
				int aktx = 0;
				int akty = 0;
				int aktw = 0;
				for (int y = 0; y < K; y++) {
					aktx += ssum[x2+1][y]-ssum[x1][y];
					akty += sssum[x2+1][y]-sssum[x1][y];
					aktw += sum[x2+1][y]-sum[x1][y];
				}
				for (int y1 = 0; y1+K-1 < Y; y1++) {
					int y2 = y1+K-1;
					int raktx = aktx-x1*(feld[x1][y1]+feld[x1][y2])-x2*(feld[x2][y1]+feld[x2][y2]);
					int rakty = akty-y1*(feld[x1][y1]+feld[x2][y1])-y2*(feld[x1][y2]+feld[x2][y2]);
					int raktw = aktw-feld[x1][y1]-feld[x1][y2]-feld[x2][y1]-feld[x2][y2];
					if (2*raktx == (x1+x2)*raktw && 2*rakty == (y1+y2)*raktw)
						maxK = max(maxK, K);
					aktx += ssum[x2+1][y2+1]-ssum[x1][y2+1] - ssum[x2+1][y1]+ssum[x1][y1];
					akty += sssum[x2+1][y2+1]-sssum[x1][y2+1] - sssum[x2+1][y1]+sssum[x1][y1];
					aktw += sum[x2+1][y2+1]-sum[x1][y2+1] - sum[x2+1][y1]+sum[x1][y1];
				}
			}
		}
		if (maxK == 0)
			printf("IMPOSSIBLE\n");
		else
			printf("%d\n", maxK);
	}
	return 0;
}
