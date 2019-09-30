#include<stdio.h>
int N, l, r;
char S[101];
int main(){
	scanf("%d%s", &N, &S);
	if(S[N/2]!='b'){printf("-1\n"); return 0;}
	l=0;
	r=N-1;
	while(l<r){
		if(S[l]=='c' && S[r]=='a'){l++; r--;}
		else if(S[l]=='a' && S[r]=='c'){l++; r--;}
		else if(S[l]=='b' && S[r]=='b'){l++; r--;}
		else{printf("-1\n"); return 0;}
	}
	printf("%d\n", N/2);
} ./Main.c: In function ‘main’:
./Main.c:5:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[101]’ [-Wformat=]
  scanf("%d%s", &N, &S);
        ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%s", &N, &S);
  ^