#define f(i)for(int i=1;i++<N;)
N,c[301][301],u,v,l,z=1e9;
main(){
	for(N=atoi(gets(&N));~scanf("%d%d%d%*c",&u,&v,&l);)c[u][v]=c[v][u]=l;
	f(k)f(i)f(j)c[i][j]=fmin(c[i][j]?:z,(c[i][k]?:z)+(c[k][j]?:z));
	f(i)f(j)if(i-j&&c[1][i]*c[j][1])z=fmin(z,c[1][i]+c[i][j]+c[j][1]);
	printf("%d\n",z<1e9?z:-1);
} ./Main.c:2:1: warning: data definition has no type or storage class
 N,c[301][301],u,v,l,z=1e9;
 ^
./Main.c:2:1: warning: type defaults to ‘int’ in declaration of ‘N’ [-Wimplicit-int]
./Main.c:2:3: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 N,c[301][301],u,v,l,z=1e9;
   ^
./Main.c:2:15: warning: type defaults to ‘int’ in declaration of ‘u’ [-Wimplicit-int]
 N,c[301][301],u,v,l,z=1e9;
               ^
./Main.c:2:17: warning: type defaults to ‘int’ in declaration of ‘v’ [-Wimplicit-int]
 N,c[301][301],u,v,l,z=1e9;
                 ^
./Main.c:2:19: warning: type defaults to ‘int’ in declaration of ‘l’ [-Wimplicit-int]
 N,c[301][301],u,v,l,z=1e9;
                   ^
./Main.c:2:21: warning: type defaults to ‘int’ in declaration of ‘z’ [-Wimplicit-int]
 N,c[301][301],u,v,l,z=1e9;
                     ^
./Main.c:3:1: warning: return type defaults to ‘int’ [-Wimplicit-int]
 main(){
 ^
./Main.c: In function ‘main’:
./Main.c:4:8: warning: implicit declaration of function ‘atoi’ [-Wi...