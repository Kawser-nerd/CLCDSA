#include<stdio.h>
int N, T, i;
int A[100001];
long long int ans;

int f;
char c;
int nextInt();
int min(int a, int b);

int main(){
	N = nextInt();
	T = nextInt();
	for(i=0; i<N; i++){
		A[i] = nextInt();
	}
	A[N] = A[N-1] + T;
	for(i=0; i<N; i++){
		ans += min(A[i+1]-A[i], T);
	}
	printf("%lld\n", ans);
}

int min(int a, int b){
	return a>b?b:a;
}

int nextInt(){
	f=0;
	c = getchar();
	while((c<'0')||('9'<c)){
		c=getchar();
	}
	while((c>='0')&&(c<='9')){
		f=f*10+(c-'0');
		c=getchar();
	}
	return f;
}