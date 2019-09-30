#include <stdio.h>
#include <stdlib.h>
#define maxsize (int)(1e5 + 2)

int plus(char c){
	if(c == 'A'){
		return 1;
	}
	else{
		return 2;
	}
}

int main(){
	char *S = (char *)malloc(sizeof(char) * maxsize);
	char *T = (char *)malloc(sizeof(char) * maxsize);
	scanf("%s", &S[1]);
	scanf("%s", &T[1]);
	int *sumS = (int *)malloc(sizeof(int) * maxsize);
	int *sumT = (int *)malloc(sizeof(int) * maxsize);
	sumS[0] = 0;
	sumT[0] = 0;
	int i;
	for(i = 1; S[i] != '\0'; i++){
		sumS[i] = sumS[i - 1] + plus(S[i]);
	}
	for(i = 1; T[i] != '\0'; i++){
		sumT[i] = sumT[i - 1] + plus(T[i]);
	}
	int q, a, b, c, d;
	scanf("%d", &q);
	int *ans = (int *)malloc(sizeof(int) * q);
	for(i = 0; i < q; i++){
		scanf("%d%d%d%d", &a, &b, &c, &d);
		if((sumS[b] - sumS[a - 1]) % 3 == (sumT[d] - sumT[c - 1]) % 3){
			ans[i] = 1;
		}
		else{
			ans[i] = 0;
		}
	}
	for(i = 0; i < q; i++){
		if(ans[i] == 1){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", &S[1]);
  ^
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", &T[1]);
  ^
./Main.c:31:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &q);
  ^
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d%d", &a, &b, &c, &d);
   ^