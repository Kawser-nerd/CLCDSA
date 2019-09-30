#include<stdio.h>

int main(){
	int N;
	scanf("%d",&N);
	char S[N+1];
	scanf("%s",S);
	int l=0;
	int pl=0;
	for(int i=0;i<N;i++){
		if(S[i]=='(')l++;
		else if(l==0)pl++;
			else l--;
	}
	for(int i=0;i<pl;i++)printf("(");
	for(int i=0;i<N;i++)printf("%c",S[i]);
	for(int i=0;i<l;i++)printf(")");
	printf("\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",S);
  ^