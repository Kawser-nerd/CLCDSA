#include<stdio.h>
int N, K, k, m, i, j;
char S[101], T[101], min, t;
int main(){
	scanf("%d %d\n", &N, &K);
	for(i=0; i<N; ++i){
		S[i]=T[i]=getchar();
	}
	k=K;
	for(i=0; i<N-1; ++i){
		min=127;
		for(j=i+1; j<N; ++j){
			if(T[j]<min){
				if(k >= (T[i]==S[i])+(T[j]==S[j])-(T[i]==S[j])-(T[j]==S[i])){
					m=j; min=T[j];
				}
			}
		}
		if(min==127 || T[i]<=T[m]){
			continue;
		}else{
			k-=(T[i]==S[i])+(T[m]==S[m])-(T[i]==S[m])-(T[m]==S[i]);
			t=T[i]; T[i]=T[m]; T[m]=t;
		}
	}
	printf("%s\n", T);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d\n", &N, &K);
  ^