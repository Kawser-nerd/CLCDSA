#include <stdio.h>
#include <string.h>

int main(void){
	char    S[200001];
	char    T[200001];
	int i,j;
	int R0[26];
	int R1[26];
	for(i=0;i<26;i++){
		R0[i]=-1;
		R1[i]=-1;
	}
	scanf("%s",S);
	scanf("%s",T);
	int n = strlen(S);
	for(i=0;i<n;i++){
		if(R0[S[i]-'a']<0){
			R0[S[i]-'a'] = T[i]-'a';
		}
		if(R1[T[i]-'a']<0){
			R1[T[i]-'a'] = S[i]-'a';
		}
	}
	for(i=0;i<n;i++){
		if(R0[S[i]-'a']!=T[i]-'a'){
			printf("No");
			return 0;
		}
		if(R1[T[i]-'a']!=S[i]-'a'){
			printf("No");
			return 0;
		}
	}
	printf("Yes");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S);
  ^
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",T);
  ^