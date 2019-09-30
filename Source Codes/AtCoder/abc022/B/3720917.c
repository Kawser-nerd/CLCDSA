#include<stdio.h>
int N, A, ans, i;
int is[100001];
int main(){
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d", &A);
		if(is[A]){
			ans++;
		}else{
			is[A]=1;
		}
	}
	printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A);
   ^