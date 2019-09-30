#include <stdlib.h>
#include <stdio.h>

#define F0(i,n) for(int i=0;i<n;i++)

typedef unsigned long long llu;

typedef struct pllu{
	llu n;
	llu k;
} pllu;

int find(pllu* L, llu key,int start,int size){
	//printf("Key: %llu,start: %d, size: %d\n",key,start,size);
	for(int i=(size-1);i>=start;i++){
		if(L[i].n > key)break;
		if(L[i].n == key)return i;
	}
	return -1;
}

void put(pllu** L,llu key, llu value,int start, int* size,int* mem_size){
	int index = find(*L,key,start,*size);
	if(index != -1){(*L)[index].k += value;}
	else if((*size) < (*mem_size)){
		(*L)[*size].n = key;
		(*L)[*size].k = value;	
		(*size)++;
	}else{ // (*size) == (*mem_size)
		(*L) = realloc(*L,((*size) + 100)*sizeof(pllu));
	//	printf("Allocation event old_size: %d\n",(*size));
		(*L)[*size].n = key;
        (*L)[*size].k = value;
		(*mem_size) = (*size) + 100;
		(*size)++;
	}
}

llu min(llu N){
	if(N%2 == 1)return (N-1)/2;
	return N/2 -1;
}

llu max(llu N){
	if(N%2 == 1)return (N-1)/2;
	return N/2;
}

int main(){
	int T;
	llu N,K;
	pllu *L = NULL;
	int L_size = 0;
	int L_start = 0;
	int mem_size = 0;
	scanf("%d\n",&T);
	F0(i,T){
		printf("Case #%d: ",i+1);
		scanf("%llu %llu\n",&N,&K);
		L_start = 0;
		L_size = 0;
		put(&L,N,1,L_start,&L_size,&mem_size);
		while(1){
			if(L[L_start].n <= 0){
				fprintf(stderr,"The maximum segment size is 0, K: %llu, k: %llu\n",K,L[L_start].k);
			//	fprintf(stderr,"K: %llu, L_start: %d, L_size: %d, mem: %d\n",K,L_start,L_size,mem_size);
			//	for(int j=L_start;j<L_size;j++){
			//		fprintf(stderr,"n: %llu, k: %llu\n",L[j].n,L[j].k);
			//	}
				return 1;
			}
			llu M = max(L[L_start].n);
			llu m = min(L[L_start].n);
			if(L[L_start].k >= K){
				printf("%llu %llu\n",M,m);
				break;
			}else{
				K -= L[L_start].k;
				put(&L,M,L[L_start].k,L_start,&L_size,&mem_size);
				put(&L,m,L[L_start].k,L_start,&L_size,&mem_size);
				L_start++;
			}
		}	
	}
}

