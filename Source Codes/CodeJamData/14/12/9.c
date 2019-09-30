#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int n;

int go2(int num[n], int adj[n][n], int curr, int prev){
	int i;
	int top=0;
	int second=0;
	for(i=0; i<num[curr]; i++){
		int j = adj[curr][i];
		if(j == prev) continue;
		int test = go2(adj,i,curr);
		if(test>top){
			second = top;
			top = test;
		} else if(test > second){
			second = test;
		}
	}
	if(second == 0) return 1;
	return top+second+1;
}

int go(void){
	scanf("%d",&n);
	int adj[n][n];
	int num[n];
	int i,j;
	for(i=0; i<n; i++){
		num[i]=0;
	}
	for(i=0; i<n; i++){
		for(j=0; j<n; j++){
			adj[i][j] = 0;
		}
	}
	for(i=0; i<n-1; i++){
		int x,y;
		scanf("%d %d",&x,&y);
		adj[x-1][num[x-1]++] = y-1;
		adj[y-1][num[y-1]++] = x-1;
	}
	int best = go2(adj, 0, -1);
	for(i = 1; i < n; i++){
		int test = go2(adj,i,-1);
		if(test > best) best=test;
	}
	return n-best;
}

int main(int argc, char** argv){
	int t;
	scanf("%d",&t);
	int i;
	for(i=1; i<=t; i++){
		int ans = go();
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}
