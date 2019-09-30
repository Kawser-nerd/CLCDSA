#include <stdio.h>
#include <stdlib.h>

typedef enum {
  false,
  true
}boolean;

typedef struct {
	int a;
	int b;
	int c;
}edge;

typedef struct vsub{
	int v;
	int num;
	struct vsub **nexts;
	int *c;
}vertex;

boolean search(boolean *grave, vertex *ver, int sum, int dest, int border){
	if(sum >= border){
		return false;
	}
	if(sum < border && ver->v == dest){
		return true;
	}
	int i;
	for(i = 0; i < ver->num ;i++){
		if(grave[(ver->nexts)[i]->v] == false){
			grave[(ver->nexts)[i]->v] = true;
			if(search(grave , (ver->nexts)[i], sum + (ver->c)[i], dest, border) == true){
				grave[(ver->nexts)[i]->v] = false;
				return true;
			}
			grave[(ver->nexts)[i]->v] = false;
		}
	}
	return false;
}

int main(){
	int N, M, i, a, b, c, ans = 0;
	scanf("%d%d", &N, &M);
	edge E[M];
	vertex *V[N];
	for(i = 0; i < N; i++){
		V[i] = (vertex *)malloc(sizeof(vertex));
		V[i]->v = i;
		V[i]->num = 0;
		V[i]->nexts = (vertex **)malloc(sizeof(vertex *) * N);
		V[i]->c = (int *)malloc(sizeof(int) * N);
	}
	for(i = 0; i < M; i++){
		scanf("%d%d%d", &a, &b, &c);
		a--;
		b--;
		E[i].a = a;
		E[i].b = b;
		E[i].c = c;
		(V[a]->nexts)[V[a]->num] = V[b];
		(V[a]->c)[V[a]->num] = c;
		(V[a]->num)++;
		(V[b]->nexts)[V[b]->num] = V[a];
		(V[b]->c)[V[b]->num] = c;
		(V[b]->num)++;
	}
	boolean *grave;
	grave = (boolean *)malloc(sizeof(boolean) * N);
	for(i = 0; i < N; i++){
		grave[i] = false;
	}
	for(i = 0; i < M; i++){
		grave[E[i].a] = true;
		if(search(grave, V[E[i].a], 0, E[i].b, E[i].c) == true){
			ans++;
		}
		grave[E[i].a] = false;
	}
	printf("%d\n", ans);
	free(grave);
	for(i = 0; i < N; i++){
		free(V[i]->nexts);
		free(V[i]->c);
		free(V[i]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &M);
  ^
./Main.c:56:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &a, &b, &c);
   ^