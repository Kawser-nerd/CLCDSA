N,A[300],a,c[301][301],i,j,k,u,v,l,z=1e9;
main(){
	for(N=atoi(gets(&N));~scanf("%d%d%d%*c",&u,&v,&l);)
		c[u][v]=c[v][u]=l,u-1||(A[a++]=v);
	for(k=1;k++<N;)for(i=1;i++<N;)for(j=1;j++<N;)
		c[i][j]=fmin(c[i][j]?:z,(c[i][k]?:z)+(c[k][j]?:z));
	for(i=0;i<a;++i)for(j=i;++j<a;)
		z=fmin(z,c[1][A[i]]+c[A[i]][A[j]]+c[A[j]][1]);
	printf("%d\n",z<1e9?z:-1);
} ./Main.c:1:1: warning: data definition has no type or storage class
 N,A[300],a,c[301][301],i,j,k,u,v,l,z=1e9;
 ^
./Main.c:1:1: warning: type defaults to ‘int’ in declaration of ‘N’ [-Wimplicit-int]
./Main.c:1:3: warning: type defaults to ‘int’ in declaration of ‘A’ [-Wimplicit-int]
 N,A[300],a,c[301][301],i,j,k,u,v,l,z=1e9;
   ^
./Main.c:1:10: warning: type defaults to ‘int’ in declaration of ‘a’ [-Wimplicit-int]
 N,A[300],a,c[301][301],i,j,k,u,v,l,z=1e9;
          ^
./Main.c:1:12: warning: type defaults to ‘int’ in declaration of ‘c’ [-Wimplicit-int]
 N,A[300],a,c[301][301],i,j,k,u,v,l,z=1e9;
            ^
./Main.c:1:24: warning: type defaults to ‘int’ in declaration of ‘i’ [-Wimplicit-int]
 N,A[300],a,c[301][301],i,j,k,u,v,l,z=1e9;
                        ^
./Main.c:1:26: warning: type defaults to ‘int’ in declaration of ‘j’ [-Wimplicit-int]
 N,A[300],a,c[301][301],i,j,k,u,v,l,z=1e9;
                          ^
./Main.c:1:28: warning: type defaults to ‘int’ in declaration of ‘k’ [-Wimplicit-int]
 N,A...