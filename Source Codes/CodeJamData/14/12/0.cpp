#pragma warning(disable:4996)
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
vector<int>E[1010];
int n, Res, D[1010];
void DFS(int a, int par){
	int i, cnt = 0;
	D[a] = 1;
	for (i = 0; i < E[a].size(); i++){
		if (E[a][i] != par){
			DFS(E[a][i], a);
			cnt++;
		}
	}
	if (cnt <= 1)return;
	int M1 = 0, M2 = 0;
	for (i = 0; i < E[a].size(); i++){
		if (E[a][i] != par){
			if (M1 < D[E[a][i]]){
				M2 = M1; M1 = D[E[a][i]];
			}
			else if (M2 < D[E[a][i]]){
				M2 = D[E[a][i]];
			}
		}
	}
	D[a] = M1 + M2 + 1;
}
void Do(int a){
	int i;
	DFS(a, -1);
	if (Res > n - D[a]) Res = n - D[a];
}
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, TC, T, a, b;
	scanf("%d", &TC);
	for (T = 1; T <= TC; T++){
		printf("Case #%d: ", T);
		scanf("%d", &n);
		for (i = 1; i < n; i++){
			scanf("%d%d", &a, &b);
			E[a].push_back(b);
			E[b].push_back(a);
		}
		Res = n;
		for (i = 1; i <= n; i++){
			Do(i);
		}
		printf("%d\n", Res);
		for (i = 1; i <= n; i++)E[i].clear();
	}
}