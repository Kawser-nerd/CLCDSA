#include<stdio.h>
char S[101];
int N, l, r, i;
int main(){
	scanf("%s%d", &S, &N);
	for(i=0; i<N; i++){
		scanf("%d%d", &l, &r);
		l--; r--;
		while(l<r){
			S[l]^=S[r]; S[r]^=S[l]; S[l]^=S[r];
			l++; r--;
		}
	}
	printf("%s\n", S);
} ./Main.c: In function ‘main’:
./Main.c:5:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[101]’ [-Wformat=]
  scanf("%s%d", &S, &N);
        ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s%d", &S, &N);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &l, &r);
   ^