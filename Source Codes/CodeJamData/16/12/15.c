#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define FORN(n) for(i=0;i<n;i++)
#define FORIN(i,n) for(i=0;i<n;i++)

int intcmp(const void *a, const void *b){
	return *((int *)a)-*((int*)b);
}

int main(){
	int cases, T, N, i;
	int input[6000];

	scanf("%d", &T);
	FORIN(cases,T){
		scanf("%d",&N);
		int len = 2*N*N-N;
		FORN(len){
			scanf("%d", &input[i]);
		}
		printf("Case #%d:", cases+1);
		qsort(input, len, sizeof(int), intcmp);
		int cnt=0;
		FORN(len){
			if(i==0 || input[i]==input[i-1]){
				cnt++;
			}else{
				if(cnt&1){
					printf(" %d",input[i-1]);
				}
				cnt=1;
			}
		}
		if(cnt&1){
			printf(" %d",input[i-1]);
		}
		printf("\n");
	}
	return 0;
}

