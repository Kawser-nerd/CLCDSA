#define MA 16
int M[MA];
long long best[1<<MA];
long long bitDP(int n){
	int N = 1 << n;
	int S,j;
	best[0]=1;
	for(S=0;S<N;S++)for(j=0;j<n;j++){
		int T=S|(1<<j);
		if(S!=T && !(M[j]&T))best[T]+=best[S];
	}
	return best[N-1];
}

int main(){
	int N,m,x,y;
	for(scanf("%d%d",&N,&m);m--;){
		scanf("%d%d",&x,&y);M[x-1]|=1<<(y-1);
	}
	printf("%lld\n",bitDP(N));
} ./Main.c: In function ‘main’:
./Main.c:17:6: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  for(scanf("%d%d",&N,&m);m--;){
      ^
./Main.c:17:6: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:17:6: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:20:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%lld\n",bitDP(N));
  ^
./Main.c:20:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:20:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’