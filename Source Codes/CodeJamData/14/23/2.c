#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int queue[10];
int stack[10][10];
int flag[10];
int G[10][10];
int n;
int done;
int p;
struct post{
	int number;
	int original;
}N[10];
void search(int depth, int next, int top){
	int i;
	if(top == 0){
		flag[next]=1;
		stack[0][0]=next;
		queue[0]=next;
		for(i=0;i<n;i++)
			if(!flag[i] && !done)
				search(1, i, 1);
	}else{
		//Check if possible
		int j;
		for(j=top-1;j>=0;j--)
			if(G[stack[depth-1][j]][next])
				break;
		if(j<0)
			return;
		flag[next]=1;
		int new_top = j+2;
		memcpy(stack[depth], stack[depth-1], sizeof(int)*(j+1));
		stack[depth][j+1]=next;
		queue[depth]=next;
		if(depth >= n-1){
			done=1;
			printf("Case #%d: ", p);
			for(i=0;i<n;i++)
				printf("%d", N[queue[i]].number);
			printf("\n");
			flag[next]=0;
			return;
		}
		for(j=0;j<n;j++)
			if(!flag[j] && !done)
				search(depth+1, j, new_top);
	}
	flag[next]=0;
}
int cmp(const void *a, const void *b){
	const struct post *_a = a;
	const struct post *_b = b;
	return _a->number-_b->number;
}
int map[10];
int main(){
	int cases;
	scanf("%d", &cases);
	for(p=1;p<=cases;p++){
		int m;
		scanf("%d%d", &n, &m);
		int i;
		memset(G,0,sizeof(G));
		for(i=0;i<n;i++){
			scanf("%d", &N[i].number);
			N[i].original=i+1;
		}
		if(n==1){
			printf("Case #%d: %d\n", p, N[0].number);
			continue;
		}
		qsort(N, n, sizeof(struct post), cmp);
		for(i=0;i<n;i++)
			map[N[i].original]=i;
		for(i=0;i<m;i++){
			int x,y;
			scanf("%d%d", &x, &y);
			G[map[x]][map[y]]=1;
			G[map[y]][map[x]]=1;
		}
		for(i=0;i<n;i++)
			if(!done)
				search(0, i, 0);
		done=0;
	}
	return 0;
}


