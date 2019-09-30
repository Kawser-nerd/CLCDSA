#include<stdio.h>
int compare_int(const void *a, const void *b);
int N, K, R[100], i;
double ans;

int main(){
	scanf("%d%d", &N, &K);
	for(i=0; i<N; i++){
		scanf("%d", R+i);
	}
    qsort(R, N, sizeof(int), compare_int);
	for(i=N-K; i<N; i++){
		ans = (ans+R[i])/2;
	}
	printf("%lf\n", ans);
}

int compare_int(const void *a, const void *b){
    return *(int*)a - *(int*)b;
} ./Main.c: In function ‘main’:
./Main.c:11:5: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
     qsort(R, N, sizeof(int), compare_int);
     ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &K);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", R+i);
   ^