#include <stdio.h>
#include <stdlib.h>

#define int long long

typedef struct {
	int next;
	int num;
	int max;
	int min;
}person;

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int min(int a, int b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}

signed main(){
	int N, i;
	scanf("%lld", &N);
	person *B = (person *)malloc(sizeof(person) * N);
	for(i = 0; i < N; i++){
		B[i].num = 0;
		B[i].max = 0;
		B[i].min = (int)(1e18);
	}
	for(i = 1; i < N; i++){
		scanf("%lld", &(B[i].next));
		B[i].next--;
		B[B[i].next].num++;
	}
	for(i = N - 1; i > 0; i--){
		if(B[i].num == 0){
			B[B[i].next].max = max(1, B[B[i].next].max);
			B[B[i].next].min = min(1, B[B[i].next].min);
		}
		else{
			B[B[i].next].max = max(1 + B[i].max + B[i].min, B[B[i].next].max);
			B[B[i].next].min = min(1 + B[i].max + B[i].min, B[B[i].next].min);
		}
	}
	printf("%lld\n", 1 + B[0].max + B[0].min);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:41:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &(B[i].next));
   ^