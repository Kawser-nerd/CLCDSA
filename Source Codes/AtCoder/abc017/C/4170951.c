#include<stdio.h>

int min(int a, int b){return a>b?b:a;}
int nextInt();
short nextShort();

int N, M, i, j;
int L[100000], R[100000];
short S[100000];
int P[100002];
int sum, ans;

int main(){
	N = nextInt();
	M = nextInt();
	for(i=N-1; i>=0; --i){
		L[i] = nextInt();
		R[i] = nextInt();
		S[i] = nextShort();
		sum += S[i];
		P[L[i]] += S[i];
		P[R[i]+1] -= S[i];
	}
	ans = 2147483647;
	for(j=1; j<=M; j++){
		P[j+1] += P[j];
		ans = min(ans, P[j]);
	}
	printf("%d\n", sum-ans);
}

int nextInt(){
	int f=0; char c=getchar();
	while((c<'0')||('9'<c)){c=getchar();}
	while((c>='0')&&(c<='9')){f=f*10+(c-'0'); c=getchar();}
	return f;
}

short nextShort(){
	short f=0; char c=getchar();
	while((c<'0')||('9'<c)){c=getchar();}
	while((c>='0')&&(c<='9')){f=f*10+(c-'0'); c=getchar();}
	return f;
}