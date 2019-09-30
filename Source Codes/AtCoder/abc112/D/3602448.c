#include<stdio.h>
#include<math.h>
int main(){
	int N, M, i, l;
	if(scanf("%d%d", &N, &M));
	l=sqrt(M);
	for(i=N; i<=l; i++){
		if(M%i==0){
			printf("%d\n", M/i);
			return 0;
		}
	}
	for(i=(l<M/N?l:M/N);; i--){
		if(M%i==0){
			printf("%d\n", i);
			return 0;
		}
	}
	return 0;
}