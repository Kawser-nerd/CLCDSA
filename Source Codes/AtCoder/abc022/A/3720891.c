#include<stdio.h>
long long int W;
int N, S, T, A, ans, i;
int main(){
	scanf("%d%d%d%d", &N, &S, &T, &W);
	if(S<=W && W<=T){
		ans++;
	}
	for(i=1; i<N; i++){
		scanf("%d", &A);
		W+=A;
		if(S<=W && W<=T){
			ans++;
		}
	}
	printf("%d\n", ans);
} ./Main.c: In function ‘main’:
./Main.c:5:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 5 has type ‘long long int *’ [-Wformat=]
  scanf("%d%d%d%d", &N, &S, &T, &W);
        ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &N, &S, &T, &W);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &A);
   ^