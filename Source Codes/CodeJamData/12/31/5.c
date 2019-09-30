#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int graph[1024][1024] = {{0}};
int label[1024] = {0};

int dfs(int start, int N){
	for (int i = 1; i<=N; i++){
		if (graph[start][i] != 0){
			if (label[i] == 0){
				label[i] = 1;
				int x = dfs(i, N);
				if (x == 1)
					return 1;
			}else{
				return 1;
			}
		}
	}
	return 0;
}

int main(){
	int T = 0, N = 0;
	scanf("%d", &T);

	for (int cas = 1; cas <= T; cas++){
		memset(graph, 0, sizeof(graph));
		memset(label, 0, sizeof(label));
		
		scanf("%d", &N);
		for (int i = 1; i<=N; i++){
			int x = 0, k = 0;
			scanf("%d", &x);
			for (int j = 0; j<x; j++){
				scanf("%d", &k);
				graph[i][k] = 1;
			}
		}

		int res = 0;
		for (int i = 1; i<=N; i++){
			if (label[i] == 0){
				label[i] = 1;
				memset(label, 0, sizeof(label));
				int x = dfs(i, N);
				if (x == 1){
					res = 1;
					break;
				}
			}
		}

		printf("Case #%d: ", cas);
		if (res){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
		
	}
		
	return 0;
}
