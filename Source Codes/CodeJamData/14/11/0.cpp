#pragma warning(disable:4996)
#include<stdio.h>
#include<string.h>
#include<algorithm>
#define INF 999999999
using namespace std;
char p[201][50];
bool o[201];
struct A{
	char p[50];
	bool operator <(const A &q)const{
		return strcmp(p, q.p) < 0;
	}
}q[201],r[201];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, TC, T, j, n, m, k, l, R, S;
	scanf("%d", &TC);
	for (T = 1; T <= TC; T++){
		printf("Case #%d: ", T);
		scanf("%d%d", &n, &m);
		for (j = 0; j < n; j++){
			scanf("%s", p[j]);
		}
		for (j = 0; j < n; j++){
			scanf("%s", q[j].p);
		}
		sort(q, q + n);
		R = INF;
		for (j = 0; j < n; j++){
			S = 0;
			for (k = 0; k < m; k++){
				if (p[0][k] != q[j].p[k])o[k] = 1, S++;
				else o[k] = 0;
			}
			if (S >= R)continue;
			for (k = 0; k < n; k++){
				for (l = 0; l < m; l++){
					r[k].p[l] = p[k][l];
					if (o[l])r[k].p[l] = '0' + '1' - r[k].p[l];
				}
				r[k].p[m] = 0;
			}
			sort(r, r + n);
			for (k = 0; k < n; k++){
				if (strcmp(r[k].p, q[k].p) != 0)break;
			}
			if (k == n)R = S;
		}
		if (R != INF)printf("%d\n", R);
		else printf("NOT POSSIBLE\n");
	}
}