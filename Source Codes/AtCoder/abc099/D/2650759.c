int N,C,D[30][30],c[500][500];
long long q[3][30],x,y=1e18;
main(){
	scanf("%d%d",&N,&C);
	for(int i=0;i<C;++i)for(int j=0;j<C;++j)scanf("%d",&D[i][j]);
	for(int i=0;i<N;++i)for(int j=0;j<N;++j)scanf("%d",&c[i][j]);
	for(int t=0;t<C;++t){
		for(int i=0;i<N;++i)for(int j=0;j<N;++j){
			q[(i+j)%3][t]+=D[c[i][j]-1][t];
		}
	}
	for(int i=0;i<C;++i){
		for(int j=0;j<C;++j)if(i!=j){
			for(int k=0;k<C;++k)if(i!=k&&j!=k){
				x=q[0][i]+q[1][j]+q[2][k];
				if(x<y)y=x;
			}
		}
	}
	printf("%lld",y);
} ./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:4:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%d",&N,&C);
  ^
./Main.c:4:2: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:4:2: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:20:2: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
  printf("%lld",y);
  ^
./Main.c:20:2: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:20:2: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’