#include "stdio.h"

int discs[10001];

inline void sort(int N){
	int i, j, t;
	for(i=1; i<N; i++) for(j=i; j--;){
		if(discs[j] < discs[j+1]){
			t = discs[j];
			discs[j] = discs[j+1];
			discs[j+1] = t;
		}
	}
}

int main(){
	int T, Ti, N, X, i, j, used, ndisc;
	scanf("%d", &T);
	for(Ti=1; Ti<=T; Ti++){
		used = 0;
		scanf("%d %d", &N, &X);
		ndisc = N;
		for(i=0; i<N; i++) scanf("%d", &(discs[i]));
		sort(N);
		for(i=0; i<N; i++){
			if(discs[i] < 0) continue;
			used++; ndisc--;
			for(j=i+1; j<N; j++){
				if(discs[j] < 0) continue;
				if(discs[i] + discs[j] <= X) break;
			}
			if(j < N){
				ndisc--; discs[j] = -1;
			}
		}
		printf("Case #%d: %d\n", Ti, used);
	}
	return 0;
}
