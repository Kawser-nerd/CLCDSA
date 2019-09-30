#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FORIN(i,n) for(i=0;i<(n);i++)
#define FORN(n) FORIN(i,n)
#define SWAP(a,b) tmp=(a); (a)=(b); (b)=tmp
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))


int reduce(int N, int *p){
	int i=0, sum=0;
	int max_i[2] = {0, 0};

	FORN(N){
		sum += p[i];
		if(p[i]>p[max_i[0]]){
			max_i[0] = i;
		}
	}
	if (max_i[0]==0) max_i[1]=1;
	FORN(N){
		if(i==max_i[0]) continue;
		else if(p[i]>p[max_i[1]]){
			max_i[1] = i;
		}
	}
	
	if (p[max_i[0]] == p[max_i[1]]) {
		if (sum==3) {
			p[max_i[0]] -= 1;
//printf("[DEBUG]  p[%d] : %d -> %d\n", max_i[0], p[max_i[0]]+1, p[max_i[0]]); fflush(stdout);
			sum -= 1;
			printf(" %c", max_i[0]+'A');
		} else {
			p[max_i[0]] -= 1;
			p[max_i[1]] -= 1;
//printf("[DEBUG]  p[%d] : %d -> %d", max_i[0], p[max_i[0]]+1, p[max_i[0]]); fflush(stdout);
//printf("  &&  p[%d] : %d -> %d\n", max_i[1], p[max_i[1]]+1, p[max_i[1]]); fflush(stdout);
			sum -= 2;
			printf(" %c%c", max_i[0]+'A', max_i[1]+'A');
		}
	} else {
		p[max_i[0]] -= 2;
		sum -= 2;
//printf("[DEBUG]  p[%d] : %d -> %d\n", max_i[0], p[max_i[0]]+2, p[max_i[0]]); fflush(stdout);
		printf(" %c%c", max_i[0]+'A', max_i[0]+'A');
	}
	return sum;
}

int main(){
	int i,j,T,cases, N;
	int p[30];

	scanf("%d",&T);

	FORIN(cases, T){
		scanf("%d",&N);
		printf("Case #%d:", cases+1);
		FORN(N){
			p[i]=0;
			scanf("%d", &p[i]);
		}
		while(reduce(N, p));

		printf("\n");
	}

	return 0;
}
