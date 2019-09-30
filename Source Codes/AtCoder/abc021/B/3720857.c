#include<stdio.h>
int N, a, b, K, P, i;
char is[101];
int main(){
	scanf("%d%d%d%d", &N, &a, &b, &K);
	is[a]=1;
	is[b]=1;
	for(i=0; i<K; i++){
		scanf("%d", &P);
		if(is[P]){
			printf("NO\n");
			return 0;
		}
		is[P]=1;
	}
	printf("YES\n");
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d", &N, &a, &b, &K);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &P);
   ^