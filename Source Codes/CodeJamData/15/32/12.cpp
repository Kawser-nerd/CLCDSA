#include <map>
#include <cmath>
#include <ctime>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int Test, K, N, M, Next[200], P[200][200];
double F[200][200][200];
char Keys[200], S[200];

bool Check()
{
	for (int i = 1; i <= N; i ++) {
		bool flag = false;
		for (int j = 0; j < K; j ++)
		if (S[i] == Keys[j]) {
			flag = true;
			break;
		}
		if (flag == false) return false;
	}
	return true;
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &Test);
	for (int Case = 1; Case <= Test; Case ++) {
		scanf("%d%d%d", &K, &N, &M);
		memset(Keys, 0, sizeof(Keys));
		scanf("%s", Keys);
		memset(S, 0, sizeof(S));
		scanf("%s", S + 1);
		printf("Case #%d: ", Case);
		if (!Check()) {
			printf("0.0\n");
			continue;
		}
		memset(Next, 0, sizeof(Next));
		Next[1] = 0;
		for (int i = 2, j = 0; i <= N; i ++) {
			for (; S[i] != S[j + 1] && j > 0; j = Next[j]);
			if (S[i] == S[j + 1]) j ++;
			Next[i] = j;
		}
		memset(P, 0, sizeof(P));
		for (int i = 0; i <= N; i ++) {
			for (int j = 0; j < K; j ++) {
				int k = i;
				for (; S[k + 1] != Keys[j] && k > 0; k = Next[k]);
				if (S[k + 1] == Keys[j]) k ++;
				P[i][j] = k;
			}
		}
		memset(F, 0, sizeof(F));
		F[0][0][0] = 1.0;
		int MAXL = 0;
		int L = Next[N];
		while (L + (N - Next[N]) <= M) {
			L += N - Next[N];
			MAXL ++;
		}
		for (int i = 0; i < M; i ++) {
			for (int j = 0; j <= N; j ++) {
				for (int k = 0; k <= MAXL; k ++)
				if (F[i][j][k] > 0) {
					for (int t = 0; t < K; t ++) {
						int x = P[j][t];
						if (x == N) {
							F[i + 1][x][k + 1] += F[i][j][k] / K;
						} else {
							F[i + 1][x][k] += F[i][j][k] / K;
						}
					}
				}
			}
		}
		double Ret = MAXL;
		for (int i = 0; i <= N; i ++) {
			for (int j = 0; j <= M; j ++) {
				Ret -= j * F[M][i][j];
			}
		}
		printf("%.12lf\n", Ret);
	}
    return 0;
}

