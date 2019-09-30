min(a,b){return a<b?a:b;}
A[300],a;
c[301][301];
main(){
	int N,M;
	scanf("%d%d%*c",&N,&M);
	for(int i=1;i<=N;++i)for(int j=1;j<=N;++j){
		c[i][j]=1e9;
	}
	for(;M--;){
		int u,v,l;
		scanf("%d%d%d%*c",&u,&v,&l);
		c[u][v]=c[v][u]=l;
		if(u==1){
			A[a++]=v;
		}
	}
	for(int k=2;k<=N;++k)for(int i=2;i<=N;++i)for(int j=2;j<=N;++j){
		c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
	}
	int z=1e9;
	for(int i=0;i<a;++i){int x=A[i];
		for(int j=i+1;j<a;++j){int y=A[j];
			z=min(z,c[1][x]+c[x][y]+c[y][1]);
		}
	}
	printf("%d\n",z<1e9?z:-1);
} ./Main.c:1:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 min(a,b){return a<b?a:b;}
 ^
./Main.c: In function ‘min’:
./Main.c:1:1: warning: type of ‘a’ defaults to ‘int’ [-Wimplicit-int]
./Main.c:1:1: warning: type of ‘b’ defaults to ‘int’ [-Wimplicit-int]
./Main.c: At top level:
./Main.c:2:1: warning: data definition has no type or storage class
 A[300],a;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘A’ [-Wimplicit-int]
./Main.c:2:8: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 A[300],a;
        ^
./Main.c:3:1: warning: data definition has no type or storage class
 c[301][301];
 ^
./Main.c:3:1: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
./Main.c:4:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:6:2: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
  scanf("%d%d%*c",&N,&M);
  ^
./Main.c:6:2: warning: incompatible implic...