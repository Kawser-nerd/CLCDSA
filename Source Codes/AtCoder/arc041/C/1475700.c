#include <stdio.h>
#include <stdlib.h>

#define int long long

typedef struct {
	int x;
	int num;
	char d;
}head;

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int main(){
	int N, M, L, i, j, ans = 0;
	scanf("%lld%lld", &N, &L);
	int *x = (int *)malloc(sizeof(int) * N);
	char *d = (char *)malloc(sizeof(char) * N);
	for(i = 0; i < N; i++){
		scanf("%lld %c", &x[i], &d[i]);
	}
	head *h = (head *)malloc(sizeof(head) * N);
	h[0].x = x[0];
	h[0].num = 1;
	h[0].d = d[0];
	for(i = 1, j = 0; i < N; i++){
		if(h[j].d != d[i]){
			j++;
			h[j].x = x[i];
			h[j].num = 1;
			h[j].d = d[i];
		}
		else if(d[i] == 'R'){
			ans += h[j].num * (x[i] - h[j].x - 1);
			h[j].x = x[i];
			h[j].num++;
		}
		else{
			ans += x[i] - h[j].x - h[j].num;
			h[j].num++;
		}
	}
	M = j + 1;
/*	for(j = 0; j < M; j++){
		printf("j = %d: (x, num, d) = (%d, %d, %c)\n", j, h[j].x, h[j].num, h[j].d);
	}
*///	printf("ans = %d\n", ans);
	j = 0;
	if(h[j].d == 'L'){
		ans += h[j].num * (h[j].x - 1);
		j++;
	}
	if(h[M - 1].d == 'R'){
		ans += h[M - 1].num * (L - h[M - 1].x);
		M--;
	}
	for(; j < M; j += 2){
		ans += max(h[j].num, h[j + 1].num) * (h[j + 1].x - h[j].x - 1);
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:23:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &L);
  ^
./Main.c:27:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld %c", &x[i], &d[i]);
   ^